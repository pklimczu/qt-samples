#pragma once

#include <QMainWindow>
#include <QTableView>
#include <QAbstractItemModel>
#include "TableModel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private:
    void createActions();
    void setupTableView();
    void setupModel();

    void _resizeTableView();

    QTableView *m_pTableView;
    TableModel *m_pModel;
};
