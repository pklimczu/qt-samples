#include "MainWindow.h"
#include <QtWidgets>

MainWindow::MainWindow()
{
    m_pTableView = new QTableView(this);
    m_pLineEdit = new QLineEdit(this);
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_pLineEdit);
    layout->addWidget(m_pTableView);
    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);
    _createActions();
    _setupLineEdit();
    _setupModel();
    resize(600,500);
    _resizeTableView();
}

void MainWindow::onGreenFilterChanged(bool isChecked)
{
    QString toFilter = "green";
    _updateFilter(isChecked, toFilter);
}

void MainWindow::onRedFilterChanged(bool isChecked)
{
    QString toFilter = "red";
    _updateFilter(isChecked, toFilter);
}

void MainWindow::onBlueFilterChanged(bool isChecked)
{
    QString toFilter = "blue";
    _updateFilter(isChecked, toFilter);
}

void MainWindow::_createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&Filter"));
    QList<QAction*> actionList;
    actionList.append(new QAction("Green ones", this));
    actionList.append(new QAction("Red ones", this));
    actionList.append(new QAction("Blue ones", this));

    // Not the best idea however but enough for this sample:
    connect(actionList[0], &QAction::toggled, this, &MainWindow::onGreenFilterChanged);
    connect(actionList[1], &QAction::toggled, this, &MainWindow::onRedFilterChanged);
    connect(actionList[2], &QAction::toggled, this, &MainWindow::onBlueFilterChanged);

    for (auto * action : actionList)
    {
        action->setCheckable(true);
        fileMenu->addAction(action);
    }
}

void MainWindow::_setupTableView()
{
    m_pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::_setupLineEdit()
{
    m_pLineEdit->setPlaceholderText("path to file with data");
    m_pLineEdit->setText("/home/pklimczu/Projekty/Qt/ModelFilterWidget/test_data.csv");
    connect(m_pLineEdit, &QLineEdit::editingFinished,
            this, &MainWindow::_updateModel);
}

void MainWindow::_setupModel()
{
    m_pModel = new TableModel();
    m_pProxy = new FilterProxy(this);
    m_pProxy->setSourceModel(m_pModel);
    m_pTableView->setModel(m_pProxy);
}

void MainWindow::_resizeTableView()
{
    for (int c = 0; c < m_pTableView->horizontalHeader()->count(); c++)
    {
        m_pTableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
}

void MainWindow::_updateFilter(bool isChecked, const QString &color)
{
    isChecked ? m_pProxy->addStringToBeFiltred(color)
              : m_pProxy->removeStringFromBeingFiltred(color);
}

void MainWindow::_updateModel()
{
    m_pModel->readData(m_pLineEdit->text());
}
