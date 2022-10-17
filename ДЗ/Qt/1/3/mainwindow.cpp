#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonAdd, &QPushButton::clicked, this, [this](){
        ui->plainTextEditRight->appendPlainText(ui->plainTextEditLeft->toPlainText());
    });
    connect(ui->pushButtonReplace, &QPushButton::clicked, this, [this](){
        ui->plainTextEditRight->setPlainText(ui->plainTextEditLeft->toPlainText());
    });
    connect(ui->pushButtonHtml, &QPushButton::clicked, this, [this](){
        ui->plainTextEditRight->clear();
        ui->plainTextEditRight->appendHtml("<font color='red'>Hello Qt!</font>");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

