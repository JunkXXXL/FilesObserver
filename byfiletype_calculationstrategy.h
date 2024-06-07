#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H
#include "calculationstrategy.h"


class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    void SomeCalculationMethod(QDir start_directory);
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
