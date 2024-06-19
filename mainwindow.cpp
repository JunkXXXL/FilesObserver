#include "mainwindow.h"
#include <QSplitter>
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>
#include <QDebug>
#include "QHBoxLayout"
#include "QComboBox"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
	//Устанавливаем размер главного окна
	this->setGeometry(100, 100, 1500, 500);

	// Определим  файловой системы:
    strategyBox = new QComboBox();
    strategyBox->addItems({"BYFOLDER", "BYFILETYPE"});

    QHBoxLayout* hbox1 = new QHBoxLayout();
    hbox1->addStretch();
    hbox1->addWidget(strategyBox);

    QString homePath = QDir::homePath();
    dirModel =  new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(homePath);

    treeView = new QTreeView(this);
    treeView->setModel(dirModel);

    tableView = new QTableView(this);
    tableModel = new FileExplorerModel(this);
    tableView->setModel(tableModel);

    QHBoxLayout* hbox2 = new QHBoxLayout();
    hbox2->addWidget(treeView);
    hbox2->addWidget(tableView);

    QVBoxLayout* vBox = new QVBoxLayout(this);
    vBox->addLayout(hbox1);
    vBox->addLayout(hbox2);

    calculationStrategy = new ByFolderType_CalculationStrategy();

    cont = new Context(calculationStrategy);

    connect(treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &Widget::on_selectionChangedSlot);
    connect(strategyBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &Widget::setStrategy);
}

void Widget::setStrategy(int index)
{
    if (index == 1)
    {
        calculationStrategy = new ByFileType_CalculationStrategy();
    }
    else
    {
        calculationStrategy = new ByFolderType_CalculationStrategy();
    }
    cont->setNewStrategy(calculationStrategy);
    on_selectionChangedSlot(QItemSelection(), QItemSelection());
}

void Widget::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
	Q_UNUSED(deselected);
	QModelIndex index = treeView->selectionModel()->currentIndex();
    QString filePath = dirModel->filePath(index);

    qDebug()<< filePath;

    if(filePath != "")
        tableModel->update(cont->useStrategy(filePath));

}

Widget::~Widget()
{
    delete cont;
    delete calculationStrategy;
}
