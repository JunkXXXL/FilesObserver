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
    enum STRATEGY{
        BYFOLDER=0,
        BYFILETYPE
    };
    virtual void SomeCalculationMethod(QDir start_directory) = 0;
    QMap<QString, unsigned int> get_map() {return map;}
    QMap<QString, float> get_percent() {return percent;}

protected:
    QMap<QString, unsigned int> map;
    QMap<QString, float> percent;
};

#endif // CALCULATIONSTRATEGY_H
