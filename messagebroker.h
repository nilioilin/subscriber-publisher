#ifndef MESSAGEBROKER_H
#define MESSAGEBROKER_H

#include <QObject>
#include <QHash>

#include "Topic.h"

class MessageBroker : public QObject
{
    Q_OBJECT
public:
    MessageBroker();
    explicit MessageBroker(QObject* parent = nullptr);

    void add_topic(QString topic_name);

    Topic search_topic(QString topic_name);

    void add_message(QString topic_name);

    void add_sbscriber(QString topic_name);

    void add_reaction(QString topic_name, QString reaction);

private:
    QHash<QString, Topic> topics;

};

#endif // MESSAGEBROKER_H
