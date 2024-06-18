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

Widget::Widget(QWidget *parent)
	: //QWidget(parent)
      QWidget(parent)
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

    cont = new Context(STRATEGY::BYFOLDER);

    connect(treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &Widget::on_selectionChangedSlot);
    connect(strategyBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &Widget::setStrategy);










//    Context *cont = new Context(STRATEGY::BYFOLDER);
//    Adapter *adapter = new Adapter(cont);
//    QList<StrategyInfo>* someDataModel = adapter->request("D://ANDwork//");

//    fileModel = new FileExplorerModel(this, adapter);//QFileSystemModel(this);d
    //fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

 //   fileModel->setRootPath(homePath);
	//Показать как дерево, пользуясь готовым видом:



//	treeView->expandAll();
//	QSplitter *splitter = new QSplitter(parent);
//	tableView = new QTableView;
//    tableView->setModel(fileModel);
//	splitter->addWidget(treeView);
//	splitter->addWidget(tableView);
//	setCentralWidget(splitter);

//	QItemSelectionModel *selectionModel = treeView->selectionModel();
//	QModelIndex rootIx = dirModel->index(0, 0, QModelIndex());//корневой элемент

//	QModelIndex indexHomePath = dirModel->index(homePath);
//	QFileInfo fileInfo = dirModel->fileInfo(indexHomePath);

	/* Рассмотрим способы обхода содержимого папок на диске.
	 * Предлагается вариант решения, которы может быть применен для более сложных задач.
	 * Итак, если требуется выполнить анализ содержимого папки, то необходимо организовать обход содержимого. Обход выполняем относительно модельного индекса.
	 * Например:*/
//	if (fileInfo.isDir()) {
//		/*
//		 * Если fileInfo папка то заходим в нее, что бы просмотреть находящиеся в ней файлы.
//		 * Если нужно просмотреть все файлы, включая все вложенные папки, то нужно организовать рекурсивный обход.
//		*/
//		QDir dir  = fileInfo.dir();

//		if (dir.cd(fileInfo.fileName())) {
//			/**
//			 * Если зашли в папку, то пройдемся по контейнеру QFileInfoList ,полученного методом entryInfoList,
//			 * */

//			foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Type)) {
//				qDebug() << inf.fileName() << "---" << inf.size();
//			}

//			dir.cdUp();//выходим из папки
//		}
//	}

//	QDir dir = fileInfo.dir();

//	foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Type)) {

//		qDebug() << inf.fileName() << "---" << inf.size();
//	}


    //treeView->header()->resizeSection(0, 200);
	//Выполняем соединения слота и сигнала который вызывается когда осуществляется выбор элемента в TreeView
//	connect(treeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
//			this, SLOT(on_selectionChangedSlot(const QItemSelection &, const QItemSelection &)));


	//Пример организации установки курсора в TreeView относит ельно модельного индекса
//	QItemSelection toggleSelection;
//	QModelIndex topLeft;
//	topLeft = dirModel->index(homePath);
//	dirModel->setRootPath(homePath);

//	toggleSelection.select(topLeft, topLeft);
//	selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);
}
//Слот для обработки выбора элемента в TreeView
//выбор осуществляется с помощью курсора

void Widget::setStrategy(int index)
{
    qDebug() << "set strategy index:" << index;


    cont->setNewStrategy((STRATEGY)index);
    on_selectionChangedSlot(QItemSelection(), QItemSelection());




}

void Widget::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
	//Q_UNUSED(selected);
	Q_UNUSED(deselected);
	QModelIndex index = treeView->selectionModel()->currentIndex();
    QString filePath = dirModel->filePath(index);

    qDebug()<< filePath;

    if(filePath != "")
        tableModel->update(cont->useStrategy(filePath));

    /*QModelIndexList indexs =  selected.indexes();
	QString filePath = "";

	// Размещаем инфо в statusbar относительно выделенного модельного индекса

	if (indexs.count() >= 1) {
		QModelIndex ix =  indexs.constFirst();
		filePath = dirModel->filePath(ix);
		this->statusBar()->showMessage("Выбранный путь : " + dirModel->filePath(indexs.constFirst()));
	}

	//TODO: !!!!!
	/*
	Тут простейшая обработка ширины первого столбца относительно длины названия папки.
	Это для удобства, что бы при выборе папки имя полностью отображалась в  первом столбце.
	Требуется доработка(переработка).
	*/
/*	int length = 200;
	int dx = 30;

	if (dirModel->fileName(index).length() * dx > length) {
		length = length + dirModel->fileName(index).length() * dx;
		qDebug() << "r = " << index.row() << "c = " << index.column() << dirModel->fileName(index) << dirModel->fileInfo(
					 index).size();

	}

//	treeView->header()->resizeSection(index.column(), length + dirModel->fileName(index).length());
/   //tableView->setRootIndex(fileModel->setRootPath(filePath)); // const QModelIndex&
//    fileModel->setRootPath(filePath);
//    fileModel->update();
//    tableView->setModel(fileModel);
//    //QAbstractItemModel a;
//    QTableView a;
*/


}

Widget::~Widget()
{
    delete cont;
}
