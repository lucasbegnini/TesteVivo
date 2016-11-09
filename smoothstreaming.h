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
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QPushButton>

class SmoothStreaming : public QWidget
{
    Q_OBJECT
public:
    explicit SmoothStreaming(QWidget* parent=0);
    SetTudo(QDomNodeList listchunks, QDomNodeList list, QString Type, int qtdQualityLevels, int chunks, QString _URL, QString tempurl);

public slots:
  void Download(QDomNodeList listchunks, QDomNodeList _list, int chunks);

private:
    QString  Finalurl;
    QTime TimerGeneral, TimeEspecific;
    QPushButton *m_button;
};

#endif // SMOOTHSTREAMING_H
