#include "messagebroker.h"
#include "subscribe.h"
#include "Topic.h"
#include <qdebug.h>
#include <QDebug>

MessageBroker::MessageBroker(QObject* parent)
    : QObject(parent)
{

}


Topic* MessageBroker::search_topic(QString topic_name)
{
    auto it = topics.find(topic_name);
    if (it != topics.end())
        return &it.value();
    return nullptr;
}


void MessageBroker::add_topic(QString &topic_name)
{
    if(topics.contains(topic_name)){
        return;
    }
    else{
        Topic topic;
        topic.name = topic_name;
        topics.insert("topic_name", topic);
    }
}


void MessageBroker::publish_message(QString &topic_name, QString &message)
{
    Topic *topic = search_topic(topic_name);
    if(topic){
        topic->messages.enqueue(message);
    }
}


QString MessageBroker::get_message(QString &topic_name)
{
    Topic *topic = search_topic(topic_name);
    if(topic){
        topic->messages.dequeue();
    }
    return QString();
}


void MessageBroker::subscribe(QString &topic_name, Subscribe *subscriber){
    Topic *topic = search_topic(topic_name);
    if(topic){
        topic->subscribers.append(subscriber);
    }
}


void MessageBroker::add_reaction(QString &topic_name, QString &reaction, Subscribe *subscriber)
{
    Topic *topic = search_topic(topic_name);
    if(topic){
        topic->reaction[subscriber] = reaction;
    }
}















