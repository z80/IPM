
#include <QtGui>
#include <QtNetwork>
#include <QtWebKit>
#include "help_wnd.h"

//! [1]

HelpWnd::HelpWnd(const QString & url)
{
    progress = 0;

    //QFile file;
    //file.setFileName(":/jquery.min.js");
    //file.open(QIODevice::ReadOnly);
    //jQuery = file.readAll();
    //file.close();
//! [1]

    QNetworkProxyFactory::setUseSystemConfiguration(true);

//! [2]
    view = new QWebView(this);
    //view->load(url);

    QFile file;
    file.setFileName( url );
    bool res = file.open( QIODevice::ReadOnly );
    Q_ASSERT( res );
    QString stri = QString::fromUtf8( file.readAll().constData() );
    file.close();
    view->setHtml( stri, QUrl( ":/help/" ) );

    connect(view, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
    connect(view, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));
    connect(view, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(view, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));
    connect(view, SIGNAL(linkClicked(const QUrl & )), this, SLOT(slotLinkClicked(const QUrl &)) );

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

    QToolBar *toolBar = addToolBar(tr("Navigation"));
    toolBar->addAction(view->pageAction(QWebPage::Back));
    toolBar->addAction(view->pageAction(QWebPage::Forward));
    toolBar->addAction(view->pageAction(QWebPage::Reload));
    toolBar->addAction(view->pageAction(QWebPage::Stop));
    toolBar->addWidget(locationEdit);
//! [2]

    //QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
    //QAction* viewSourceAction = new QAction("Page Source", this);
    //connect(viewSourceAction, SIGNAL(triggered()), SLOT(viewSource()));
    //viewMenu->addAction(viewSourceAction);

//! [3]
    QMenu *effectMenu = menuBar()->addMenu(tr("&Effect"));
    effectMenu->addAction("Highlight all links", this, SLOT(highlightAllLinks()));

    rotateAction = new QAction(this);
    rotateAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    rotateAction->setCheckable(true);
    rotateAction->setText(tr("Turn images upside down"));
    connect(rotateAction, SIGNAL(toggled(bool)), this, SLOT(rotateImages(bool)));
    effectMenu->addAction(rotateAction);

    //QMenu *toolsMenu = menuBar()->addMenu(tr("&Tools"));
    //toolsMenu->addAction(tr("Remove GIF images"), this, SLOT(removeGifImages()));
    //toolsMenu->addAction(tr("Remove all inline frames"), this, SLOT(removeInlineFrames()));
    //toolsMenu->addAction(tr("Remove all object elements"), this, SLOT(removeObjectElements()));
    //toolsMenu->addAction(tr("Remove all embedded elements"), this, SLOT(removeEmbeddedElements()));

    setCentralWidget(view);
    setUnifiedTitleAndToolBarOnMac(true);
}
//! [3]

void HelpWnd::viewSource()
{
    QNetworkAccessManager* accessManager = view->page()->networkAccessManager();
    QNetworkRequest request(view->url());
    QNetworkReply* reply = accessManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(slotSourceDownloaded()));
}

void HelpWnd::slotLinkClicked(const QUrl & url )
{
    QString stri = url.toString();
    stri = QString( ":/help/%1" ).arg( stri );
    QFile file;
    file.setFileName( stri );
    bool res = file.open( QIODevice::ReadOnly );
    Q_ASSERT( res );
    stri = QString::fromUtf8( file.readAll().constData() );
    file.close();
    view->setHtml( stri, QUrl( ":/help/" ) );
}

void HelpWnd::slotSourceDownloaded()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(const_cast<QObject*>(sender()));
    QTextEdit* textEdit = new QTextEdit(NULL);
    textEdit->setAttribute(Qt::WA_DeleteOnClose);
    textEdit->show();
    textEdit->setPlainText(reply->readAll());
    reply->deleteLater();
}

//! [4]
void HelpWnd::adjustLocation()
{
    locationEdit->setText(view->url().toString());
    view->page()->setLinkDelegationPolicy( QWebPage::DelegateAllLinks );
}

void HelpWnd::changeLocation()
{
    QUrl url = QUrl(locationEdit->text());
    view->load(url);
    view->setFocus();
}
//! [4]

//! [5]
void HelpWnd::adjustTitle()
{
    if (progress <= 0 || progress >= 100)
        setWindowTitle(view->title());
    else
        setWindowTitle(QString("%1 (%2%)").arg(view->title()).arg(progress));
}

void HelpWnd::setProgress(int p)
{
    progress = p;
    adjustTitle();
}
//! [5]

//! [6]
void HelpWnd::finishLoading(bool)
{
    progress = 100;
    adjustTitle();
    //view->page()->mainFrame()->evaluateJavaScript(jQuery);

    //rotateImages(rotateAction->isChecked());
}
//! [6]

//! [7]
void HelpWnd::highlightAllLinks()
{
    QString code = "$('a').each( function () { $(this).css('background-color', 'yellow') } )";
    view->page()->mainFrame()->evaluateJavaScript(code);
}
//! [7]

//! [8]
void HelpWnd::rotateImages(bool invert)
{
    QString code;
    if (invert)
        code = "$('img').each( function () { $(this).css('-webkit-transition', '-webkit-transform 2s'); $(this).css('-webkit-transform', 'rotate(180deg)') } )";
    else
        code = "$('img').each( function () { $(this).css('-webkit-transition', '-webkit-transform 2s'); $(this).css('-webkit-transform', 'rotate(0deg)') } )";
    view->page()->mainFrame()->evaluateJavaScript(code);
}
//! [8]

//! [9]
void HelpWnd::removeGifImages()
{
    QString code = "$('[src*=gif]').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void HelpWnd::removeInlineFrames()
{
    QString code = "$('iframe').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void HelpWnd::removeObjectElements()
{
    QString code = "$('object').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void HelpWnd::removeEmbeddedElements()
{
    QString code = "$('embed').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}
//! [9]

