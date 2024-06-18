#ifndef ADAPTERS_H
#define ADAPTERS_H
#include "QVariant"
#include "context.h"
#include "qDebug.h"

class Target
{
public:
    explicit Target(Context* cntx)
    {
        context = cntx;
    }
    virtual QList<StrategyInfo>* request(QString) = 0;

protected:
    Context* context;
};

class Adapter: public Target
{
public:
    explicit Adapter(Context* cntx) : Target(cntx) {}
    QList<StrategyInfo>* request(QString path) override
    {
        QMap<QString, qint64>* map = context->useStrategy(path);
        QList<StrategyInfo>* to_ret = new QList<StrategyInfo>;
        QMapIterator<QString, qint64> iter(*map);
        qint64 sizeMap = getSizeMap(map);

        while (iter.hasNext())
        {
            iter.next();
            StrategyInfo info = StrategyInfo(iter.key(), iter.value(), float(iter.value())/float(sizeMap));
            to_ret->insert(to_ret->size(), info);
        }

        delete map;
        return to_ret;
    }

private:
    qint64 getSizeMap(QMap<QString, qint64>* map)
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
};

#endif // ADAPTERS_H
