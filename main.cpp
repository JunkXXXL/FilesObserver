#include "QDebug"
#include "context.h"
#include "QFileSystemModel"
#include "QTreeView"
#include "QApplication"
#include "QListView"
#include "QLabel"
#include "mainwindow.h"
#include "fileexplorermodel.h"
#include "QTableView"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
