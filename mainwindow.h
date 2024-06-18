#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include "fileexplorermodel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
private slots:

	void on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected);

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
    QAbstractItemModel *fileModel;
	QFileSystemModel *dirModel;
	QTreeView *treeView;
	QTableView *tableView;
};

#endif // MAINWINDOW_H
