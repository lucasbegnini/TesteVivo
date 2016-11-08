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
    Xmldown(QByteArray datain);

private:
    //QList lista;
    QDomDocument xml;
    int qtdQualityLevels, chunks;
    QString Type;

};

#endif // XMLDOWN_H
