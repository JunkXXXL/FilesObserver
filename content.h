#ifndef CONTEXT_H
#define CONTEXT_H
#include "calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"
#include "byfoldertype_calculationstrategy.h"

class Content
{
public:
    explicit Content(CalculationStrategy::STRATEGY flag);
    ~Content();
    void test1(QString path);
    void test2(QString path);
    void test3(QString path);
    void example(QString path);

private:
    CalculationStrategy *strategy;
};

#endif // CONTEXT_H
