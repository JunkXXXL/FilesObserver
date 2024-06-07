#include "byfoldertype_calculationstrategy.h"

void ByFolderType_CalculationStrategy::SomeCalculationMethod(QDir start_directory)
{
    map.clear();
    QDirIterator it(start_directory, QDirIterator::NoIteratorFlags);
    map[start_directory.absolutePath()] = CalculateCurrentFolder(start_directory);

    while(it.hasNext())
    {
        it.next();
        QFileInfo inf = it.fileInfo();
        QString flpath = inf.filePath();
        qDebug() << flpath.right(1);
        if (!inf.isFile() && flpath.right(1) != ".")
            map[flpath] = CalculateFolderWeigth(QDir(it.filePath()));
    }
}

unsigned int ByFolderType_CalculationStrategy::CalculateFolderWeigth(QDir folder)
{
    unsigned int weigth = 0;
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

unsigned int ByFolderType_CalculationStrategy::CalculateCurrentFolder(QDir folder)
{
    unsigned int weigth = 0;
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
