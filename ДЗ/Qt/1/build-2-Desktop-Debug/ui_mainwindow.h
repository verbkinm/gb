/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_degrees;
    QRadioButton *radioButton_radians;
    QSpinBox *spinBox_A;
    QGraphicsView *graphicsView;
    QSpinBox *spinBox_B;
    QLabel *label_2;
    QSpinBox *spinBox_Alpha;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(366, 342);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setScaledContents(false);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        radioButton_degrees = new QRadioButton(groupBox);
        radioButton_degrees->setObjectName(QString::fromUtf8("radioButton_degrees"));
        radioButton_degrees->setChecked(true);

        verticalLayout->addWidget(radioButton_degrees);

        radioButton_radians = new QRadioButton(groupBox);
        radioButton_radians->setObjectName(QString::fromUtf8("radioButton_radians"));

        verticalLayout->addWidget(radioButton_radians);


        gridLayout->addWidget(groupBox, 1, 2, 3, 1);

        spinBox_A = new QSpinBox(centralwidget);
        spinBox_A->setObjectName(QString::fromUtf8("spinBox_A"));
        spinBox_A->setAlignment(Qt::AlignCenter);
        spinBox_A->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_A->setMinimum(1);
        spinBox_A->setMaximum(999999999);

        gridLayout->addWidget(spinBox_A, 1, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 3);

        spinBox_B = new QSpinBox(centralwidget);
        spinBox_B->setObjectName(QString::fromUtf8("spinBox_B"));
        spinBox_B->setAlignment(Qt::AlignCenter);
        spinBox_B->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_B->setMinimum(1);
        spinBox_B->setMaximum(999999999);

        gridLayout->addWidget(spinBox_B, 2, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        spinBox_Alpha = new QSpinBox(centralwidget);
        spinBox_Alpha->setObjectName(QString::fromUtf8("spinBox_Alpha"));
        spinBox_Alpha->setAlignment(Qt::AlignCenter);
        spinBox_Alpha->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Alpha->setMinimum(1);
        spinBox_Alpha->setMaximum(999999999);

        gridLayout->addWidget(spinBox_Alpha, 3, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 366, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setTearOffEnabled(false);
        menu->setSeparatorsCollapsible(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt - \320\267\320\260\320\264\320\260\320\275\320\270\320\265 \342\204\2262", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "A:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\225\320\264\320\270\320\275\320\270\321\206\321\213 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217 \321\203\320\263\320\273\320\260:", nullptr));
        radioButton_degrees->setText(QCoreApplication::translate("MainWindow", "\320\263\321\200\320\260\320\264\321\203\321\201\321\213", nullptr));
        radioButton_radians->setText(QCoreApplication::translate("MainWindow", "\321\200\320\260\320\264\320\270\320\260\320\275\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "B:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\316\273:", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
