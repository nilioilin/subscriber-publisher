#ifndef TOPIC_H
#define TOPIC_H

#include <QString>
#include <QSet>

class Subscribe;

struct Topic
{
    QString name;
    QString message;
    QString reaction;
    QSet<Subscribe*> subscribers;


};

#endif // TOPIC_H
