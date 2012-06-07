
#include "script_editor.h"
#include "ui_script_editor.h"
#include "binder.h"

class ScriptEditor::PD
{
public:
    Ui_ScriptEditor ui;
    Binder * binder;
};

ScriptEditor::ScriptEditor( Binder * binder, QWidget * parent )
: QMainWindow( parent )
{
    pd = new PD();
    pd->binder = binder;
    pd->ui.setupUi( this );

    connect( pd->ui.run,   SIGNAL(triggered()), this, SLOT(run()) );
    connect( pd->ui.stop,  SIGNAL(triggered()), this, SLOT(stop()) );
    connect( pd->ui.debug, SIGNAL(triggered()), this, SLOT(debug()) );
    connect( pd->ui.step,  SIGNAL(triggered()), this, SLOT(step()) );
    connect( pd->ui.open, SIGNAL(triggered()), this, SLOT(open()) );
    connect( pd->ui.save, SIGNAL(triggered()), this, SLOT(save()) );
}

ScriptEditor::~ScriptEditor()
{
    delete pd;
}

void ScriptEditor::run()
{
    QString stri = pd->ui.code->toPlainText();
    pd->binder->execString( stri.toStdString() );
}

void ScriptEditor::stop()
{
    pd->binder->stopExec();
}

void ScriptEditor::debug()
{
    if ( pd->ui.debug->isChecked() )
        pd->binder->breakExec();
    else
        pd->binder->contExec();
}

void ScriptEditor::step()
{
    pd->binder->stepInto();
}

void ScriptEditor::open()
{
    QString fileName = QFileDialog::getOpenFileName( this,
       tr("Open Java script"), "./", tr("Js files (*.js)"));
    if ( !fileName.isNull() )
    {
        QFile scriptFile( fileName );
        scriptFile.open(QIODevice::ReadOnly);
        QTextStream stream( &scriptFile );
        QString contents = stream.readAll();
        scriptFile.close();

        pd->ui.code->setPlainText( contents );
    }
}

void ScriptEditor::save()
{
    QString fileName = QFileDialog::getSaveFileName( this,
       tr("Save Java script"), "./", tr("Js files (*.js)"));
    if ( !fileName.isNull() )
    {
        QString stri = pd->ui.code->toPlainText();
        QFile scriptFile( fileName );
        scriptFile.open(QIODevice::WriteOnly);
        QTextStream stream( &scriptFile );
        stream << stri;
        scriptFile.close();
    }
}



