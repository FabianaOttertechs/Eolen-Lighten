#ifndef IMPACTVISUALIZER_H
#define IMPACTVISUALIZER_H

#include <QObject>
#include <QQuickItem>

class ImpactVisualizer : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(bool headImpact READ headImpact WRITE setHeadImpact NOTIFY headImpactChanged)
    Q_PROPERTY(bool chestImpact READ chestImpact WRITE setChestImpact NOTIFY chestImpactChanged)
    Q_PROPERTY(bool bellyImpact READ bellyImpact WRITE setBellyImpact NOTIFY bellyImpactChanged)
    Q_PROPERTY(bool feetImpact READ feetImpact WRITE setFeetImpact NOTIFY feetImpactChanged)

public:
    explicit ImpactVisualizer(QQuickItem *parent = nullptr);

    bool headImpact() const;
    bool chestImpact() const;
    bool bellyImpact() const;
    bool feetImpact() const;

public slots:
    void setHeadImpact(bool headImpact);
    void setChestImpact(bool chestImpact);
    void setBellyImpact(bool bellyImpact);
    void setFeetImpact(bool feetImpact);

    // For direct control from C++
    void triggerHeadImpact();
    void triggerChestImpact();
    void triggerBellyImpact();
    void triggerFeetImpact();
    void resetAllImpacts();
    void setLedImpact(const QString& led, bool impact) {
        if (led == "head") setHeadImpact(impact);
        else if (led == "chest") setChestImpact(impact);
        else if (led == "belly") setBellyImpact(impact);
        else if (led == "feet") setFeetImpact(impact);
    }

    void setLedColor(const QString& led, const QString& color) {
        setLedImpact(led, color == "red");
    }

signals:
    void headImpactChanged(bool headImpact);
    void chestImpactChanged(bool chestImpact);
    void bellyImpactChanged(bool bellyImpact);
    void feetImpactChanged(bool feetImpact);

private:
    bool m_headImpact;
    bool m_chestImpact;
    bool m_bellyImpact;
    bool m_feetImpact;
};

#endif // IMPACTVISUALIZER_H
