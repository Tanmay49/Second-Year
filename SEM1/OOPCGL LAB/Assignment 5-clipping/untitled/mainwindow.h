#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dda(float,float,float,float);  //Line by DDA algorithm
    int findRegionCode(double, double);     //Function to find region code
    void Clip(int, int, int, int);      //Function to perform clipping

private:
    Ui::MainWindow *ui;
    int noOfLines = 0;      //to count the number of lines
    int x1Line[10];         //to store all the x coordinates of first end point of the line
    int x2Line[10];         //to store all the x coordinates of second end point of the line
    int y1Line[10];         //to store all the y coordinates of first end point of the line
    int y2Line[10];         //to store all the y coordinates of second end point of the line
    bool click1, click2, diag1, diag2;      //boolean variables to check whether line is drawn or clipping window
    int diagonal_x[2], diagonal_y[2];       //to store x and y coordinates of the diagonal vertices of the window
    int left;                         // left of window
    int right;                          // right of window
    int top;                         // top of window
    int bottom;                        // bottom of window

protected:
    void mousePressEvent(QMouseEvent *ev);      //for mouse functionality

private slots:
    void on_pushButton_clicked();           //for drawing line
    void on_pushButton_2_clicked();         //for changing colour
    void on_pushButton_3_clicked();         //for drawing clipping window
    void on_pushButton_4_clicked();         //for performing the clipping
    void on_pushButton_5_clicked();         //for clearing the screen
};
#endif // MAINWINDOW_H
