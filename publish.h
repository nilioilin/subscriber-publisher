#ifndef PUBLISH_H
#define PUBLISH_H

#include <QObject>
#include <QWidget>
#include "messagebroker.h"

class Publish : public QObject
{
    Q_OBJECT

public:
    explicit Publish(MessageBroker *broker = nullptr);

    void add_message(const QString &topic_name, QString &message);

private:
    MessageBroker *broker;
};

#endif // PUBLISH_H
