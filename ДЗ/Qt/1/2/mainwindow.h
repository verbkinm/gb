#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene _scene;
    QGraphicsEllipseItem _itemAlpha;
    QGraphicsTextItem *_result;

private slots:
    void calculate();
};
