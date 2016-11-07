#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
#include <QtNetwork/QNetworkReply>

class Window : public QWidget
{
    Q_OBJECT
public:
 explicit Window(QWidget *parent = 0);
public slots:
  void slotButtonClicked();
  void funcaoteste();
  void slotReadyRead();

private:
 int m_counter;
 QPushButton *m_button;
 QInputDialog *inputDialog;
 QString *inputText;



};

#endif // WINDOW_H
