#include "publish.h"

Publish::Publish(MessageBroker *broker)
    :broker(broker) {

}

void Publish::add_message(QString &topic_name, QString &message)
{
    broker -> publish_message(topic_name, message);
}
