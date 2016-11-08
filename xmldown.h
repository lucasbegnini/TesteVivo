#ifndef XMLDOWN_H
#define XMLDOWN_H
#include <QByteArray>
#include <QTextCodec>
#include <QString>

#include <QList>
#include <QDomDocument>
#include <QDebug>
#include <QDomNode>

class Xmldown
{
public:
    Xmldown();
    Xmldown(QByteArray datain, QString *tempurl);

private:
    //QList lista;
    QDomDocument xml;
    int qtdQualityLevels, chunks;
    QString Type, _URL, _tempurl;

};

#endif // XMLDOWN_H
