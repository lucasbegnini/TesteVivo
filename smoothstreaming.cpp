#include "smoothstreaming.h"
#include <QtNetwork/QNetworkReply>

SmoothStreaming::SmoothStreaming(QWidget* parent): QWidget(parent)
{

}
SmoothStreaming::SetTudo(QDomNodeList listchunks, QDomNodeList list, QString Type, int qtdQualityLevels, int chunks, QString _URL, QString tempurl)
{
    Finalurl = tempurl+ "/" + _URL;
    QDomNodeList _list = list;
   // qDebug()<< Type;
   // qDebug()<< qtdQualityLevels;
   // qDebug()<< chunks;
   // qDebug() << list.at(0).toElement().attribute("Bitrate");
   // QString Bitrate = list.at(0).toElement().attribute("Bitrate");
    //Finalurl.replace("bitrate",Bitrate);
    //qDebug()<< Finalurl;
    Download(listchunks, list, chunks);


}

void SmoothStreaming::Download(QDomNodeList listchunks, QDomNodeList _list, int chunks)
{
    qDebug() << listchunks.at(0).toElement().attribute("d");
    qDebug() << chunks;


    QString Bitrate = _list.at(0).toElement().attribute("Bitrate");
    Finalurl.replace("{start time}","0");
    Finalurl.replace("{bitrate}",Bitrate);
    qDebug() << Finalurl;
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(Finalurl));
    QNetworkReply *reply = manager->get(request);
    //connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead(QNetworkReply*)));
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QByteArray data = reply->readAll();

 /*   QFile file("C:/Users/Public/some_name.mp4");
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();
     QApplication::quit();
*/
    //for(int i = 0; i < 10 ; i++)
    //{}
}

void SmoothStreaming::requestReceived(QNetworkReply * reply)
{

    reply->deleteLater();
      qDebug() << "Finalurl";
     if(reply->error() == QNetworkReply::NoError)
     {

     }
}
