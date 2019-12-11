#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    server(this)
{
    ui->setupUi(this);

    connect(&server, &Server::newMessage,
            ui->textEdit, &QTextEdit::append);
    connect(ui->pushButton, &QPushButton::clicked,
            ui->textEdit, &QTextEdit::clear);

    server.run();
    ui->textEdit->append(server.getPort());
}

MainWindow::~MainWindow()
{
    delete ui;
}
