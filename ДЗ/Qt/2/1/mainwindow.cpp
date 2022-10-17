#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::slotChangeText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotChangeText()
{
    disconnect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::slotChangeText);

    QString str = ui->plainTextEdit->toPlainText();
    if (ParseText::isParsing(str))
    {
        auto pair = ParseText::parse(str);
        int curPos = ui->plainTextEdit->textCursor().position();
        int sub = str.length() - pair.second.length();
        ui->plainTextEdit->setPlainText(pair.second);

        if (sub <= 0)
            ui->plainTextEdit->textCursor().setPosition(pair.second.length() - 1);
        else
        {
            auto textCursor = ui->plainTextEdit->textCursor();
            textCursor.setPosition(curPos - sub);
            ui->plainTextEdit->setTextCursor(textCursor);
        }
    }

    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::slotChangeText);
}

