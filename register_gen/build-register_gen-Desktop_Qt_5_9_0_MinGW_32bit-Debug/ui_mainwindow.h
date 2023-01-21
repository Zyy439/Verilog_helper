/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUser_guide;
    QAction *actionImport_Excel;
    QAction *actionExcel;
    QAction *actionVerilog;
    QWidget *centralWidget;
    QTableWidget *TableWidget_register;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_add;
    QLabel *label_register_number;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(662, 686);
        MainWindow->setMinimumSize(QSize(662, 686));
        MainWindow->setMaximumSize(QSize(662, 686));
        actionUser_guide = new QAction(MainWindow);
        actionUser_guide->setObjectName(QStringLiteral("actionUser_guide"));
        actionImport_Excel = new QAction(MainWindow);
        actionImport_Excel->setObjectName(QStringLiteral("actionImport_Excel"));
        actionExcel = new QAction(MainWindow);
        actionExcel->setObjectName(QStringLiteral("actionExcel"));
        actionVerilog = new QAction(MainWindow);
        actionVerilog->setObjectName(QStringLiteral("actionVerilog"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TableWidget_register = new QTableWidget(centralWidget);
        if (TableWidget_register->columnCount() < 5)
            TableWidget_register->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableWidget_register->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableWidget_register->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableWidget_register->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TableWidget_register->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TableWidget_register->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        TableWidget_register->setObjectName(QStringLiteral("TableWidget_register"));
        TableWidget_register->setGeometry(QRect(10, 50, 641, 521));
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(540, 580, 111, 20));
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(540, 20, 111, 21));
        pushButton_minus = new QPushButton(centralWidget);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(490, 20, 31, 21));
        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(450, 20, 31, 21));
        label_register_number = new QLabel(centralWidget);
        label_register_number->setObjectName(QStringLiteral("label_register_number"));
        label_register_number->setGeometry(QRect(10, 20, 251, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 662, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImport_Excel);
        menuFile->addAction(menuExport->menuAction());
        menuExport->addAction(actionExcel);
        menuExport->addAction(actionVerilog);
        menuHelp->addAction(actionUser_guide);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionUser_guide->setText(QApplication::translate("MainWindow", "User guide", Q_NULLPTR));
        actionImport_Excel->setText(QApplication::translate("MainWindow", "Import Excel", Q_NULLPTR));
        actionExcel->setText(QApplication::translate("MainWindow", "Excel", Q_NULLPTR));
        actionVerilog->setText(QApplication::translate("MainWindow", "Verilog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = TableWidget_register->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = TableWidget_register->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Signal name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = TableWidget_register->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Width", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = TableWidget_register->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Inout", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = TableWidget_register->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Annotation", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        label_register_number->setText(QApplication::translate("MainWindow", "Register Number :", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
