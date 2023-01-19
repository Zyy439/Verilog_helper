#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //set up ui
    ui->setupUi(this);

    //fix the window title
    this->setWindowTitle("Register Manager");

    //initiallize the row number as 0
    this->row_number = 0;

    //signal connection
    connect(ui->pushButton_exit,&QPushButton::clicked,this,&MainWindow::close);
    connect(ui->pushButton_add,&QPushButton::clicked,this,&MainWindow::add_signal);
    connect(ui->pushButton_minus,&QPushButton::clicked,this,&MainWindow::minus_signal);
    connect(ui->pushButton_clear,&QPushButton::clicked,this,&MainWindow::clear_signal);
    connect(ui->actionVerilog,&QAction::triggered,this,&MainWindow::generate_verilog_file);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_signal(){

    //add a row in the table widget
    ui->TableWidget_register->insertRow(row_number);

    //update the address for every row in the table
    for (unsigned int i=0;i<=MainWindow::row_number;i++)
    {
        QTableWidgetItem *signal_address = new QTableWidgetItem;
        signal_address->setText("9'h" + QString::number(i*4,16));

        //allocate address to the newly defined signal
        ui->TableWidget_register->setItem(i,0,signal_address);
    }

    //allocate a combobox for every row in the tablewidget
    for (unsigned int i=0;i<=MainWindow::row_number;i++)
    {
        QComboBox *rdselect = new QComboBox;
        rdselect->addItems({"read only","read / write"});
        //add this combobox to the newly inserted row
        ui->TableWidget_register->setCellWidget(i,3,rdselect);
    }

    //update the row number and then exhibit it in the register number label
    this->row_number ++;
    ui->label_register_number->setText("Register Number :  " + QString::number(this->row_number));

    //debug output
    qDebug()<<"the slot add_signal is successfully enabled"<<endl;
    qDebug()<<"the number of the  signal at the moment is : " + QString::number(this->row_number)<<endl;

}


void MainWindow::minus_signal(){

    //delete a row in the table widget
    ui->TableWidget_register->removeRow(ui->TableWidget_register->currentRow());

    //update the row number and then exhibit it in the register number label
    MainWindow::row_number --;
    ui->label_register_number->setText("Register Number :  " + QString::number(this->row_number));

    //debug output
    qDebug()<<"the slot minus_signal is successfully enabled"<<endl;
    qDebug()<<"the number of the  signal at the moment is : " + QString::number(this->row_number)<<endl;

}


void MainWindow::clear_signal(){

    //delete all rows
    while(MainWindow::row_number > 0)
    {
        ui->TableWidget_register->removeRow(MainWindow::row_number);
        MainWindow::row_number --;
    }

    //delete the last row when row number equals zero
    ui->TableWidget_register->removeRow(MainWindow::row_number);

    //exhibit the row number in the label
    ui->label_register_number->setText("Register Number :  " + QString::number(this->row_number));

    //debug output
    qDebug()<<"the slot clear_signal is successfully enabled"<<endl;
    qDebug()<<"the number of the  signal at the moment is : " + QString::number(this->row_number)<<endl;

}


void MainWindow::generate_verilog_file(){

    //user needs to select a file path
    QString FilePath = QFileDialog::getExistingDirectory(this,tr("select file path"),tr("verilog(*.v)"));
    QFile verilog_file(FilePath + "/CtrlReg.v");

    //if file already exists we then delete it first
    if(!verilog_file.exists())
    {
        verilog_file.open(QFile::WriteOnly|QFile::Text|QIODevice::Append);
    }
    else
    {
        QFile::remove(FilePath + "/CtrlReg.v");
        verilog_file.open(QFile::WriteOnly|QFile::Text|QIODevice::Append);
    }

    //create a text adder
    QTextStream verilog_stream(&verilog_file);

    //=====================================================================
    //                 start adding text to the file
    //=====================================================================
    verilog_stream<<"testtest"<<endl;

    //debug output
    qDebug()<<"generate verilog file action successfully enabled！"<<endl;
    qDebug()<<FilePath<<endl;

}
