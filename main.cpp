#include "qdiriterator.h"
#include "QDebug"
#include "context.h"
#include "calculationstrategy.h"
#include "QFileSystemModel"
#include "QTreeView"
#include "QApplication"
#include "QListView"
#include "QLabel"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    Context content(STRATEGY::BYFOLDER);
    QString dir = "D:/FilesObserver/";
    //content.example(dir);
    //content.test1(dir); // empty folder
    //content.test2(dir); //folder with files
    //content.test3(dir); //folder with folders

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
