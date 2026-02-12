#include "subscribe.h"
#include <QString>

Subscribe::Subscribe(MessageBroker *broker)
    :broker(broker) {

}

QString Subscribe::get_message(const QString &topic_name){
    return broker->get_message(topic_name);
}

void Subscribe::subscribe(const QString &topic_name){
    broker -> subscribe(topic_name, this);
}

void Subscribe::add_reaction(const QString &topic_name, QString &reaction){
    broker -> add_reaction(topic_name,  reaction, this);
}
