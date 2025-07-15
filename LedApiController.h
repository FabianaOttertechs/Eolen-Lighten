#ifndef LEDAPICONTROLLER_H
#define LEDAPICONTROLLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>

class ImpactVisualizer; // Forward declaration

class LedApiController : public QObject {
    Q_OBJECT
public:
    explicit LedApiController(ImpactVisualizer* visualizer, QObject* parent = nullptr);

    Q_INVOKABLE void sendLedCommand(const QString& led, const QString& color);

signals:
    void apiError(const QString& message);

private slots:
    void handleApiResponse(QNetworkReply* reply);

private:
    QNetworkAccessManager* manager;
    ImpactVisualizer* impactVisualizer; // Reference to your existing visualizer

    void processLedCommand(const QString& led, const QString& color);
};

#endif // LEDAPICONTROLLER_H
