// #ifndef IMPACTVISUALIZER_H
// #define IMPACTVISUALIZER_H

// #include <QObject>
// #include <QQuickItem>

// class ImpactVisualizer : public QQuickItem
// {
//     Q_OBJECT
//     Q_PROPERTY(bool headImpact READ headImpact WRITE setHeadImpact NOTIFY headImpactChanged)
//     Q_PROPERTY(bool chestImpact READ chestImpact WRITE setChestImpact NOTIFY chestImpactChanged)
//     Q_PROPERTY(bool bellyImpact READ bellyImpact WRITE setBellyImpact NOTIFY bellyImpactChanged)
//     Q_PROPERTY(bool feetImpact READ feetImpact WRITE setFeetImpact NOTIFY feetImpactChanged)

// public:
//     explicit ImpactVisualizer(QQuickItem *parent = nullptr);

//     bool headImpact() const;
//     bool chestImpact() const;
//     bool bellyImpact() const;
//     bool feetImpact() const;

// public slots:
//     void setHeadImpact(bool headImpact);
//     void setChestImpact(bool chestImpact);
//     void setBellyImpact(bool bellyImpact);
//     void setFeetImpact(bool feetImpact);

//     // For direct control from C++
//     void triggerHeadImpact();
//     void triggerChestImpact();
//     void triggerBellyImpact();
//     void triggerFeetImpact();
//     void resetAllImpacts();
//     void setLedImpact(const QString& led, bool impact) {
//         if (led == "head") setHeadImpact(impact);
//         else if (led == "chest") setChestImpact(impact);
//         else if (led == "belly") setBellyImpact(impact);
//         else if (led == "feet") setFeetImpact(impact);
//     }

//     void setLedColor(const QString& led, const QString& color) {
//         setLedImpact(led, color == "red");
//     }

// signals:
//     void headImpactChanged(bool headImpact);
//     void chestImpactChanged(bool chestImpact);
//     void bellyImpactChanged(bool bellyImpact);
//     void feetImpactChanged(bool feetImpact);

// private:
//     bool m_headImpact;
//     bool m_chestImpact;
//     bool m_bellyImpact;
//     bool m_feetImpact;

// };

// #endif // IMPACTVISUALIZER_H
#ifndef IMPACTVISUALIZER_H
#define IMPACTVISUALIZER_H

#include <QQuickItem>
#include <QColor>
#include <QtWebSockets/QWebSocket>

class ImpactVisualizer : public QQuickItem
{
    Q_OBJECT

    // Impact properties (existing)
    Q_PROPERTY(bool headImpact READ headImpact WRITE setHeadImpact NOTIFY headImpactChanged)
    Q_PROPERTY(bool chestImpact READ chestImpact WRITE setChestImpact NOTIFY chestImpactChanged)
    Q_PROPERTY(bool bellyImpact READ bellyImpact WRITE setBellyImpact NOTIFY bellyImpactChanged)
    Q_PROPERTY(bool feetImpact READ feetImpact WRITE setFeetImpact NOTIFY feetImpactChanged)
    Q_PROPERTY(bool webSocketConnected READ isWebSocketConnected NOTIFY webSocketConnectedChanged)

    // LED Color properties (new)
    Q_PROPERTY(QColor headLedColor READ headLedColor WRITE setHeadLedColor NOTIFY headLedColorChanged)
    Q_PROPERTY(QColor chestLedColor READ chestLedColor WRITE setChestLedColor NOTIFY chestLedColorChanged)
    Q_PROPERTY(QColor bellyLedColor READ bellyLedColor WRITE setBellyLedColor NOTIFY bellyLedColorChanged)
    Q_PROPERTY(QColor feetLedColor READ feetLedColor WRITE setFeetLedColor NOTIFY feetLedColorChanged)

public:
    explicit ImpactVisualizer(QQuickItem *parent = nullptr);

    // Impact getters (existing)
    bool headImpact() const;
    bool chestImpact() const;
    bool bellyImpact() const;
    bool feetImpact() const;

    // LED Color getters (new)
    QColor headLedColor() const;
    QColor chestLedColor() const;
    QColor bellyLedColor() const;
    QColor feetLedColor() const;

public slots:
    // Impact setters (existing)
    void setHeadImpact(bool headImpact);
    void setChestImpact(bool chestImpact);
    void setBellyImpact(bool bellyImpact);
    void setFeetImpact(bool feetImpact);

    // LED Color setters (new)
    void setHeadLedColor(const QColor &color);
    void setChestLedColor(const QColor &color);
    void setBellyLedColor(const QColor &color);
    void setFeetLedColor(const QColor &color);

    // Impact triggers (existing)
    void triggerHeadImpact();
    void triggerChestImpact();
    void triggerBellyImpact();
    void triggerFeetImpact();

    // LED control methods (new)
    void setLedColor(const QString &zone, const QString &color);
    void resetAllLeds();
    bool isWebSocketConnected() const;
    void resetAllImpacts();

private slots:
    void onConnected();
    void onDisconnected();
    void onMessageReceived(const QString &message);
    void onError(QAbstractSocket::SocketError error);

signals:
    // Impact signals (existing)
    void headImpactChanged(bool headImpact);
    void chestImpactChanged(bool chestImpact);
    void bellyImpactChanged(bool bellyImpact);
    void feetImpactChanged(bool feetImpact);

    // LED Color signals (new)
    void headLedColorChanged(const QColor &color);
    void chestLedColorChanged(const QColor &color);
    void bellyLedColorChanged(const QColor &color);
    void feetLedColorChanged(const QColor &color);
    void webSocketConnectedChanged(bool connected);

private:
    // Impact members (existing)
    bool m_headImpact;
    bool m_chestImpact;
    bool m_bellyImpact;
    bool m_feetImpact;

    // LED Color members (new)
    QColor m_headLedColor;
    QColor m_chestLedColor;
    QColor m_bellyLedColor;
    QColor m_feetLedColor;

    QWebSocket *m_socket;
    void connectWebSocket();
    bool m_webSocketConnected;
};

#endif // IMPACTVISUALIZER_H
