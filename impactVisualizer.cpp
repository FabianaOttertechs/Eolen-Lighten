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
    m_headImpact(false), //capacete
    m_chestImpact(false), //cinto
    m_bellyImpact(false), //travaquedas
    m_feetImpact(false), //botas
    m_headLedColor(Qt::white), // branco no data, vermelho unsafe, verde safe, amarelo unsave warning
    m_chestLedColor(Qt::white),
    m_bellyLedColor(Qt::white),
    m_feetLedColor(Qt::white),
    m_socket(new QWebSocket()),
    m_handshakeCompleted(false)

{
    connect(m_socket, &QWebSocket::connected, this, &ImpactVisualizer::onConnected);
    connect(m_socket, &QWebSocket::disconnected, this, &ImpactVisualizer::onDisconnected);
    connect(m_socket, &QWebSocket::textMessageReceived,
            this, &ImpactVisualizer::onMessageReceived);
    connect(m_socket, &QWebSocket::errorOccurred,
            this, &ImpactVisualizer::onError);
    connect(m_socket, &QWebSocket::stateChanged,
            this, &ImpactVisualizer::connectionStatus);

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
    //setHeadLedColor(m_headImpact ? Qt::red : Qt::green : Qt::yellow);
}

void ImpactVisualizer::setChestImpact(bool chestImpact) {
    if (m_chestImpact == chestImpact) return;
    m_chestImpact = chestImpact;
    emit chestImpactChanged(m_chestImpact);
    //setChestLedColor(m_chestImpact ? Qt::red : Qt::green : Qt::yellow);
}

void ImpactVisualizer::setBellyImpact(bool bellyImpact) {
    if (m_bellyImpact == bellyImpact) return;
    m_bellyImpact = bellyImpact;
    emit bellyImpactChanged(m_bellyImpact);
    //setBellyLedColor(m_bellyImpact ? Qt::red : Qt::green : Qt::yellow);
}

void ImpactVisualizer::setFeetImpact(bool feetImpact) {
    if (m_feetImpact == feetImpact) return;
    m_feetImpact = feetImpact;
    emit feetImpactChanged(m_feetImpact);
    //setFeetLedColor(m_feetImpact ? Qt::red : Qt::green : Qt::yellow);
}

// Setters de cor (mantidos)
void ImpactVisualizer::setHeadLedColor(const QColor &color) {
    if (m_headLedColor == color) return;
    m_headLedColor = color;
    emit headLedColorChanged(m_headLedColor);
    qDebug() << "Capacete LED:" << color.name();

    if (color == Qt::red) {
        setHeadImpact(true);
    } else if (color == Qt::green) {
        setHeadImpact(false);
    }
}

void ImpactVisualizer::setChestLedColor(const QColor &color) {
    if (m_chestLedColor == color) return;
    m_chestLedColor = color;
    emit chestLedColorChanged(m_chestLedColor);
    qDebug() << "Cinto LED:" << color.name();

    if (color == Qt::red) {
        setChestImpact(true);
    } else if (color == Qt::green) {
        setChestImpact(false);
    }
}

void ImpactVisualizer::setBellyLedColor(const QColor &color) {
    if (m_bellyLedColor == color) return;
    m_bellyLedColor = color;
    emit bellyLedColorChanged(m_bellyLedColor);
    qDebug() << "Travaquedas LED:" << color.name();

    if (color == Qt::red) {
        setBellyImpact(true);
    } else if (color == Qt::green) {
        setBellyImpact(false);
    }
}

void ImpactVisualizer::setFeetLedColor(const QColor &color) {
    if (m_feetLedColor == color) return;
    m_feetLedColor = color;
    emit feetLedColorChanged(m_feetLedColor);
    qDebug() << "Botas LED:" << color.name();

    if (color == Qt::red) {
        setFeetImpact(true);
    } else if (color == Qt::green) {
        setFeetImpact(false);
    }
}

