// #include "ImpactVisualizer.h"
// #include <QTimer>

// ImpactVisualizer::ImpactVisualizer(QQuickItem *parent)
//     : QQuickItem(parent),
//     m_headImpact(false),
//     m_chestImpact(false),
//     m_bellyImpact(false),
//     m_feetImpact(false)
// {
// }

// bool ImpactVisualizer::headImpact() const
// {
//     return m_headImpact;
// }

// bool ImpactVisualizer::chestImpact() const
// {
//     return m_chestImpact;
// }

// bool ImpactVisualizer::bellyImpact() const
// {
//     return m_bellyImpact;
// }

// bool ImpactVisualizer::feetImpact() const
// {
//     return m_feetImpact;
// }

// void ImpactVisualizer::setHeadImpact(bool headImpact)
// {
//     if (m_headImpact == headImpact)
//         return;

//     m_headImpact = headImpact;
//     emit headImpactChanged(m_headImpact);

//     if (m_headImpact) {
//         QTimer::singleShot(1000, this, [this]() {
//             setHeadImpact(false);
//         });
//     }
// }

// void ImpactVisualizer::setChestImpact(bool chestImpact)
// {
//     if (m_chestImpact == chestImpact)
//         return;

//     m_chestImpact = chestImpact;
//     emit chestImpactChanged(m_chestImpact);

//     if (m_chestImpact) {
//         QTimer::singleShot(1000, this, [this]() {
//             setChestImpact(false);
//         });
//     }
// }

// void ImpactVisualizer::setBellyImpact(bool bellyImpact)
// {
//     if (m_bellyImpact == bellyImpact)
//         return;

//     m_bellyImpact = bellyImpact;
//     emit bellyImpactChanged(m_bellyImpact);

//     if (m_bellyImpact) {
//         QTimer::singleShot(1000, this, [this]() {
//             setBellyImpact(false);
//         });
//     }
// }

// void ImpactVisualizer::setFeetImpact(bool feetImpact)
// {
//     if (m_feetImpact == feetImpact)
//         return;

//     m_feetImpact = feetImpact;
//     emit feetImpactChanged(m_feetImpact);

//     if (m_feetImpact) {
//         QTimer::singleShot(1000, this, [this]() {
//             setFeetImpact(false);
//         });
//     }
// }

// void ImpactVisualizer::triggerHeadImpact()
// {
//     setHeadImpact(true);
// }

// void ImpactVisualizer::triggerChestImpact()
// {
//     setChestImpact(true);
// }

// void ImpactVisualizer::triggerBellyImpact()
// {
//     setBellyImpact(true);
// }

// void ImpactVisualizer::triggerFeetImpact()
// {
//     setFeetImpact(true);
// }

// void ImpactVisualizer::resetAllImpacts()
// {
//     setHeadImpact(false);
//     setChestImpact(false);
//     setBellyImpact(false);
//     setFeetImpact(false);
// }
#include "ImpactVisualizer.h"
#include <QDebug>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QTimer>

ImpactVisualizer::ImpactVisualizer(QQuickItem *parent)
    : QQuickItem(parent),
    m_headImpact(false),
    m_chestImpact(false),
    m_bellyImpact(false),
    m_feetImpact(false),
    m_headLedColor(Qt::white),
    m_chestLedColor(Qt::white),
    m_bellyLedColor(Qt::white),
    m_feetLedColor(Qt::white),
    m_socket(new QWebSocket())

{
    connect(m_socket, &QWebSocket::connected, this, &ImpactVisualizer::onConnected);
    connect(m_socket, &QWebSocket::textMessageReceived,
            this, &ImpactVisualizer::onMessageReceived);
    connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error),
            this, &ImpactVisualizer::onError);

    connectWebSocket();
}

// Getters mantidos como estão
bool ImpactVisualizer::headImpact() const { return m_headImpact; }
bool ImpactVisualizer::chestImpact() const { return m_chestImpact; }
bool ImpactVisualizer::bellyImpact() const { return m_bellyImpact; }
bool ImpactVisualizer::feetImpact() const { return m_feetImpact; }

