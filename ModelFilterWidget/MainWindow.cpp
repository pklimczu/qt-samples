#include "MainWindow.h"
#include <QtWidgets>

MainWindow::MainWindow()
{
    m_pTableView = new QTableView(this);
    setCentralWidget(m_pTableView);
    createActions();
    setupModel();
    setFixedSize(600,500);
    _resizeTableView();
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&Filter"));
    QList<QAction*> actionList;
    actionList.append(new QAction("Green ones", this));
    actionList.append(new QAction("Red ones", this));
    actionList.append(new QAction("Blue ones", this));

    for (auto * action : actionList)
    {
        action->setCheckable(true);
        fileMenu->addAction(action);
    }
}

void MainWindow::setupTableView()
{
    m_pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::setupModel()
{
    m_pModel = new TableModel();
    m_pModel->setHeaderData(0, Qt::Orientation::Horizontal, QVariant("Test"));
    m_pTableView->setModel(m_pModel);
}

void MainWindow::_resizeTableView()
{
    for (int c = 0; c < m_pTableView->horizontalHeader()->count(); c++)
    {
        m_pTableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
}
