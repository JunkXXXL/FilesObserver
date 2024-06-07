#include "byfoldertype_calculationstrategy.h"

void ByFolderType_CalculationStrategy::SomeCalculationMethod(QDir start_directory)
{
    map.clear();
    unsigned int absolute_size = 0;
    QDirIterator it(start_directory, QDirIterator::NoIteratorFlags);
    map[start_directory.absolutePath()] = CalculateCurrentFolder(start_directory);

    while(it.hasNext())
    {
        it.next();
        QFileInfo inf = it.fileInfo();
        QString flpath = inf.filePath();
        if (!inf.isFile() && flpath.right(1) != "."){
            qint64 foldersize = CalculateFolderWeigth(QDir(it.filePath()));
            map[flpath] = foldersize;
            absolute_size += foldersize;
        }

    }


    QMapIterator<QString, unsigned int> iter(map);
    if (absolute_size != 0)
    {
        while (iter.hasNext())
        {
            iter.next();
            qDebug() << (float(map[iter.key()]) / absolute_size);
            if (map[iter.key()] == 0)
                percent[iter.key()] = 0;
            else
                percent[iter.key()] = ((float(map[iter.key()]) / absolute_size)*100 < 0.01)?0.01 :(float(map[iter.key()])*100 / absolute_size);
        }
    }
    else
    {
        while (iter.hasNext())
        {
            iter.next();
            percent[iter.key()] = 0;
        }
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
