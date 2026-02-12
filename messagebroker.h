#ifndef MESSAGEBROKER_H
#define MESSAGEBROKER_H

#include <QObject>
#include <QHash>
#include "Topic.h"


class MessageBroker : public QObject
{
    Q_OBJECT
public:
    explicit MessageBroker(QObject *parent = nullptr);

    void add_topic(QString &topic_name);

    void publish_message(QString &topic_name, QString &message);

    QString get_message(QString &topic_name);
    void subscribe(QString &topic_name, Subscribe *subscriber);
    void add_reaction(QString &topic_name, QString &reaction, Subscribe *subscriber);

private:
    QHash<QString, Topic> topics;
    Topic* search_topic(QString topic_name);

};

#endif // MESSAGEBROKER_H
