
#include "mcu_ctrl.h"
#include <sstream>
#include <boost/regex.hpp>

McuCtrl::McuCtrl()
: UsbIo()
{

}

McuCtrl::~McuCtrl()
{

}

bool McuCtrl::inputs( unsigned long * data, int len )
{
    std::string stri = "st\r\n";
    int cntWr = write( stri );
    int cntRd = read( stri );
    // Here it should be output parser.
    std::string::const_iterator start = stri.begin();
    std::string::const_iterator end   = stri.end();
    boost::regex patt( "\\{([\\w\\s]{1,})\\}" );
    boost::smatch match;
    if ( boost::regex_search( start, end, match, patt ) )
    {
        //std::cout << it->str() << "\n";
        std::string ss = match[1];
        std::istringstream in( ss );
        for ( int i=0; i<len; i++ )
            in >> data[i];
        return true;
    }
    return false;
}

bool McuCtrl::setOutputs( unsigned long * data, int len )
{
    std::ostringstream out;
    out << "out ";
    for ( int i=0; i<len; i++ )
    {
        out << data[i];
        if ( i < (len-1) )
            out << " ";
    }
    out << "\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::i2cSetAddr( int addr )
{
    std::ostringstream out;
    out << "addr ";
    out << addr;
    out << "\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::i2cSetBuf( int start, unsigned char * data, int cnt )
{
    std::ostringstream out;
    out << "set_buf ";
    out << start;
    for ( int i=0; i<cnt; i++ )
    {
        out << " ";
        out << static_cast<int>( data[i] );
    }
    out << "\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::i2cIo( int txCnt, int rxCnt )
{
    std::ostringstream out;
    out << "io ";
    out << txCnt;
    out << " ";
    out << rxCnt;
    out << "\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::i2cStatus( int & status )
{
    std::ostringstream out;
    out << "status\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    std::string::const_iterator start = stri.begin();
    std::string::const_iterator end   = stri.end();
    boost::regex patt( "\\{([\\w\\s]{1,})\\}" );
    boost::smatch match;
    if ( boost::regex_search( start, end, match, patt ) )
    {
        std::string ss = match[1];
        std::istringstream in( ss );
        in >> status;
        return true;
    }
    return false;
}

bool McuCtrl::i2cBuffer( int cnt, unsigned char * data )
{
    std::ostringstream out;
    out << "buffer ";
    out << cnt;
    out << "\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    std::string::const_iterator start = stri.begin();
    std::string::const_iterator end   = stri.end();
    boost::regex patt( "\\{([\\w\\s]{1,})\\}" );
    boost::smatch match;
    if ( boost::regex_search( start, end, match, patt ) )
    {
        std::string ss = match[1];
        std::istringstream in( ss );
        for ( int i=0; i<cnt; i++ )
            in >> data[i];
        return true;
    }
    return false;
}









