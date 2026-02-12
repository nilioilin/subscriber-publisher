#ifndef TOPIC_H
#define TOPIC_H

#include <QString>
#include <QList>
#include <QMap>

class Subscribe;

struct Topic
{
    QString name;
    QString message;
    QMap <Subscribe, QString> reaction;
    QList<Subscribe> subscribers;


};

#endif // TOPIC_H
