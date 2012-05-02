
#include "IceE/IceE.h"
#include "thread_ice.h"

ThreadIce::ThreadIce( const std::string & listen )
: IceUtil::Thread(), 
  m_listen( listen )
{
}

ThreadIce::~ThreadIce()
{
}

void ThreadIce::shutdown()
{
    if ( m_comm )
    {
        m_semaphore.lock();
        m_comm->shutdown();
        m_semaphore.wait();
        m_semaphore.unlock();
    }
}

std::string ThreadIce::lastError()
{
    m_mutex.lock();
    if ( m_errors.size() )
    {
        std::string res = m_errors.back();
        m_errors.pop();
        m_mutex.unlock();
        return res;
    }
    m_mutex.unlock();
    return std::string();
}

std::string ThreadIce::status() const
{
    m_mutex.lock();
    std::string res = m_status;
    m_mutex.unlock();
    return res;
}

bool ThreadIce::listen()
{
    m_semaphore.lock();
    start();
    m_semaphore.wait();
    m_semaphore.unlock();
    bool res = ( status() == "connected" );
    return res;
}

void ThreadIce::run()
{
    try
    {
        Ice::PropertiesPtr   props = Ice::createProperties();
        props->setProperty( "client_adapter.Endpoints", "tcp" );
        Ice::InitializationData initData;
        initData.properties = props;
        m_comm = Ice::initialize( initData );

        m_adapter = m_comm->createObjectAdapterWithEndpoints( "adapter", m_listen );
        m_factory = new FactoryIce( this );
        m_adapter->add( m_factory, m_comm->stringToIdentity( "factory" ) );
        m_adapter->activate();

        m_mutex.lock();
        m_status = "connected";
        m_mutex.unlock();

        m_semaphore.lock();
        m_semaphore.notifyAll();
        m_semaphore.unlock();
        m_comm->waitForShutdown();
        m_comm->destroy();
    }
    catch(const Ice::Exception& ex)
    {
        m_errors.push( ex.ice_name() );
        if( m_comm )
        {
            try
            {
                m_comm->destroy();
            }
            catch(const Ice::Exception& ex)
            {
                m_errors.push( ex.ice_name() );
            }
        }
    }
    m_mutex.lock();
    m_status = "disconnected";
    m_mutex.unlock();

    m_semaphore.lock();
    m_semaphore.notifyAll();
    m_semaphore.unlock();
}

Ice::ObjectAdapterPtr ThreadIce::adapter()
{
    return m_adapter;
}



