#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include "QMap"
#include "QDir"
#include "QDebug"
#include "QDirIterator"
#include "memory"


class CalculationStrategy
{
public:
    virtual QMap<QString, qint64>* SomeCalculationMethod(QDir start_directory) = 0;
};

#endif // CALCULATIONSTRATEGY_H