QColor ImpactVisualizer::headLedColor() const { return m_headLedColor; }
QColor ImpactVisualizer::chestLedColor() const { return m_chestLedColor; }
QColor ImpactVisualizer::bellyLedColor() const { return m_bellyLedColor; }
QColor ImpactVisualizer::feetLedColor() const { return m_feetLedColor; }

// Setters de impacto modificados (removendo auto-reset)
void ImpactVisualizer::setHeadImpact(bool headImpact) {
    if (m_headImpact == headImpact) return;
    m_headImpact = headImpact;
    emit headImpactChanged(m_headImpact);
    // Cor relacionada ao estado de impacto
    setHeadLedColor(m_headImpact ? Qt::red : Qt::green);
}

void ImpactVisualizer::setChestImpact(bool chestImpact) {
    if (m_chestImpact == chestImpact) return;
    m_chestImpact = chestImpact;
    emit chestImpactChanged(m_chestImpact);
    setChestLedColor(m_chestImpact ? Qt::red : Qt::green);
}

void ImpactVisualizer::setBellyImpact(bool bellyImpact) {
    if (m_bellyImpact == bellyImpact) return;
    m_bellyImpact = bellyImpact;
    emit bellyImpactChanged(m_bellyImpact);
    setBellyLedColor(m_bellyImpact ? Qt::red : Qt::green);
}

void ImpactVisualizer::setFeetImpact(bool feetImpact) {
    if (m_feetImpact == feetImpact) return;
    m_feetImpact = feetImpact;
    emit feetImpactChanged(m_feetImpact);
    setFeetLedColor(m_feetImpact ? Qt::red : Qt::green);
}

// Setters de cor (mantidos)
void ImpactVisualizer::setHeadLedColor(const QColor &color) {
    if (m_headLedColor == color) return;
    m_headLedColor = color;
    emit headLedColorChanged(m_headLedColor);
    qDebug() << "Head LED:" << color.name();
}

void ImpactVisualizer::setChestLedColor(const QColor &color) {
    if (m_chestLedColor == color) return;
    m_chestLedColor = color;
    emit chestLedColorChanged(m_chestLedColor);
    qDebug() << "Chest LED:" << color.name();
}

void ImpactVisualizer::setBellyLedColor(const QColor &color) {
    if (m_bellyLedColor == color) return;
    m_bellyLedColor = color;
    emit bellyLedColorChanged(m_bellyLedColor);
    qDebug() << "Belly LED:" << color.name();
}

void ImpactVisualizer::setFeetLedColor(const QColor &color) {
    if (m_feetLedColor == color) return;
    m_feetLedColor = color;
    emit feetLedColorChanged(m_feetLedColor);
    qDebug() << "Feet LED:" << color.name();
}

// Método unificado para controle de LEDs
void ImpactVisualizer::setLedColor(const QString &zone, const QString &color) {
    QColor qColor;

    if (color.compare("red", Qt::CaseInsensitive) == 0) {
        qColor = Qt::red;
    } else if (color.compare("green", Qt::CaseInsensitive) == 0) {
        qColor = QColor("#32cd32"); // Verde-limão
    } else {
        qColor = Qt::white; // Default/neutro
    }

    if (zone.compare("head", Qt::CaseInsensitive) == 0) {
        setHeadLedColor(qColor);
        setHeadImpact(qColor == Qt::red); // Atualiza estado lógico
    }
    else if (zone.compare("chest", Qt::CaseInsensitive) == 0) {
        setChestLedColor(qColor);
        setChestImpact(qColor == Qt::red);
    }
    else if (zone.compare("belly", Qt::CaseInsensitive) == 0) {
        setBellyLedColor(qColor);
        setBellyImpact(qColor == Qt::red);
    }
    else if (zone.compare("feet", Qt::CaseInsensitive) == 0) {
        setFeetLedColor(qColor);
        setFeetImpact(qColor == Qt::red);
    }
}

