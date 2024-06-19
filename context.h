#ifndef CONTEXT_H
#define CONTEXT_H
#include "calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"
#include "byfoldertype_calculationstrategy.h"


enum STRATEGY{
    BYFOLDER=0,
    BYFILETYPE
};

class Context
{
public:
    explicit Context(CalculationStrategy* strt);
    ~Context();
    void setNewStrategy(CalculationStrategy* strt);
    QMap<QString, qint64>* useStrategy(QString path);

private:
    qint64 getSizeMap(QMap<QString, qint64>* map);
    CalculationStrategy *strategy;
};

#endif // CONTEXT_H
