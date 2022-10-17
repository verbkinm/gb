#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _itemAlpha(-125, -25, 50, 50), _result(nullptr)
{
    ui->setupUi(this);

    QPolygonF triangle;
    triangle.append(QPointF(-100.,0));
    triangle.append(QPointF(0.,-100));
    triangle.append(QPointF(100.,0));
    triangle.append(QPointF(-100.,0));

    QGraphicsItem *itemA = _scene.addText("A");
    itemA->setPos(-60, -80);
    QGraphicsItem *itemB = _scene.addText("B");
    itemB->setPos(-10, 0);
    QGraphicsItem *itemAlpha = _scene.addText("λ");
    itemAlpha->setPos(-75, -25);
    _scene.addPolygon(triangle);

    _itemAlpha.setStartAngle(0);
    _itemAlpha.setSpanAngle(360 * 2);
    _scene.addItem(&_itemAlpha);

    ui->graphicsView->setScene(&_scene);

    _result = _scene.addText("?");
    _result->setPos(60, -80);

    connect(ui->spinBox_A, SIGNAL(valueChanged(int)), SLOT(calculate()));
    connect(ui->spinBox_B, SIGNAL(valueChanged(int)), SLOT(calculate()));
    connect(ui->spinBox_Alpha, SIGNAL(valueChanged(int)), SLOT(calculate()));
    connect(ui->radioButton_degrees, SIGNAL(toggled(bool)), SLOT(calculate()));
    connect(ui->radioButton_radians, SIGNAL(toggled(bool)), SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    double a, b, c, alpha;

    a = ui->spinBox_A->value();
    b = ui->spinBox_B->value();
    alpha = ui->spinBox_Alpha->value();

    if (ui->radioButton_degrees->isChecked())
        alpha = alpha * M_PI / 180.0;

    c = std::sqrt(std::pow(a, 2) + std::pow(b, 2) - 2 * a * b * std::cos(alpha));

    _result->setPlainText(QString::number(c));
}

