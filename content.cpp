#include "content.h"

Content::Content(CalculationStrategy::STRATEGY flag)
{
    if (flag == CalculationStrategy::BYFILETYPE)
    {
        strategy = new ByFileType_CalculationStrategy();
    }
    else
    {
        strategy = new ByFolderType_CalculationStrategy();
    }
}

Content::~Content()
{
    delete strategy;
}

void Content::test1(QString path)
{
    QDir dir(path + "empty folder");
    strategy->SomeCalculationMethod(dir);
    const QMap<QString, unsigned int> &map = strategy->get_map();
    const QMap<QString, float> &percent = strategy->get_percent();
    QMapIterator<QString, unsigned int> iter(map);

    while (iter.hasNext())
    {
        iter.next();
        QString key = iter.key();
        qDebug() << key << ": " << iter.value() << Qt::fixed << qSetRealNumberPrecision(2) << percent[key] << "%";
    }
}

void Content::test2(QString path)
{
    QDir dir(path + "folder with only files");
    strategy->SomeCalculationMethod(dir);
    const QMap<QString, unsigned int> &map = strategy->get_map();
    const QMap<QString, float> &percent = strategy->get_percent();
    QMapIterator<QString, unsigned int> iter(map);

    while (iter.hasNext())
    {
        iter.next();
        QString key = iter.key();
        qDebug() << key << ": " << iter.value() << Qt::fixed << qSetRealNumberPrecision(2) << percent[key] << "%";
    }
}

void Content::test3(QString path)
{
    QDir dir(path + "folder with only folders");
    strategy->SomeCalculationMethod(dir);
    const QMap<QString, unsigned int> &map = strategy->get_map();
    const QMap<QString, float> &percent = strategy->get_percent();
    QMapIterator<QString, unsigned int> iter(map);

    while (iter.hasNext())
    {
        iter.next();
        QString key = iter.key();
        qDebug() << key << ": " << iter.value() << Qt::fixed << qSetRealNumberPrecision(2) << percent[key] << "%";
    }
}

void Content::example(QString path)
{
    QDir dir(path + "folder");
    strategy->SomeCalculationMethod(dir);
    const QMap<QString, unsigned int> &map = strategy->get_map();
    const QMap<QString, float> &percent = strategy->get_percent();
    QMapIterator<QString, unsigned int> iter(map);

    while (iter.hasNext())
    {
        iter.next();
        QString key = iter.key();
        qDebug() << key << ": " << iter.value() << Qt::fixed << qSetRealNumberPrecision(2) << percent[key] << "%";
    }
}
