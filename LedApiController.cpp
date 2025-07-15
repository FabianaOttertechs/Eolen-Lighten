#include "LedApiController.h"
#include "ImpactVisualizer.h"

LedApiController::LedApiController(ImpactVisualizer* visualizer, QObject* parent)
    : QObject(parent), impactVisualizer(visualizer) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, &LedApiController::handleApiResponse);
}

void LedApiController::sendLedCommand(const QString& led, const QString& color) {
    QUrl apiUrl("http://your-api-server.com/api/led");
    QNetworkRequest request(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject payload{
        {"led", led},
        {"color", color}
    };

    manager->post(request, QJsonDocument(payload).toJson());
}

void LedApiController::handleApiResponse(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        emit apiError(reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
    if (response.isObject()) {
        QJsonObject json = response.object();
        processLedCommand(
            json["led"].toString(),
            json["color"].toString()
            );
    }
    reply->deleteLater();
}

void LedApiController::processLedCommand(const QString& led, const QString& color) {
    if (!impactVisualizer) return;

    bool impactState = (color == "red");

    if (led == "head") {
        impactVisualizer->setHeadImpact(impactState);
    }
    else if (led == "chest") {
        impactVisualizer->setChestImpact(impactState);
    }
    else if (led == "belly") {
        impactVisualizer->setBellyImpact(impactState);
    }
    else if (led == "feet") {
        impactVisualizer->setFeetImpact(impactState);
    }
}
