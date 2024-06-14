#ifndef CONTEXT_H
#define CONTEXT_H
#include "calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"
#include "byfoldertype_calculationstrategy.h"


enum class STRATEGY{
    BYFOLDER=0,
    BYFILETYPE
};

class Context
{
public:
    explicit Context(STRATEGY flag);
    ~Context();
    void test1(QString path);
    void test2(QString path);
    void test3(QString path);
    void example(QString path);

private:
    qint64 getSizeMap(QMap<QString, qint64>* map);
    CalculationStrategy *strategy;
};

#endif // CONTEXT_H
