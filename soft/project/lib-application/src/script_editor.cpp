
#include "script_editor.h"
#include "ui_script_editor.h"
#include "js_binder.h"

class ScriptEditor::PD
{
public:
    Ui_ScriptEditor ui;
    JsBinder * binder;
};

ScriptEditor::ScriptEditor( JsBinder * binder, QWidget * parent )
: QMainWindow( parent )
{
    pd = new PD();
    pd->binder = binder;
    pd->ui.setupUi( this );

    connect( pd->ui.run,  SIGNAL(triggered()), this, SLOT(run()) );
    connect( pd->ui.stop, SIGNAL(triggered()), this, SLOT(stop()) );
    connect( pd->ui.open, SIGNAL(triggered()), this, SLOT(open()) );
    connect( pd->ui.save, SIGNAL(triggered()), this, SLOT(save()) );
}

ScriptEditor::~ScriptEditor()
{
    delete pd;
}

void ScriptEditor::openFile( const QString & stri )
{
    QFile scriptFile( stri );
    scriptFile.open(QIODevice::ReadOnly);
    QTextStream stream( &scriptFile );
    QString contents = stream.readAll();
    scriptFile.close();

    pd->ui.code->setPlainText( contents );
}

void ScriptEditor::saveFile( const QString & stri )
{
    QString content = pd->ui.code->toPlainText();
    QFile scriptFile( stri );
    scriptFile.open(QIODevice::WriteOnly);
    QTextStream stream( &scriptFile );
    stream << content;
    scriptFile.close();
}

void ScriptEditor::run()
{
    QString stri = pd->ui.code->toPlainText();
    pd->binder->runText( stri );
}

void ScriptEditor::stop()
{
    pd->binder->stop();
}

void ScriptEditor::open()
{
    QString fileName = QFileDialog::getOpenFileName( this,
       tr("Open Java script"), "./", tr("Js files (*.js)"));
    if ( !fileName.isNull() )
        openFile( fileName );
}

void ScriptEditor::save()
{
    QString fileName = QFileDialog::getSaveFileName( this,
       tr("Save Java script"), "./", tr("Js files (*.js)"));
    if ( !fileName.isNull() )
        saveFile( fileName );
}



