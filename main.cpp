#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tcp_server.h"
#include "tcp_client.h"
#include "file_opener.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    qmlRegisterType<TCP_Server>("tcpServer",1,0,"TcpServer");
    //qmlRegisterType<TCP_Session>("tcpSession",1,0,"TcpSession");
    qmlRegisterType<TCP_Client>("tcpClient",1,0,"TcpClient");

    file_opener f;
    f.openTheFile("C:\\Users\\Thomas\\Documents\\GIT\\standaloneQMLorCompositeComponents\\TEST.txt");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
