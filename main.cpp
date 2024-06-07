#include "qdiriterator.h"
#include "QDebug"
#include "content.h"
#include "calculationstrategy.h"

int main(int argc, char *argv[])
{
    Content content(CalculationStrategy::BYFOLDER);
    QString dir = "D:/FilesObserver/";
    content.example(dir);
    //content.test1(dir); // empty folder
    //content.test2(dir); //folder with files
    //content.test3(dir); //folder with folders

    return 0;
}

