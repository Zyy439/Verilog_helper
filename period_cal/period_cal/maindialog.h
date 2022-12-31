#ifndef MAINDIALOG_H
#define MAINDIALOG_H


#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDialog>

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    //constructor function
    MainDialog(QWidget *parent = 0);
    ~MainDialog();

    //pushbuttons
    QPushButton     button_calc     ;
    QPushButton     button_exit     ;

    //labels
    QLabel          label_frequency ;
    QLabel          label_time      ;
    QLabel          label_period    ;

    //QLineEdit
    QLineEdit       lineedit_frequency  ;
    QLineEdit       lineedit_time       ;
    QLineEdit       lineedit_periods    ;

//    int bit_length_calc(int period_num_int = 0);
public slots:
    void Show_Calc_Result();

private:
    int bit_length_calc(int period_num_int);
};

#endif // MAINDIALOG_H
