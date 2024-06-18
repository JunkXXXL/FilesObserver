#ifndef FILEEXPLORERMODEL_H
#define FILEEXPLORERMODEL_H
#include <QFileSystemModel>
#include <QAbstractTableModel>
#include <QMap>

class FileExplorerModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FileExplorerModel(QObject *parent = nullptr);
    ~FileExplorerModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void update(QMap<QString, qint64>* newModel);

private:
    enum NameColumn {
        NAME = 0,
        SIZE,
        PERCENT
    };
    qint64 calculateMaxSize() const;
    QMap<QString, qint64> dataModel;
    qint64 maxSize;
};

#endif // FILEEXPLORERMODEL_H