// Reset geral
void ImpactVisualizer::resetAllLeds() {
    setHeadLedColor(Qt::white);
    setChestLedColor(Qt::white);
    setBellyLedColor(Qt::white);
    setFeetLedColor(Qt::white);
    // Não altera automaticamente os estados de impacto
    qDebug() << "All LEDs reset to white (neutral)";
}

void ImpactVisualizer::resetAllImpacts() {
    setHeadImpact(false);
    setChestImpact(false);
    setBellyImpact(false);
    setFeetImpact(false);
    // As cores serão atualizadas automaticamente via setters
}

// Triggers (opcionais - mantidos para compatibilidade)
void ImpactVisualizer::triggerHeadImpact() {
    setHeadImpact(true);
    setHeadLedColor(Qt::red);
}
void ImpactVisualizer::triggerChestImpact() {
    setChestImpact(true);
    setChestLedColor(Qt::red);
}
void ImpactVisualizer::triggerBellyImpact() {
    setBellyImpact(true);
    setBellyLedColor(Qt::red);
}
void ImpactVisualizer::triggerFeetImpact() {
    setFeetImpact(true);
    setFeetLedColor(Qt::red);
}
void ImpactVisualizer::connectWebSocket()
{
    //m_socket->open(QUrl("ws://localhost:5000/socket.io/?EIO=4&transport=websocket")); //seridor local
    m_socket->open(QUrl("wss://7248700b1416.ngrok-free.app/socket.io/?EIO=4&transport=websocket")); //acesso externo
}

bool ImpactVisualizer::isWebSocketConnected() const
{
    return m_webSocketConnected;
}

void ImpactVisualizer::onConnected()
{
    qDebug() << "WebSocket connected!";
    m_webSocketConnected = true;
    emit webSocketConnectedChanged(true);

    // Send Socket.IO handshake sequence
    m_socket->sendTextMessage("2probe");
    m_socket->sendTextMessage("5"); // Binary support
}

void ImpactVisualizer::onDisconnected()
{
    qDebug() << "WebSocket disconnected!";
    m_webSocketConnected = false;
    emit webSocketConnectedChanged(false);

    // Attempt reconnect after delay
    QTimer::singleShot(3000, this, &ImpactVisualizer::connectWebSocket);
}

void ImpactVisualizer::onError(QAbstractSocket::SocketError error)
{
    qWarning() << "WebSocket error:" << error << m_socket->errorString();
    onDisconnected();
}

void ImpactVisualizer::onMessageReceived(const QString &message)
{
    qDebug() << "Message received:" << message;

    if (message == "2") {  // Ping recebido
        m_socket->sendTextMessage("3");  // Responde com pong
        return;
    }
    // Socket.IO protocol messages start with numbers
    if (message.startsWith("0")) {
        // Initial handshake response
        m_socket->sendTextMessage("40");
    }

    else if (message.startsWith("42")) {
        // Actual data message (42["event",{data}])
        QJsonDocument doc = QJsonDocument::fromJson(message.mid(2).toUtf8());
        if (!doc.isArray()) return;

        QJsonArray arr = doc.array();
        if (arr.size() < 2) return;

        QString event = arr[0].toString();
        QJsonObject data = arr[1].toObject();

        if (event == "led_update") {
            QString led = data["led"].toString();
            QString color = data["color"].toString();
            setLedColor(led, color);
        }
        else if (event == "impact_update") {
            QString zone = data["zone"].toString();
            bool impact = data["impact"].toBool();

            // Call the specific impact method based on zone
            if (zone == "head") {
                setHeadImpact(impact);
            }
            else if (zone == "chest") {
                setChestImpact(impact);
            }
            else if (zone == "belly") {
                setBellyImpact(impact);
            }
            else if (zone == "feet") {
                setFeetImpact(impact);
            }
        }
    }
}


