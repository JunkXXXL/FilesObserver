#include "byfiletype_calculationstrategy.h"

void ByFileType_CalculationStrategy::SomeCalculationMethod(QDir start_directory)
{
    map.clear();
    unsigned int absolute_size = 0;
    QDirIterator it(start_directory, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString str = it.next();
        QFileInfo inf = it.fileInfo();
        QString names = it.filePath();
        if (inf.isFile())
        {
            QString file_path = inf.filePath();
            QString format;
            int last_elements;

            auto dot_position = file_path.lastIndexOf(".");
            if (dot_position != -1)
            {   last_elements = file_path.length() - dot_position;
                format = file_path.right(last_elements);
            }
            else
            {
                format = "no format";
            }
            qint64 size = inf.size();
            (map[format]) += size;
            absolute_size += size;
        }
    }

    QMapIterator<QString, unsigned int> iter(map);
    if (absolute_size != 0)
    {
        while (iter.hasNext())
        {
            iter.next();
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
