#include "xmldown.h"
#include "smoothstreaming.h"

Xmldown::Xmldown()
{

}

Xmldown::Xmldown(QByteArray datain, QString* tempurl)
{
    xml.setContent(datain);
    _tempurl = *tempurl;
   // QDomNodeList list=xml.elementsByTagName(QString("QualityLevel"));
   // QString DataAsString = QTextCodec::codecForMib(1015)->toUnicode(datain);
    // qDebug(DataAsString.toLatin1());

     //qDebug()<<list.at(0).toElement().attribute("Index");
    //Take QualityLevels
     qtdQualityLevels = xml.elementsByTagName(QString("StreamIndex")).at(0).toElement().attribute("QualityLevels").toInt();
     //Take type
     Type = xml.elementsByTagName(QString("StreamIndex")).at(0).toElement().attribute("Type");
     //Take chunks
      chunks = xml.elementsByTagName(QString("StreamIndex")).at(0).toElement().attribute("Chunks").toInt();
      //Take URL
      _URL = xml.elementsByTagName(QString("StreamIndex")).at(0).toElement().attribute("Url");
    //Gera uma lista so com os videos onde cada .at(i) é um QualityLevel

    QDomNodeList list=xml.elementsByTagName(QString("StreamIndex")).at(0).childNodes();
    QDomNodeList listchunks =xml.elementsByTagName(QString("c"));
    // qDebug()<< qtdQualityLevels;
    // qDebug()<< Type;
    // qDebug()<< chunks;
    // qDebug()<< _tempurl;

    SmoothStreaming download;
    download.SetTudo(listchunks, list , Type, qtdQualityLevels,chunks,_URL, _tempurl);
       //if(list.at(0).toElement().attribute("Index"))
      //Lista todas Quality Level de vídeo.
      //QDomNodeList QualityLevelVideoList = list.at(0).elementsByTagName(QString("QualityLevel"));
       //qDebug()<<list.at(0).toElement().attribute("Bitrate");
}
