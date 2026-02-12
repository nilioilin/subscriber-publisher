#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include <QObject>
#include <QString>
#include "messagebroker.h"


class Subscribe : public QObject
{
    Q_OBJECT
public:
    explicit Subscribe(
        QObject *parent = nullptr, MessageBroker *broker= nullptr);

    QString get_message(QString &topic_name);
    void subscribe(QString &topic_name);
    void add_reaction(QString &topic_name, QString &reaction);

private:
        MessageBroker *broker;
};

#endif // SUBSCRIBE_H
