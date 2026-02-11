#include "subscribe.h"
#include <QString>

Subscribe::Subscribe(QObject *parent, MessageBroker *broker)
    :QObject(parent), broker(broker) {

}

QString Subscribe::get_message(QString &topic_name){
    return broker->get_message(topic_name, this);
}

void Subscribe::subscribe(QString &topic_name){
    broker -> subscribe(topic_name, this);
}

void Subscribe::add_reaction(QString &topic_name, QString &reaction){
    broker -> add_reaction(topic_name,  reaction);
}
