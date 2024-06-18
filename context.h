#ifndef CONTEXT_H
#define CONTEXT_H
#include "calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"
#include "byfoldertype_calculationstrategy.h"

class StrategyInfo
{
public:
    StrategyInfo(QString nm, qint64 sz, float pc)
    {
        name = nm; size = sz; percent = pc;
    }
    QString name;
    qint64 size;
    float percent;
};

enum class STRATEGY{
    BYFOLDER=0,
    BYFILETYPE
};

class Context
{
public:
    explicit Context(STRATEGY flag);
    ~Context();
    void setNewStrategy(STRATEGY flag);
    QMap<QString, qint64>* useStrategy(QString path);
    //QMap<QString, qint64>* useStrategyMap(QString path);

private:
    qint64 getSizeMap(QMap<QString, qint64>* map);
    CalculationStrategy *strategy;
};

#endif // CONTEXT_H
