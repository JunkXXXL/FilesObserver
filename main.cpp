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
#include "fileexplorermodel.h""
#include "QTableView"

int main1(int argc, char *argv[]) {
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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Создаем модельные данные и заполняем их
    QList<SomeData> someDataModel;
    someDataModel.append(SomeData("*.pdf", "3021", "%?"));
    someDataModel.append(SomeData("*.doc", "5060", "%?"));
    someDataModel.append(SomeData("*.txt", "4500", "%?"));
    someDataModel.append(SomeData("*.exe", "23784", "%?"));
    someDataModel.append(SomeData("others", "3045", "%?"));
    //Создаем модель
    QAbstractItemModel *tablemodel = new FileExplorerModel(nullptr, someDataModel);
    //Создаем представление QTableView
    QTableView *tableView = new QTableView;
    //Устанавливаем модель в представление
    tableView->setModel(tablemodel);
    //Показываем представление
    tableView->show();
    return app.exec();
}
