#include "window.h"

#include <QtGui>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QDebug>

Window::Window(QWidget *parent) :
 QWidget(parent)
{
    bool ok;
    inputDialog = new QInputDialog(this);
    inputDialog->setOptions(QInputDialog::NoButtons);

    *inputText =  inputDialog->getText(NULL ,"QInputDialog::getText() Example",
                                          "User name:", QLineEdit::Normal,
                                          QDir::home().dirName(), &ok);
    slotButtonClicked();

//connect(inputDialog, SIGNAL (accepted()), this, SLOT (fucaoteste()));
//connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
}
void Window::funcaoteste()
{

}
void Window::slotButtonClicked()
{
     QString urlText = *inputText;
        qDebug() << urlText;
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl("http://playready.directtaps.net/smoothstreaming/SSWSS720H264/SuperSpeedway_720.ism/Manifest"));
    QNetworkReply *reply = manager->get(request);
    //connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead(QNetworkReply*)));
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray data = reply->readAll();
    QString DataAsString = QTextCodec::codecForMib(1015)->toUnicode(data);
   // QString dataReply(data);
     qDebug(DataAsString.toLatin1());

}

void Window::slotReadyRead()
{
   // qDebug() <<"Entrou no segundo slot";
   // QByteArray b (reply->readAll());
   // QString s(b);
}
