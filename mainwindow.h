#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include "fileexplorermodel.h"
#include <QComboBox>
#include "context.h"

class Widget : public QWidget
{
	Q_OBJECT
private slots:

	void on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected);
    void setStrategy(int index);

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    FileExplorerModel *fileModel;
	QFileSystemModel *dirModel;
	QTreeView *treeView;
	QTableView *tableView;
    QComboBox *strategyBox;
    Context* cont;
    FileExplorerModel* tableModel;

};

#endif // MAINWINDOW_H
