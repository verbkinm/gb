#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model.appendRow(new QStandardItem(QIcon(":/img/cpp.png"), "C++"));
    _model.appendRow(new QStandardItem(QIcon(":/img/csharp.png"), "C#"));
    _model.appendRow(new QStandardItem(QIcon(":/img/java.png"), "Java"));
    _model.appendRow(new QStandardItem(QIcon(":/img/php.png"), "PHP"));
    _model.appendRow(new QStandardItem(QIcon(":/img/python.png"), "Python"));
    _model.appendRow(new QStandardItem(QIcon(":/img/js.png"), "JavaScript"));

    ui->listView->setModel(&_model);

    ui->listView->setDragDropMode(QAbstractItemView::InternalMove);
    ui->listView->setDragEnabled(true);
    ui->listView->setDragDropOverwriteMode(false);
    ui->listView->setDropIndicatorShown(true);
    ui->listView->setDefaultDropAction(Qt::IgnoreAction);
    ui->listView->setAlternatingRowColors(true);
    ui->listView->setMovement(QListView::Free);
    ui->listView->setIconSize(QSize(16, 16));
    ui->listView->setLayoutMode(QListView::Batched);
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->checkBoxMode, &QCheckBox::toggled, this, &MainWindow::iconModeSet);

    connect(ui->pushButtonDelete, &QPushButton::clicked, this, &MainWindow::deleteItem);
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::insertItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iconModeSet(bool state)
{
    if (state)
        ui->listView->setViewMode(QListView::IconMode);
    else
        ui->listView->setViewMode(QListView::ListMode);
}

void MainWindow::deleteItem()
{
    auto item =  ui->listView->currentIndex();
    if (item.column() != -1)
        _model.removeRow(item.row());
}

void MainWindow::insertItem()
{
    _model.appendRow(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)), "Строка с файлом"));
}


