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

    Finalurl.replace("{bitrate}",Bitrate);
    qDebug() << Finalurl;
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QByteArray data;
    //Acumulador de tempo
    int tempAc = 0;
    //Loop para baixar todos os arquivos
     TimeAlta.start();
    for(int i = 0; i <= 10; i++)
    {
        if(i==0)
        {
         Finalurl.replace("{start time}","0");
        }else{
           tempAc = tempAc + listchunks.at(i-1).toElement().attribute("d").toInt();
           QString s = QString::number(tempAc);
         Finalurl.replace("{start time}",s);
        }
        request.setUrl(QUrl(Finalurl));
        QNetworkReply *reply = manager->get(request);
        QEventLoop loop;
        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        data = data + reply->readAll();
         qDebug() << i;
    }
    float nMiliAlta = TimeAlta.elapsed();
    //TimeAlta.
       QFile file("C:/Users/Public/AltaQualidade.mp4");
       file.open(QIODevice::WriteOnly);
       file.write(data);
       file.close();
         qDebug() << "Done Alta Qualidade em :" << nMiliAlta/1000 << " em segundos ";

         Bitrate = _list.at(8).toElement().attribute("Bitrate");

         Finalurl.replace("{bitrate}",Bitrate);
          data = 0;
         //Acumulador de tempo
         tempAc = 0;
         //Loop para baixar todos os arquivos
        TimeBaixa.start();
         for(int i = 0; i <= 10; i++)
         {
             if(i==0)
             {
              Finalurl.replace("{start time}","0");
             }else{
                tempAc = tempAc + listchunks.at(i-1).toElement().attribute("d").toInt();
                QString s = QString::number(tempAc);
              Finalurl.replace("{start time}",s);
             }
             request.setUrl(QUrl(Finalurl));
             QNetworkReply *reply = manager->get(request);
             QEventLoop loop;
             connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
             loop.exec();
             data = data + reply->readAll();
              qDebug() << i;
         }
         float nMiliBaixa = TimeBaixa.elapsed();
            QFile file2("C:/Users/Public/BaixaQualidade.mp4");
            file2.open(QIODevice::WriteOnly);
            file2.write(data);
            file2.close();
              qDebug() << "Done Baixa Qualidade :" << nMiliBaixa/1000 << " em segundos ";
            //quit();
            //return false;
              exit(EXIT_FAILURE);
}

void SmoothStreaming::requestReceived(QNetworkReply * reply)
{

    reply->deleteLater();
      qDebug() << "Finalurl";
     if(reply->error() == QNetworkReply::NoError)
     {

     }
}
