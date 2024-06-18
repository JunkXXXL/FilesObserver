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
#include "adapters.h"

int main(int argc, char *argv[]) {
    //content.example(dir);
    //content.test1(dir); // empty folder
    //content.test2(dir); //folder with files
    //content.test3(dir); //folder with folders

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}

int main1(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Создаем модельные данные и заполняем их
    Context *cont = new Context(STRATEGY::BYFOLDER);
    Adapter *adapter = new Adapter(cont);
    QList<StrategyInfo>* someDataModel = adapter->request("D://ANDwork//");
    //Создаем модель
    //QAbstractItemModel *tablemodel = new FileExplorerModel(nullptr, adapter);
    //Создаем представление QTableView
    QTableView *tableView = new QTableView;
    //Устанавливаем модель в представление
   // tableView->setModel(tablemodel);
    //Показываем представление
    tableView->show();

    delete cont;
    return app.exec();
}
