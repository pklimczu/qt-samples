#pragma once

#include <QMainWindow>
#include <QTableView>
#include <QLineEdit>
#include <QAbstractItemModel>
#include "FilterProxy.h"
#include "TableModel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    void onGreenFilterChanged(bool isChecked);
    void onRedFilterChanged(bool isChecked);
    void onBlueFilterChanged(bool isChecked);

private:
    void _createActions();
    void _setupTableView();
    void _setupLineEdit();
    void _setupModel();

    void _resizeTableView();

    void _updateFilter(bool isChecked, const QString& color);
    void _updateModel();

    QLineEdit *m_pLineEdit;
    QTableView *m_pTableView;
    TableModel *m_pModel;
    FilterProxy *m_pProxy;
};
