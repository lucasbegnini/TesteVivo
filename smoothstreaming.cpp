#include "smoothstreaming.h"
#include <QtNetwork/QNetworkReply>

SmoothStreaming::SmoothStreaming(QWidget* parent): QWidget(parent)
{

}
SmoothStreaming::SetTudo(QDomNodeList listchunks, QDomNodeList list, QString Type, int qtdQualityLevels, int chunks, QString _URL, QString tempurl)
{
    Finalurl = tempurl+ "/" + _URL;
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
//-------------------------Criação da janela de exibição --------------------------//

    QWidget window;
    window.setFixedSize(400, 180);
    QProgressBar *progressBar = new QProgressBar(&window);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 10, 380, 30);
    m_button = new QPushButton("Close", &window);
    m_button->setGeometry(150, 140, 80, 30);
    m_button->setEnabled(false);
    QLabel *_downloadrate = new QLabel("Dowload Rate :",&window);
    _downloadrate->setGeometry(10,50,200,30);
    QLabel *_downloadtime = new QLabel("Dowload Time :",&window);
    _downloadtime->setGeometry(10,70,200,30);
    QLabel *_downloadtimeAlta = new QLabel("Dowload Time in High :",&window);
    _downloadtimeAlta->setGeometry(10,90,200,30);
    QLabel *_downloadtimeBaixa = new QLabel("Dowload Time in Low :",&window);
    _downloadtimeBaixa->setGeometry(10,110,200,30);
    window.show();

    //Acumulador da barrar de progresso
    int progessBarAc = 0;
 //-------------------------Download de todas os arquivos na versão alta--------------------------//
    //Acumulador de tempo
    int tempAc = 0;
    //Loop para baixar todos os arquivos
     TimerGeneral.start();
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
        TimeEspecific.start();
        QNetworkReply *reply = manager->get(request);
        TimeEspecific.start();
        QEventLoop loop;
        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
         _downloadtime->setText("Dowload Time :" +  QString::number(TimeEspecific.elapsed()) + " ms");
         _downloadrate->setText("Dowload Rate :" + QString::number(((reply->readAll().size())/(TimerGeneral.elapsed()))) + " Kb/s");
        data = data + reply->readAll();
        qDebug() << i;
        progessBarAc += ((20*i)/100)*10;
        progressBar->setValue(progessBarAc);
    }
    float nMiliAlta = TimerGeneral.elapsed();
    //TimeAlta.
       QFile file("C:/Users/Public/AltaQualidade.mp4");
       file.open(QIODevice::WriteOnly);
       file.write(data);
       file.close();
       qDebug() << "Done Alta Qualidade em :" << nMiliAlta/1000 << " em segundos ";
         _downloadtimeAlta->setText("Download in High : " + QString::number(nMiliAlta/1000) + "s");

//-------------------------Download de todas os arquivos na versão baixa--------------------------//
         Bitrate = _list.at(8).toElement().attribute("Bitrate");

         Finalurl.replace("{bitrate}",Bitrate);
          data = 0;
         //Acumulador de tempo
         tempAc = 0;
         //Loop para baixar todos os arquivos
        TimerGeneral.start();
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
             TimeEspecific.start();
             QNetworkReply *reply = manager->get(request);
             QEventLoop loop;
             connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
             loop.exec();
             _downloadtime->setText("Dowload Time :" +  QString::number(TimeEspecific.elapsed()) + " ms");
             _downloadrate->setText("Dowload Rate :" + QString::number(((reply->readAll().size())/(TimerGeneral.elapsed()))) + " Kb/s");
             data = data + reply->readAll();
              qDebug() << i;
              progessBarAc += ((20*i)/100)*10;
              progressBar->setValue(progessBarAc);
         }
         float nMiliBaixa = TimerGeneral.elapsed();
            QFile file2("C:/Users/Public/BaixaQualidade.mp4");
            file2.open(QIODevice::WriteOnly);
            file2.write(data);
            file2.close();
            qDebug() << "Done Baixa Qualidade :" << nMiliBaixa/1000 << " em segundos ";
            _downloadtimeBaixa->setText("Download in Low : " + QString::number(nMiliBaixa/1000) + "s");
            m_button->setEnabled(true);
            QEventLoop loop;
            connect(m_button, SIGNAL(clicked()), & loop, SLOT(quit()));
            loop.exec();

            exit(EXIT_SUCCESS);
//
}


