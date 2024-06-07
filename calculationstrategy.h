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
    virtual void SomeCalculationMethod(QDir start_directory) = 0;
    QMap<QString, unsigned int> get_map() {return map;}

protected:
    QMap<QString, unsigned int> map;
};

#endif // CALCULATIONSTRATEGY_H
