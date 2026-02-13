#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include <QObject>
#include <QString>
#include "messagebroker.h"


class Subscribe : public QObject
{
    Q_OBJECT
public:
    explicit Subscribe(MessageBroker *broker= nullptr);

    QString get_message(const QString &topic_name);
    void subscribe(const QString &topic_name);
    void add_reaction(const QString &topic_name, QString &reaction);

private:
        MessageBroker *broker;

public slots:
        void Message(const QString &topic_name, QString &message);
};

#endif // SUBSCRIBE_H
