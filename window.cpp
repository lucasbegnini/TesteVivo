#include "window.h"
#include "xmldown.h"

Window::Window(QWidget *parent) :
 QWidget(parent)
{
    bool ok;

    inputDialog = new QInputDialog(this);
    inputDialog->setOptions(QInputDialog::NoButtons);
    inputDialog->resize(800, 180);
    *inputText =  inputDialog->getText(NULL ,"Insert the Base Adress",
                                          "Adress:", QLineEdit::Normal,
                                          "http://playready.directtaps.net/smoothstreaming/SSWSS720H264/SuperSpeedway_720.ism", &ok);
    slotButtonClicked();

}

void Window::slotButtonClicked()
{
     QString urlText = *inputText;
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(urlText.trimmed() + "/Manifest"));
    QNetworkReply *reply = manager->get(request);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray data = reply->readAll();
    reply->deleteLater();
    Xmldown xml =  Xmldown(data, inputText);
}


