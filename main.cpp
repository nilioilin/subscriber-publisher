#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "messagebroker.h"
#include "publish.h"
#include "subscribe.h"
#include "Topic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qInfo() << "ok";

    MessageBroker broker;
    Publish poblish(&broker);
    Subscribe temperture(&broker);

    QString message = "pressure message";

    broker.add_topic("pressure");
    poblish.add_message("pressure", message);
    Topic *topic = broker.search_topic("pressure");
    QString temp = temperture.get_message("pressure");
    qInfo() << temp;

    qInfo() << topic->name;


    return app.exec();
}
