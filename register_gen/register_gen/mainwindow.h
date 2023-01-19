#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //define the row number in the current table widget
    unsigned int row_number;

public slots:
    void add_signal();
    void minus_signal();
    void clear_signal();
    void generate_verilog_file();
};

#endif // MAINWINDOW_H
