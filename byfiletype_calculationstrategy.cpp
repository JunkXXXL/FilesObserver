#include "byfiletype_calculationstrategy.h"

QMap<QString, qint64>* ByFileType_CalculationStrategy::SomeCalculationMethod(QDir start_directory)
{
    QMap<QString, qint64>* map = new QMap<QString, qint64>();
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
            (*map)[format] += size;
        }
    }
    return map;
}
