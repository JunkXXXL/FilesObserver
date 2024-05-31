#include "qdiriterator.h"
#include "QDebug"


int main1(int argc, char *argv[])
{
    QDirIterator it("D:/ANDwork", QDirIterator::Subdirectories);

    QMap<QString, unsigned int> map;
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

            map[format] = inf.size();
        }
    }

    QMapIterator<QString, unsigned int> iter(map);
    while (iter.hasNext())
    {
        iter.next();
        qDebug() << iter.key() << ": " << iter.value();
    }

    return 0;
}

int main(int argc, char *argv[])
{
    QDirIterator it("D:/ANDwork", QDirIterator::Subdirectories);

    QMap<QString, unsigned int> map;
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

            map[format] += inf.size();
        }
    }

    QMapIterator<QString, unsigned int> iter(map);
    while (iter.hasNext())
    {
        iter.next();
        qDebug() << iter.key() << ": " << iter.value();
    }

    return 0;
}

