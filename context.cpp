#include "context.h"

Context::Context(STRATEGY flag)
{
    if (flag == STRATEGY::BYFILETYPE)
    {
        strategy = new ByFileType_CalculationStrategy();
    }
    else
    {
        strategy = new ByFolderType_CalculationStrategy();
    }
}

Context::~Context()
{
    delete strategy;
}

QMap<QString, qint64>* Context::useStrategy(QString path)
{

}

//void Context::test1(QString path)
//{
//    QDir dir(path + "empty folder");
//    strategy->SomeCalculationMethod(dir);
//    QMap<QString, qint64> *map = strategy->SomeCalculationMethod(dir);
//    QMapIterator<QString, qint64> iter(*map);
//    qint64 mapSize = getSizeMap(map);

//    while (iter.hasNext())
//    {
//        iter.next();
//        QString key = iter.key();
//        qDebug() << key << ": " << iter.value();
//    }
//    delete map;
//}


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
