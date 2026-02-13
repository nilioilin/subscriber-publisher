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

    Topic* search_topic(const QString topic_name);

    void add_topic(const QString &topic_name);

    void publish_message(const QString &topic_name, QString &message);

    QString get_message(const QString &topic_name);
    void subscribe(const QString &topic_name, Subscribe *subscriber);
    void add_reaction(const QString &topic_name, QString &reaction, Subscribe *subscriber);

private:
    QHash<QString, Topic> topics;

signals:
    void Message(const QString &topic_name, QString &message);

};

#endif // MESSAGEBROKER_H
