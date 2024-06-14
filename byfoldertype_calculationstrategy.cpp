#include "byfoldertype_calculationstrategy.h"

QMap<QString, qint64>* ByFolderType_CalculationStrategy::SomeCalculationMethod(QDir start_directory)
{
    QMap<QString, qint64>* map = new QMap<QString, qint64>();
    QDirIterator it(start_directory, QDirIterator::NoIteratorFlags);
    qint64 currentfoldersize = CalculateCurrentFolder(start_directory);
    (*map)[start_directory.absolutePath()] = currentfoldersize;

    while(it.hasNext())
    {
        it.next();
        QFileInfo inf = it.fileInfo();
        QString flpath = inf.filePath();
        if (!inf.isFile() && flpath.right(1) != "."){
            qint64 foldersize = CalculateFolderWeigth(QDir(it.filePath()));
            (*map)[flpath] = foldersize;
        }

    }
    return map;
}

qint64 ByFolderType_CalculationStrategy::CalculateFolderWeigth(QDir folder)
{
    qint64 weigth = 0;
    QDirIterator it(folder, QDirIterator::Subdirectories);

    while (it.hasNext())
    {
        it.next();
        QFileInfo inf = it.fileInfo();
        if (inf.isFile())
            weigth += inf.size();
    }

    return weigth;
}

qint64 ByFolderType_CalculationStrategy::CalculateCurrentFolder(QDir folder)
{
    qint64 weigth = 0;
    QDirIterator it(folder, QDirIterator::NoIteratorFlags);

    while (it.hasNext())
    {
        it.next();
        QFileInfo inf = it.fileInfo();
        if (inf.isFile())
            weigth += inf.size();
    }

    return weigth;
}
