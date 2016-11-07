#include "window.h"

#include <QtGui>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>

Window::Window(QWidget *parent) :
 QWidget(parent)
{
    bool ok;
    inputDialog = new QInputDialog(this);
    inputDialog->setOptions(QInputDialog::NoButtons);

    *inputText =  inputDialog->getText(NULL ,"QInputDialog::getText() Example",
                                          "User name:", QLineEdit::Normal,
                                          QDir::home().dirName(), &ok);


connect(inputDialog, SIGNAL (accepted()), this, SLOT (fucaoteste()));
//connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
}
void Window::fucaoteste()
{
     std::cout<<"Entrou no primeiro slot"<<std::endl;
}
void Window::slotButtonClicked()
{
        std::cout<<"Entrou no primeiro slot"<<std::endl;
  //  QNetworkAccessManager* manager = new QNetworkAccessManager(this);
  //  QNetworkRequest request;
   // request.setUrl(QUrl("http://playready.directtaps.net/smoothstreaming/SSWSS720H264/SuperSpeedway_720.ism/Manifest"));
   // QNetworkReply *reply = manager->get(request);
   // connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead(QNetworkReply*)));
}

void Window::slotReadyRead(QNetworkReply* reply)
{
    std::cout<<"Entrou no segundo slot"<<std::endl;
    QByteArray b (reply->readAll());
    QString s(b);
}
