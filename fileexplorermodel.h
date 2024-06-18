#ifndef FILEEXPLORERMODEL_H
#define FILEEXPLORERMODEL_H
#include <QFileSystemModel>
#include <QAbstractTableModel>
#include "adapters.h"
#include <QMap>

class FileExplorerModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FileExplorerModel(QObject *parent = nullptr);
    ~FileExplorerModel();
    //Минимальный и обязательный набор необходимых методов
    //Так как нам требуется только отображать данные, то этого набора достаточно
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void setRootPath(QString str);
    void update(QMap<QString, qint64>* newModel);

private:
    //Определим перечисление NameColumn для индексации столбцов нашей таблицы.
    enum NameColumn {
        NAME = 0,
        SIZE,
        PERCENT
    };
   // QString path;
   // Adapter* selfadapter;
    //Представим данные модели в виде списка.
    QMap<QString, qint64> dataModel;
};

#endif // FILEEXPLORERMODEL_H
