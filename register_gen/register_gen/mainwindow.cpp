#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

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
    connect(ui->actionExcel,&QAction::triggered,this,&MainWindow::generate_excel_file);
    connect(ui->actionUser_guide,&QAction::triggered,this,&MainWindow::user_guide_action);
    connect(ui->actionImport_Excel,&QAction::triggered,this,&MainWindow::import_excel_file);
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


    /*
    //allocate a combobox for every row in the tablewidget
    for (unsigned int i=0;i<=MainWindow::row_number;i++)
    {
        QComboBox *rdselect = new QComboBox;
        rdselect->addItems({"read only","read / write"});
        //add this combobox to the newly inserted row
        ui->TableWidget_register->setCellWidget(i,3,rdselect);
    }
    */

    //allocate a combobox for the new row in the tablewidget
    QComboBox *rdselect = new QComboBox;
    QStringList list;
    list.append("read only");
    list.append("read / write");
    rdselect->addItems(list);
    ui->TableWidget_register->setCellWidget(MainWindow::row_number,3,rdselect);

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
        //return;
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

    //time accuracy
    verilog_stream<<"`resetall"<<endl;
    verilog_stream<<"`timescale 1ns/10ps"<<endl;
    verilog_stream<<endl;

    //---------------------------------------------------------------------
    //port declaration
    verilog_stream<<"module CtrlReg("<<endl;

    for(int i=0;i<ui->TableWidget_register->rowCount()-1;i++){

        //obtain the in/out info from the table widget
        QComboBox *combobox_p = (QComboBox*)ui->TableWidget_register->cellWidget(i,3);
        QString inout_string = combobox_p->currentText();

        if("read only" == inout_string){
            verilog_stream  <<  "   input   ";
        }
        else{
            verilog_stream  <<  "   output  ";
        }
        verilog_stream  <<"["+QString::number(ui->TableWidget_register->model()->index(i,2).data().toInt()-1)+":0]   "
                        <<ui->TableWidget_register->model()->index(i,1).data().toString()<<" ,"<<endl;
    }

    //the last signal does not need a comma
    QComboBox *combobox_p = (QComboBox*)ui->TableWidget_register->cellWidget(ui->TableWidget_register->rowCount()-1,3);
    QString inout_string = combobox_p->currentText();

    if("read only" == inout_string){
        verilog_stream  <<  "   input   ";
    }
    else{
        verilog_stream  <<  "   output  ";
    }

    verilog_stream  <<"["+QString::number(ui->TableWidget_register->model()->index(ui->TableWidget_register->rowCount()-1,2).data().toInt()-1)+":0]   "
                    <<ui->TableWidget_register->model()->index(ui->TableWidget_register->rowCount()-1,1).data().toString()<<endl;

    //end of port declaration
    verilog_stream<<");"<<endl;


    //---------------------------------------------------------------------
    //signal define

    //---------------------------------------------------------------------
    //message box to inform that a verilog file has been successfully generated
    QMessageBox::information(this,"verilog generator","verilog file successfully generated","confirm");

    //debug output
    qDebug()<<"generate verilog file action successfully enabled！"<<endl;
    qDebug()<<FilePath<<endl;

}

void MainWindow::generate_excel_file(){
    QString path = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),tr("Files (*.csv)"));
    QFile file(path);
        bool ret = file.open(QIODevice::Truncate | QIODevice::ReadWrite);
        if(!ret)
        {
            qDebug() << "open failure";
            return;
        }

        QTextStream stream(&file);
        QString conTents;
        // tabel head insert
//        QHeaderView * header = ui->TableWidget_register->horizontalHeader() ;
//        if (NULL != header)
//        {
//            for (int i = 0; i < header->count(); i++)
//            {
//                QTableWidgetItem *item = ui->TableWidget_register->horizontalHeaderItem(i);
//                if (NULL != item)
//                {
//                    conTents += item->text() + ",";
//                }
//            }
//            conTents += "\n";
//        }

        // 写内容
        for (int row = 0; row < ui->TableWidget_register->rowCount(); row++)
        {
            for (int column = 0; column < ui->TableWidget_register->columnCount(); column++)
            {
                if(column != 3){
                    QTableWidgetItem* item = ui->TableWidget_register->item(row, column);
                    if (NULL != item )
                    {
                        QString str;
                        str = item->text();
                        str.replace(","," ");
                        conTents += str + ",";
                    }
                }
                else{
                    auto cellWidget = ui->TableWidget_register->cellWidget(row,3);
                    QComboBox *combox=(QComboBox*)cellWidget;
                    if(combox->count() == 0){
                        return;
                    }
                    QString str = combox->currentText();
                    conTents += str + ",";
                }
            }
            conTents += "\n";
        }
        stream << conTents;

        file.close();

        //message box to inform that an excel file has been successfully generated
        QMessageBox::information(this,"excel generator","excel file successfully generated","confirm");

        //debug output
        qDebug()<<"generate excel file action successfully enabled！"<<endl;
        return;
}

void MainWindow::import_excel_file(){


    QFileDialog* fd = new QFileDialog(this);
    QString path = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.csv)"));
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line;
    QStringList fields;
    int row = 1;
    while (!in.atEnd())
    {
        line = in.readLine();
        fields = line.split(',');
        for (int column = 0; column < fields.size(); column++)
        {
            ui->TableWidget_register->setRowCount(row);
            if(column != 3){
                ui->TableWidget_register->setItem(row - 1, column, new QTableWidgetItem(fields[column]));
            }
            else{
                QComboBox *rdselect = new QComboBox;
                QStringList list;
                list.append("read only");
                list.append("read / write");
                rdselect->addItems(list);
                if(fields[3] == "read only"){
                    rdselect->setCurrentIndex(0);
                }
                else{
                    rdselect->setCurrentIndex(1);
                }
                ui->TableWidget_register->setCellWidget(row - 1,3,rdselect);
            }
        }
        row++;
    }
    //debug output
    qDebug()<<"import excel file action successfully enabled！"<<endl;

}

void MainWindow::user_guide_action(){

    //output tips
    QMessageBox::information(this,"register manager","add wechat: zhouyuyangdashabi","yes");

    //debug output
    qDebug()<<"open user guide action successfully enabled！"<<endl;
}
