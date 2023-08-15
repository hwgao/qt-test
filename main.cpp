#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <QDebug>

#include "messageprovider.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QTranslator  translator;
    if (translator.load(":/i18n/apptranslate_en.qm")) {
        app.installTranslator(&translator);
    } else {
        qWarning() << "Loading failed.";
    }

    QQmlApplicationEngine engine;

    //% Welcome %1 from %2
    MessageProvider msgProvider{qtTrId("welcome-message").arg("a", "b")};
    engine.rootContext()->setContextProperty("messageProvider", &msgProvider);
    const QUrl url(u"qrc:/translate/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
