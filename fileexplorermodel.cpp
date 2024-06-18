#include "fileexplorermodel.h"
#include <cmath>

FileExplorerModel::FileExplorerModel(QObject *parent, QList<StrategyInfo> dt) :
    QAbstractTableModel(parent)
{
    dataModel = dt;
}
//Возвращаем количество строк, в зависимости от количества данных в списке
int FileExplorerModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return dataModel.count();
}

int FileExplorerModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return PERCENT + 1;
}
//Возвращаем названия заголовков. Обратите внимание на тип возвращаемого значения.
QVariant FileExplorerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Vertical) {
        return section;
    }
    switch (section) {
    case NAME:
        return "Название";
    case SIZE:
        return "Размер";
    case PERCENT:
        return "В процентах";
    }
    return QVariant();
}

QVariant FileExplorerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() ||
        dataModel.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole))
    {
        return QVariant();
    }
    if (index.column() == 0) {
        return dataModel[index.row()].name;
    } else if (index.column() == 1) {
        return dataModel[index.row()].size;
    } else if (index.column() == 2) {
        qDebug() << dataModel[index.row()].percent;
        return round(dataModel[index.row()].percent*1000000)/1000000 * 100;
    }
}