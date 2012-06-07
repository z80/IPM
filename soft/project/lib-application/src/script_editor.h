
#ifndef __SCRIPT_EDITOR_H_
#define __SCRIPT_EDITOR_H_

#include <QtGui>
class JsBinder;

class ScriptEditor: public QMainWindow
{
    Q_OBJECT
public:
    ScriptEditor( JsBinder * binder, QWidget * parent = 0 );
    ~ScriptEditor();
    void openFile( const QString & stri );
    void saveFile( const QString & stri );
private slots:
    void run();
    void stop();
    void open();
    void save();
private:
    class PD;
    PD * pd;
};

#endif



