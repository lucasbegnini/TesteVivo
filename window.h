#ifndef WINDOW_H
#define WINDOW_H


#include <QtNetwork/QNetworkReply>
#include <QtWidgets>
#include <QtGui>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QTextCodec>

class Window : public QWidget
{
    Q_OBJECT
public:
 explicit Window(QWidget *parent = 0);
   QString getUrl();
public slots:
  void slotButtonClicked();

private:
 int m_counter;
 QPushButton *m_button;
 QInputDialog *inputDialog;
 QString *inputText;



};

#endif // WINDOW_H
