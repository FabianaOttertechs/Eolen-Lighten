#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>  // For debugging
#include "ImpactVisualizer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register your C++ type
    qmlRegisterType<ImpactVisualizer>("ImpactVisualizer", 1, 0, "ImpactVisualizer");

    QQmlApplicationEngine engine;
    // Set up the main QML file
    const QUrl url(QStringLiteral("qrc:/leds.qml"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}

