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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditResult;
    QDoubleSpinBox *doubleSpinBoxA;
    QDoubleSpinBox *doubleSpinBoxB;
    QDoubleSpinBox *doubleSpinBoxC;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(316, 212);
        MainWindow->setMinimumSize(QSize(0, 212));
        MainWindow->setMaximumSize(QSize(16777215, 212));
        MainWindow->setWindowOpacity(1.000000000000000);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        lineEditResult = new QLineEdit(centralwidget);
        lineEditResult->setObjectName(QString::fromUtf8("lineEditResult"));
        lineEditResult->setAlignment(Qt::AlignCenter);
        lineEditResult->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditResult);

        doubleSpinBoxA = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxA->setObjectName(QString::fromUtf8("doubleSpinBoxA"));
        doubleSpinBoxA->setWrapping(false);
        doubleSpinBoxA->setAlignment(Qt::AlignCenter);
        doubleSpinBoxA->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxA->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBoxA->setMinimum(-9999999.000000000000000);
        doubleSpinBoxA->setMaximum(9999999.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBoxA);

        doubleSpinBoxB = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxB->setObjectName(QString::fromUtf8("doubleSpinBoxB"));
        doubleSpinBoxB->setWrapping(false);
        doubleSpinBoxB->setAlignment(Qt::AlignCenter);
        doubleSpinBoxB->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxB->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBoxB->setMinimum(-9999999.000000000000000);
        doubleSpinBoxB->setMaximum(9999999.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBoxB);

        doubleSpinBoxC = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxC->setObjectName(QString::fromUtf8("doubleSpinBoxC"));
        doubleSpinBoxC->setWrapping(false);
        doubleSpinBoxC->setAlignment(Qt::AlignCenter);
        doubleSpinBoxC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxC->setKeyboardTracking(true);
        doubleSpinBoxC->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBoxC->setMinimum(-9999999.000000000000000);
        doubleSpinBoxC->setMaximum(9999999.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxC);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 316, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt - \320\267\320\260\320\264\320\260\320\275\320\270\320\265 \342\204\2261", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "a:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "b:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "c:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
        doubleSpinBoxA->setSpecialValueText(QString());
        doubleSpinBoxB->setSpecialValueText(QString());
        doubleSpinBoxC->setSpecialValueText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">ax</span><span style=\" font-size:14pt; vertical-align:super;\">2 </span><span style=\" font-size:14pt;\">+ bx + c = 0 </span></p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
