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
#include <QTimer>
#include <QDebug>

ImpactVisualizer::ImpactVisualizer(QQuickItem *parent)
    : QQuickItem(parent),
    m_headImpact(false),
    m_chestImpact(false),
    m_bellyImpact(false),
    m_feetImpact(false),
    m_headLedColor(Qt::white),
    m_chestLedColor(Qt::white),
    m_bellyLedColor(Qt::white),
    m_feetLedColor(Qt::white)
{
}

// Impact getters (existing)
bool ImpactVisualizer::headImpact() const { return m_headImpact; }
bool ImpactVisualizer::chestImpact() const { return m_chestImpact; }
bool ImpactVisualizer::bellyImpact() const { return m_bellyImpact; }
bool ImpactVisualizer::feetImpact() const { return m_feetImpact; }

// LED Color getters (new)
QColor ImpactVisualizer::headLedColor() const { return m_headLedColor; }
QColor ImpactVisualizer::chestLedColor() const { return m_chestLedColor; }
QColor ImpactVisualizer::bellyLedColor() const { return m_bellyLedColor; }
QColor ImpactVisualizer::feetLedColor() const { return m_feetLedColor; }

// Impact setters (existing)
void ImpactVisualizer::setHeadImpact(bool headImpact)
{
    if (m_headImpact == headImpact) return;
    m_headImpact = headImpact;
    emit headImpactChanged(m_headImpact);
    if (m_headImpact) {
        QTimer::singleShot(1000, this, [this]() { setHeadImpact(false); });
    }
}

void ImpactVisualizer::setChestImpact(bool chestImpact)
{
    if (m_chestImpact == chestImpact) return;
    m_chestImpact = chestImpact;
    emit chestImpactChanged(m_chestImpact);
    if (m_chestImpact) {
        QTimer::singleShot(1000, this, [this]() { setChestImpact(false); });
    }
}

void ImpactVisualizer::setBellyImpact(bool bellyImpact)
{
    if (m_bellyImpact == bellyImpact) return;
    m_bellyImpact = bellyImpact;
    emit bellyImpactChanged(m_bellyImpact);
    if (m_bellyImpact) {
        QTimer::singleShot(1000, this, [this]() { setBellyImpact(false); });
    }
}

void ImpactVisualizer::setFeetImpact(bool feetImpact)
{
    if (m_feetImpact == feetImpact) return;
    m_feetImpact = feetImpact;
    emit feetImpactChanged(m_feetImpact);
    if (m_feetImpact) {
        QTimer::singleShot(1000, this, [this]() { setFeetImpact(false); });
    }
}

// LED Color setters (new)
void ImpactVisualizer::setHeadLedColor(const QColor &color)
{
    if (m_headLedColor == color) return;
    m_headLedColor = color;
    emit headLedColorChanged(m_headLedColor);
    qDebug() << "Head LED color changed to:" << color;
}

void ImpactVisualizer::setChestLedColor(const QColor &color)
{
    if (m_chestLedColor == color) return;
    m_chestLedColor = color;
    emit chestLedColorChanged(m_chestLedColor);
    qDebug() << "Chest LED color changed to:" << color;
}

void ImpactVisualizer::setBellyLedColor(const QColor &color)
{
    if (m_bellyLedColor == color) return;
    m_bellyLedColor = color;
    emit bellyLedColorChanged(m_bellyLedColor);
    qDebug() << "Belly LED color changed to:" << color;
}

void ImpactVisualizer::setFeetLedColor(const QColor &color)
{
    if (m_feetLedColor == color) return;
    m_feetLedColor = color;
    emit feetLedColorChanged(m_feetLedColor);
    qDebug() << "Feet LED color changed to:" << color;
}

// Impact triggers (existing)
void ImpactVisualizer::triggerHeadImpact() { setHeadImpact(true); }
void ImpactVisualizer::triggerChestImpact() { setChestImpact(true); }
void ImpactVisualizer::triggerBellyImpact() { setBellyImpact(true); }
void ImpactVisualizer::triggerFeetImpact() { setFeetImpact(true); }

// LED control methods (new)
void ImpactVisualizer::setLedColor(const QString &zone, const QString &color)
{
    QColor qColor;
    if (color.toLower() == "red") {
        qColor = Qt::red;
    } else if (color.toLower() == "green") {
        qColor = QColor("#32cd32"); // Lime green
    } else if (color.toLower() == "white") {
        qColor = Qt::white;
    } else if (color.toLower() == "yellow") {
        qColor = Qt::yellow;
    } else if (color.toLower() == "black") {
        qColor = Qt::black;
    } else {
        qColor = QColor(color); // Try to parse as hex or named color
    }

    if (zone.toLower() == "head") {
        setHeadLedColor(qColor);
    } else if (zone.toLower() == "chest") {
        setChestLedColor(qColor);
    } else if (zone.toLower() == "belly") {
        setBellyLedColor(qColor);
    } else if (zone.toLower() == "feet") {
        setFeetLedColor(qColor);
    }
}

void ImpactVisualizer::resetAllLeds()
{
    setHeadLedColor(Qt::white);
    setChestLedColor(Qt::white);
    setBellyLedColor(Qt::white);
    setFeetLedColor(Qt::white);
    qDebug() << "All LEDs reset to white";
}

void ImpactVisualizer::resetAllImpacts()
{
    setHeadImpact(false);
    setChestImpact(false);
    setBellyImpact(false);
    setFeetImpact(false);
}