// Método unificado para controle de LEDs
void ImpactVisualizer::setLedColor(const QString &zone, const QString &color) {
    // QColor qColor;

    // if (color.compare("red", Qt::CaseInsensitive) == 0) {
    //     qColor = Qt::red;
    // } else if (color.compare("green", Qt::CaseInsensitive) == 0) {
    //     qColor = QColor("#32cd32"); // Verde-limão
    // } else if (color.compare("yellow", Qt::CaseInsensitive) == 0) {
    //     qColor = QColor("yellow"); // Amarelo
    // } else {
    //     qColor = Qt::white; // Default/neutro
    // }

    // if (zone.compare("head", Qt::CaseInsensitive) == 0) {
    //     setHeadLedColor(qColor);
    //     //setHeadImpact(qColor == Qt::red); // Atualiza estado lógico
    // }
    // else if (zone.compare("chest", Qt::CaseInsensitive) == 0) {
    //     setChestLedColor(qColor);
    //     //setChestImpact(qColor == Qt::red);
    // }
    // else if (zone.compare("belly", Qt::CaseInsensitive) == 0) {
    //     setBellyLedColor(qColor);
    //     //setBellyImpact(qColor == Qt::red);
    // }
    // else if (zone.compare("feet", Qt::CaseInsensitive) == 0) {
    //     setFeetLedColor(qColor);
    //     //setFeetImpact(qColor == Qt::red);
    // }
    QColor qColor;

    if (color.compare("red", Qt::CaseInsensitive) == 0) {
        qColor = Qt::red;
    } else if (color.compare("green", Qt::CaseInsensitive) == 0) {
        qColor = QColor("#32cd32");
    } else if (color.compare("yellow", Qt::CaseInsensitive) == 0) {
        qColor = QColor("#ffd300");
    } else {
        qColor = Qt::white;
    }

    if (zone.compare("capacete", Qt::CaseInsensitive) == 0) {
        if (m_headLedColor != qColor) {
            m_headLedColor = qColor;
            emit headLedColorChanged(m_headLedColor);
            qDebug() << "Head LED color changed to:" << m_headLedColor.name();
        }
    }
    else if (zone.compare("cinto", Qt::CaseInsensitive) == 0) {
        if (m_chestLedColor != qColor) {
            m_chestLedColor = qColor;
            emit chestLedColorChanged(m_chestLedColor);
            qDebug() << "Chest LED color changed to:" << m_chestLedColor.name();
        }
    }
    else if (zone.compare("travaquedas", Qt::CaseInsensitive) == 0) {
        if (m_bellyLedColor != qColor) {
            m_bellyLedColor = qColor;
            emit bellyLedColorChanged(m_bellyLedColor);
            qDebug() << "Belly LED color changed to:" << m_bellyLedColor.name();
        }
    }
    else if (zone.compare("botas", Qt::CaseInsensitive) == 0) {
        if (m_feetLedColor != qColor) {
            m_feetLedColor = qColor;
            emit feetLedColorChanged(m_feetLedColor);
            qDebug() << "Feet LED color changed to:" << m_feetLedColor.name();
        }
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
// Adicionando trigger para warning
void ImpactVisualizer::triggerHeadWarning() {
    setHeadLedColor(QColor("#ffd300"));
}
void ImpactVisualizer::triggerChestWarning() {
    setChestLedColor(QColor("#ffd300"));
}
void ImpactVisualizer::triggerBellyWarning() {
    setBellyLedColor(QColor("#ffd300"));
}
void ImpactVisualizer::triggerFeetWarning() {
    setFeetLedColor(QColor("#ffd300"));
}
void ImpactVisualizer::initializeConnection()
{
    if(m_socket->state() == QAbstractSocket::UnconnectedState) {
        connectWebSocket();
    }
}

void ImpactVisualizer::startConnection()
{
    qDebug() << "Iniciando conexão solicitada pelo QML";
    initializeConnection();
}

void ImpactVisualizer::connectWebSocket()
{
    // Fechar conexão existente
    if (m_socket->state() == QAbstractSocket::ConnectedState ||
        m_socket->state() == QAbstractSocket::ConnectingState) {
        qDebug() << "Já está conectado ou tentando conectar.";
        return;
    }

    QString serverUrl;
    //static bool tryWss = true; // Variável estática para alternar entre WSS/WS

    // if (tryWss) {
    //     serverUrl = "wss://211b584c6427.ngrok-free.app/socket.io/?EIO=4&transport=websocket";
    //     qDebug() << "Tentando conexão segura (WSS)...";
    // } else {
    //     serverUrl = "ws://localhost:5000/socket.io/?EIO=4&transport=websocket";
    // }
    serverUrl = "ws://localhost:5000/socket.io/?EIO=4&transport=websocket";//"wss://211b584c6427.ngrok-free.app/socket.io/?EIO=4&transport=websocket";
    qDebug() << "Connecting to WebSocket:" << serverUrl;

    m_handshakeCompleted = false;
    m_socket->open(QUrl(serverUrl));
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
    emit connectionStatusChanged(state());

    // Socket.IO handshake sequence
    m_socket->sendTextMessage("2probe");
    m_socket->sendTextMessage("5");

    // Configure handshake timeout (5 seconds)
    m_handshakeTimer.start(5000);
}

void ImpactVisualizer::onDisconnected()
{
    if (m_socket->isValid()) {
        m_socket->close();
    }
    qDebug() << "WebSocket disconnected!";
    m_webSocketConnected = false;
    m_handshakeCompleted = false;
    emit webSocketConnectedChanged(false);
    emit connectionStatusChanged(state());
}

void ImpactVisualizer::onError(QAbstractSocket::SocketError error)
{
    QString errorMsg;
    switch(error) {
    case QAbstractSocket::ConnectionRefusedError:
        errorMsg = "Servidor recusou a conexão";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        errorMsg = "Servidor fechou a conexão";
        break;
    case QAbstractSocket::HostNotFoundError:
        errorMsg = "Servidor não encontrado";
        break;
    case QAbstractSocket::SocketTimeoutError:
        errorMsg = "Timeout de conexão";
        break;
    default:
        errorMsg = QString("Erro de socket: %1").arg(error);
    }
    qDebug() << "WebSocket Error:" << errorMsg;
    //emit connectionError(errorMsg);
}

void ImpactVisualizer::onMessageReceived(const QString &message)
{
    qDebug() << "Message received:" << message;

    // Handle handshake response
    if (message == "3probe") {
        m_handshakeCompleted = true;
        m_handshakeTimer.stop();
        m_socket->sendTextMessage("40"); // Connect to default namespace
        qDebug() << "Handshake completed successfully";
        return;
    }

    // Handle ping-pong
    if (message == "2") {
        m_socket->sendTextMessage("3");
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
            QString color = data["led_color"].toString();

            setLedColor(zone, color);

            // Force property updates
            if (zone == "capacete") {
                emit headImpactChanged(impact);
                emit headLedColorChanged(m_headLedColor);
            }
            else if (zone == "cinto") {
                emit chestImpactChanged(impact);
                emit chestLedColorChanged(m_chestLedColor);
            }
            else if (zone == "travaquedas") {
                emit bellyImpactChanged(impact);
                emit bellyLedColorChanged(m_bellyLedColor);
            }
            else if (zone == "botas") {
                emit feetImpactChanged(impact);
                emit feetLedColorChanged(m_feetLedColor);
            }
        }
        else if (event == "state_update") {
            // Atualiza todos os LEDs de uma vez
            QJsonObject leds = data["leds"].toObject();
            for (const QString& zone : leds.keys()) {
                setLedColor(zone, leds[zone].toString());
            }

            // Se precisar resetar tudo, chame a função existente
            if (leds["capacete"] == "white" &&
                leds["cinto"] == "white" &&
                leds["travaquedas"] == "white" &&
                leds["botas"] == "white") {
                resetAllLeds(); // Reutiliza sua função existente
            }
        }

    }
}

// void ImpactVisualizer::handleSocketStateChange(QAbstractSocket::SocketState state)
// {
//     QString status;
//     switch(state) {
//     case QAbstractSocket::UnconnectedState: status = "Disconnected"; break;
//     case QAbstractSocket::ConnectingState: status = "Connecting"; break;
//     case QAbstractSocket::ConnectedState:
//         status = m_handshakeCompleted ? "Connected" : "Handshaking";
//         break;
//     default: status = "Unknown";
//     }
//     emit connectionStatusChanged(status);
// }
QString ImpactVisualizer::connectionStatus() const
{
    switch(m_socket->state()) {
    case QAbstractSocket::UnconnectedState:
        return "Disconnected";
    case QAbstractSocket::ConnectingState:
        return "Connecting...";
    case QAbstractSocket::ConnectedState:
        return m_handshakeCompleted ? "Connected" : "Handshaking";
    case QAbstractSocket::ClosingState:
        return "Closing";
    case QAbstractSocket::HostLookupState:
        return "Looking up host";
    case QAbstractSocket::BoundState:
        return "Bound";
    case QAbstractSocket::ListeningState:
        return "Listening";
    default:
        return "Unknown state";
    }
}
