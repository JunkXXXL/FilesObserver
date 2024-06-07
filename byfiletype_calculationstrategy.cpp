#include "byfiletype_calculationstrategy.h"

void ByFileType_CalculationStrategy::SomeCalculationMethod(QDir start_directory)
{
    map.clear();
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
            (map[format]) += inf.size();
        }
    }
}
