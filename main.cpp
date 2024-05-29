#include "qdiriterator.h"
#include "QDebug"


int main(int argc, char *argv[])
{
    QDirIterator it("D:/ANDwork", QDirIterator::Subdirectories);

    unsigned int size = 0;
    while (it.hasNext())
    {
        QString str = it.next();
        QFileInfo inf = it.fileInfo();
        QString names = it.filePath();
        if (inf.isFile())
        {
            //qDebug() << inf.fileName();
            size += inf.size();
        }
    }
    qDebug() << size;

    return 0;
}
