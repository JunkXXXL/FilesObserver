#ifndef BYFOLDERTYPE_CALCULATIONSTRATEGY_H
#define BYFOLDERTYPE_CALCULATIONSTRATEGY_H
#include "calculationstrategy.h"
#include "QStringList"

class ByFolderType_CalculationStrategy: public CalculationStrategy
{
public:
    void SomeCalculationMethod(QDir start_directory);

private:
    unsigned int CalculateFolderWeigth(QDir folder);
    unsigned int CalculateCurrentFolder(QDir folder);
};

#endif // BYFOLDERTYPE_CALCULATIONSTRATEGY_H
