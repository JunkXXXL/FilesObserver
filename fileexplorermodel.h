#ifndef FILEEXPLORERMODEL_H
#define FILEEXPLORERMODEL_H
#include <QFileSystemModel>
#include <QAbstractTableModel>

class SomeData
{
public:
    SomeData(QString nm = "SomeName", QString sz = "SomeSize", QString pr = "SomePercent")
    {
        name = nm;
        size = sz;
        percent = pr;
    }

    QString name, size, percent;
};

class FileExplorerModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FileExplorerModel(QObject *parent = nullptr, QList<SomeData> dt =QList<SomeData>());
    //Минимальный и обязательный набор необходимых методов
    //Так как нам требуется только отображать данные, то этого набора достаточно
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    //Определим перечисление NameColumn для индексации столбцов нашей таблицы.
    enum NameColumn {
        NAME = 0,
        SIZE,
        PERCENT
    };
    //Представим данные модели в виде списка.
    QList<SomeData> dataModel;
};

#endif // FILEEXPLORERMODEL_H
