#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->doubleSpinBoxA, SIGNAL(valueChanged(double)), SLOT(calculate()));
    connect(ui->doubleSpinBoxB, SIGNAL(valueChanged(double)), SLOT(calculate()));
    connect(ui->doubleSpinBoxC, SIGNAL(valueChanged(double)), SLOT(calculate()));

    calculate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    double a = ui->doubleSpinBoxA->value(),
            b = ui->doubleSpinBoxB->value(),
            c = ui->doubleSpinBoxC->value();

    if (a == 0)
    {
        ui->lineEditResult->setText("Not a quadratic equation!");
        return;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        ui->lineEditResult->setText("Root 1, 2: " + QString::number(x1) + ", " + QString::number(x2));
    }
    else if (discriminant == 0)
    {
        double x = (-b + std::sqrt(discriminant))  / (2 * a);
        ui->lineEditResult->setText("Root: " + QString::number(x));
    }
    else
        ui->lineEditResult->setText("Complex scenario is not supported!");

}

