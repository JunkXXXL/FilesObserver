#ifndef BYFOLDERTYPE_CALCULATIONSTRATEGY_H
#define BYFOLDERTYPE_CALCULATIONSTRATEGY_H
#include "calculationstrategy.h"
#include "QStringList"

class ByFolderType_CalculationStrategy: public CalculationStrategy
{
public:
    QMap<QString, qint64>* SomeCalculationMethod(QDir start_directory);

private:
    qint64 CalculateFolderWeigth(QDir folder);
    qint64 CalculateCurrentFolder(QDir folder);
};

#endif // BYFOLDERTYPE_CALCULATIONSTRATEGY_H
