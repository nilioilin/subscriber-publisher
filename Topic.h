#ifndef TOPIC_H
#define TOPIC_H

#include <QString>
#include <QQueue>
#include <QMap>

class Subscribe;

struct Topic
{
    QString name;
    QQueue <QString> messages;
    QMap <Subscribe, QString> reaction;
    QList<Subscribe> subscribers;
};

#endif // TOPIC_H
