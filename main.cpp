#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl urlMainWindow(QStringLiteral("qrc:/main.qml"));


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [urlMainWindow](QObject *obj, const QUrl &objUrl) {
        if (!obj && urlMainWindow == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);





    engine.load(urlMainWindow);

    return app.exec();
}
