#include "ImpactVisualizer.h"
#include <QTimer>

ImpactVisualizer::ImpactVisualizer(QQuickItem *parent)
    : QQuickItem(parent),
    m_headImpact(false),
    m_chestImpact(false),
    m_bellyImpact(false),
    m_feetImpact(false)
{
}

bool ImpactVisualizer::headImpact() const
{
    return m_headImpact;
}

bool ImpactVisualizer::chestImpact() const
{
    return m_chestImpact;
}

bool ImpactVisualizer::bellyImpact() const
{
    return m_bellyImpact;
}

bool ImpactVisualizer::feetImpact() const
{
    return m_feetImpact;
}

void ImpactVisualizer::setHeadImpact(bool headImpact)
{
    if (m_headImpact == headImpact)
        return;

    m_headImpact = headImpact;
    emit headImpactChanged(m_headImpact);

    if (m_headImpact) {
        QTimer::singleShot(1000, this, [this]() {
            setHeadImpact(false);
        });
    }
}

void ImpactVisualizer::setChestImpact(bool chestImpact)
{
    if (m_chestImpact == chestImpact)
        return;

    m_chestImpact = chestImpact;
    emit chestImpactChanged(m_chestImpact);

    if (m_chestImpact) {
        QTimer::singleShot(1000, this, [this]() {
            setChestImpact(false);
        });
    }
}

void ImpactVisualizer::setBellyImpact(bool bellyImpact)
{
    if (m_bellyImpact == bellyImpact)
        return;

    m_bellyImpact = bellyImpact;
    emit bellyImpactChanged(m_bellyImpact);

    if (m_bellyImpact) {
        QTimer::singleShot(1000, this, [this]() {
            setBellyImpact(false);
        });
    }
}

void ImpactVisualizer::setFeetImpact(bool feetImpact)
{
    if (m_feetImpact == feetImpact)
        return;

    m_feetImpact = feetImpact;
    emit feetImpactChanged(m_feetImpact);

    if (m_feetImpact) {
        QTimer::singleShot(1000, this, [this]() {
            setFeetImpact(false);
        });
    }
}

void ImpactVisualizer::triggerHeadImpact()
{
    setHeadImpact(true);
}

void ImpactVisualizer::triggerChestImpact()
{
    setChestImpact(true);
}

void ImpactVisualizer::triggerBellyImpact()
{
    setBellyImpact(true);
}

void ImpactVisualizer::triggerFeetImpact()
{
    setFeetImpact(true);
}

void ImpactVisualizer::resetAllImpacts()
{
    setHeadImpact(false);
    setChestImpact(false);
    setBellyImpact(false);
    setFeetImpact(false);
}
