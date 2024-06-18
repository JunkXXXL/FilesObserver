#include "fileexplorermodel.h"
#include <cmath>

FileExplorerModel::FileExplorerModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    //selfadapter = adap;
    //path = "D://C++";
    //dataModel = selfadapter->request(path);
}

void FileExplorerModel::update(QMap<QString, qint64>* newModel)
{
    dataModel = *newModel;
    emit layoutChanged();
   // dataModel = selfadapter->request(path);
}

void FileExplorerModel::setRootPath(QString str)
{
    //path = str;
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
        return dataModel.keys().at(index.row());
    } else if (index.column() == 1) {
        return  dataModel.values().at(index.row());
    } else if (index.column() == 2) {
        return round(dataModel.values().at(index.row())*1000000)/1000000 * 100;
    }
}

FileExplorerModel::~FileExplorerModel()
{

}
