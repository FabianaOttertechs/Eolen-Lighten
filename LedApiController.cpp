#include "LedApiController.h"
#include "ImpactVisualizer.h"

LedApiController::LedApiController(ImpactVisualizer* visualizer, QObject* parent)
    : QObject(parent), impactVisualizer(visualizer) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, &LedApiController::handleApiResponse);
}

void LedApiController::sendLedCommand(const QString& led, const QString& color) {
    QUrl apiUrl("https://18a8d84625ea.ngrok-free.app/api/led");
    QNetworkRequest request(apiUrl);

    // Configure SSL (ignore errors for testing, remove for production)
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject payload{
        {"led", led},
        {"color", color}
    };

    manager->post(request, QJsonDocument(payload).toJson());
}

void LedApiController::handleApiResponse(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "API Error:" << reply->errorString();
        emit apiError(reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonParseError parseError;
    QJsonDocument response = QJsonDocument::fromJson(reply->readAll(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON Parse Error:" << parseError.errorString();
        emit apiError("Invalid JSON response");
    }
    else if (response.isObject()) {
        QJsonObject json = response.object();
        if (json.contains("error")) {
            emit apiError(json["error"].toString());
        } else {
            processLedCommand(
                json["led"].toString(),
                json["color"].toString()
                );
        }
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
