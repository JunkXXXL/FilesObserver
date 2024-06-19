#include "context.h"

Context::Context(CalculationStrategy* strt)
{
    strategy = strt;
}

Context::~Context()
{
}

QMap<QString, qint64>* Context::useStrategy(QString path)
{
    QMap<QString, qint64>* map = strategy->SomeCalculationMethod(path);
    return map;
}


qint64 Context::getSizeMap(QMap<QString, qint64>* map)
{
    qint64 folderSize = 0;
    QMapIterator<QString, qint64> iter(*map);
    while (iter.hasNext())
    {
        iter.next();
        QString key = iter.key();
        folderSize += (*map)[key];
    }
    return folderSize;
}

void Context::setNewStrategy(CalculationStrategy* strt)
{
    strategy = strt;
}
