#include "maindialog.h"
//#include <QDebug>
#include <qmath.h>

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
{

    //==============================================================
    //initiallize the window
    this->setFixedSize(500,250);
    this->setWindowIcon(QIcon("//cherry-2-256.ico"));

    //--------------------------------------------------------------
    //calculate pushbutton
    button_calc.setParent(this);
    button_calc.setText("calculate");
    button_calc.move(240,200);
    connect(&button_calc,&QPushButton::clicked,this,&MainDialog::Show_Calc_Result);

    //--------------------------------------------------------------
    //exit pushbutton
    button_exit.setParent(this);
    button_exit.setText("exit");
    button_exit.move(370,200);
    connect(&button_exit,&QPushButton::clicked,this,&QDialog::close);

    //--------------------------------------------------------------
    //frequency label
    label_frequency.setParent(this);
    label_frequency.setText("Frequency(MHz) :");
    label_frequency.move(10,10);

    //--------------------------------------------------------------
    //time label
    label_time.setParent(this);
    label_time.setText("Time(Ms) :");
    label_time.move(10,70);

    //--------------------------------------------------------------
    //period label
    label_period.setParent(this);
    label_period.setText("the number of clock periods need is :");
    label_period.move(10,130);

    //--------------------------------------------------------------
    //period label
    lineedit_frequency.setParent(this);
    lineedit_frequency.setClearButtonEnabled(true);
    lineedit_frequency.setPlaceholderText("Please input the frequency of the clock");
    lineedit_frequency.resize(480,28);
    lineedit_frequency.move(10,35);

    //--------------------------------------------------------------
    //period label
    lineedit_time.setParent(this);
    lineedit_time.setClearButtonEnabled(true);
    lineedit_time.setPlaceholderText("Please input the time that you want");
    lineedit_time.resize(480,28);
    lineedit_time.move(10,95);

    //--------------------------------------------------------------
    //period label
    lineedit_periods.setParent(this);
    lineedit_periods.resize(480,28);
    lineedit_periods.setReadOnly(true);
    lineedit_periods.move(10,155);
}

MainDialog::~MainDialog()
{

}

void MainDialog::Show_Calc_Result()
{
    //calculate the period number and then convert it into integar.
    double frequency_mhz        ;
    double time_ms              ;
    double period_num           ;
    frequency_mhz   = lineedit_frequency.text().toDouble()      ;
    time_ms         = lineedit_time.text().toDouble()           ;
    period_num      = frequency_mhz*1000*time_ms                ;
    int period_num_int = (int)period_num;

    //calculate the bit length needed
    int bit_length;
    bit_length = bit_length_calc(period_num_int);

    //output the result into the third line edit box
    QString Qstr_result;
    Qstr_result = QString::number(bit_length)+"'"+QString::number(period_num_int,16);
    lineedit_periods.setText(Qstr_result);


//    qDebug() << frequency_mhz << endl;
//    qDebug() << time_ms << endl;
//    qDebug() << bit_length << endl;
//    qDebug() << period_num_int << endl;
};

int MainDialog::bit_length_calc(int period_num_int){
    int bit_length = 1;
    while(qPow(2,bit_length) <= period_num_int)
    {
        bit_length ++;
    }
    return bit_length;
}
