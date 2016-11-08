#ifndef SMOOTHSTREAMING_H
#define SMOOTHSTREAMING_H

#include <QWidget>
#include<QDomNodeList>
#include <QDebug>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>
#include <QtWidgets>
#include <QFile>
#include <QTime>

class SmoothStreaming : public QWidget
{
    Q_OBJECT
public:
    explicit SmoothStreaming(QWidget* parent=0);
    SetTudo(QDomNodeList listchunks, QDomNodeList list, QString Type, int qtdQualityLevels, int chunks, QString _URL, QString tempurl);

public slots:
  void Download(QDomNodeList listchunks, QDomNodeList _list, int chunks);
  void requestReceived(QNetworkReply*reply);

private:
    QString  Finalurl;
    QTime TimeAlta, TimeBaixa;
};

#endif // SMOOTHSTREAMING_H
