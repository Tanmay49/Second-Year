//Write C++ program to implement Cohen Southerland line clipping algorithm.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>  // for alert box
#include <QColorDialog> // to choose the colors
#include <QMouseEvent> // to detect all the mouse events

#define height 600 // set the height of the drawing area
#define width 600  // set the width of the drawing area

QImage img(height, width, QImage::Format_RGB888); // this is the drawing area
QRgb rgb(qRgb(255, 255, 255));  //initially colour set to white

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < height; ++x) // this is for initial black screen
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0)); //setting each pixel to black colour
        }
    }
    click1 = false;     //setting all boolean variables to false
    click2 = false;
    diag1 = false;
    diag2 = false;
    ui -> pushButton_4 -> setEnabled(false);    //disabled clip button
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)       //defining the mouse event
{
    if(click1)          //checks whether user is giving input for the first coordinates of the line
    {
        int x1 = ev -> pos().x();
        int y1 = ev -> pos().y();
        x1Line[noOfLines] = x1;
        y1Line[noOfLines] = y1;
        click1 = false;             //disabling input for first coordinate of the line
        click2 = true;              //enabling input for second coordinte of the line
    }
    else if(click2)     //checks whether user is giving input for the second coordinates of the line
    {
        int x2 = ev -> pos().x();
        int y2 = ev -> pos().y();
        x2Line[noOfLines] = x2;
        y2Line[noOfLines] = y2;
        click2 = false;             //disabling input for second coordinate of the line
        dda(x1Line[noOfLines], y1Line[noOfLines], x2Line[noOfLines], y2Line[noOfLines]);    //calling the dda function to draw the line
        noOfLines ++;       //incrementing the count of number of lines
        QMessageBox msg;
        msg.information(0, "Information", "Mouse functionality disabled!");
        ui -> pushButton_3 -> setEnabled(true);     //enabling the button to draw the clipping window
    }
    else if(diag1)      //checks whether user is giving input for the first diagonal coordinates of the window
    {
        diagonal_x[0] = ev -> pos().x();
        diagonal_y[0] = ev -> pos().y();
        diag1 = false;      //disabling input for first diagonal coordinates
        diag2 = true;       //enabling input for second diagonal coordinates
    }
    else if(diag2)
    {
        diagonal_x[1] = ev -> pos().x();
        diagonal_y[1] = ev -> pos().y();
        diag2 = false;      //disabling input for second diagonal coordinates
        dda(diagonal_x[0], diagonal_y[0], diagonal_x[1], diagonal_y[0]);        //calling dda function to draw lines between the diagonal
        dda(diagonal_x[0], diagonal_y[0], diagonal_x[0], diagonal_y[1]);        //coordinates to draw the clipping window
        dda(diagonal_x[1], diagonal_y[1], diagonal_x[1], diagonal_y[0]);
        dda(diagonal_x[1], diagonal_y[1], diagonal_x[0], diagonal_y[1]);
        QMessageBox msg;
        msg.information(0, "Information", "Mouse functionality disabled!");
        ui -> pushButton -> setEnabled(true);       //enabling button for drawing line
        ui -> pushButton_4 -> setEnabled(true);     //enabling button for performing the clipping
    }
}

void MainWindow::dda(float x1, float y1, float x2, float y2)        //defining the dda line drawing algorithm
{
    float dx, dy, step, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) >= abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    dx = dx / step;
    dy = dy / step;
    int i = 0;
    x = x1;
    y = y1;
    while (i < step)
    {
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, rgb);
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::findRegionCode(double x, double y) //for finding the region code
{
    //4 bit region code system in the algorithm
    //Use   TBRL

    /*
                        left	    central	     right

    top             | 1001 =9  |    1000 =8	  | 1010 =10
                    ------------------------------------
    central         | 0001 =1  |    0000 =0	  | 0010 =2
                    ------------------------------------
    bottom          | 0101 =5  |	0100 =4	  | 0110 =6
     */

    if (diagonal_x[0] > diagonal_x[1])      //code to set the right, left, top and bottom of the clipping window
    {
        right = diagonal_x[0];
        left = diagonal_x[1];
    }
    else
    {
        right = diagonal_x[1];
        left = diagonal_x[0];
    }


    if (diagonal_y[0] > diagonal_y[1])
    {
        top = diagonal_y[0];
        bottom = diagonal_y[1];
    }
    else
    {
        top = diagonal_y[1];
        bottom = diagonal_y[0];
    }

    int bits[4];        //setting the 4 bit region code
    for(int i =0;i<4;i++){
        bits[i]=0;
    }
    if(y>top)
    {
        bits[0]=1;
    }
    else
    {
        bits[0]=0;
    }
    if(y<bottom)
    {
        bits[1]=1;
    }
    else
    {
        bits[1]=0;
    }
    if(x>right)
    {
        bits[2]=1;
    }
    else
    {
        bits[2]=0;
    }
    if(x<left)
    {
        bits[3]=1;
    }
    else
    {
        bits[3]=0;
    }
    int m =1;
    int n=0;
    for(int i=3;i>=0;i--){      //converting the binary number to decimal
        n=n+bits[i]*m;
        m=m*2;
    }
    return n;
}

void MainWindow::Clip(int x1, int y1, int x2, int y2)       //defining the clipping function
{
    int code1 = findRegionCode(x1, y1); // find region code of 1st end point
    int code2 = findRegionCode(x2, y2); // find region code of 2nd end point

    bool isVisible = false;     //defining boolean variable to check whether line completely lies inside

    while (true)
    {
        if (code1 == 0 && code2 == 0) // line completely inside the window
        {
            isVisible = true;
            break;
        }
        else if (code1 & code2) // both are outside so ignore the line
        {
            break;
        }
        else
        {
            int code_out;
            int x=0, y=0;
            if (code1 != 0) // check which point is outside
                code_out = code1;
            else
                code_out = code2;

            if (code_out & 4)
            {
                x = x1 + (x2 - x1) * (bottom - y1) / (y2 - y1);
                y = bottom;
            }
            else if (code_out & 8)
            {
                x = x1 + (x2 - x1) * (top - y1) / (y2 - y1);
                y = top;
            }
            else if (code_out & 1)
            {
                y = y1 + (y2 - y1) * (left - x1) / (x2 - x1);
                x = left;
            }
            else if (code_out & 2)
            {
                y = y1 + (y2 - y1) * (right - x1) / (x2 - x1);
                x = right;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = findRegionCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = findRegionCode(x2, y2);
            }
        }
    }

    if (isVisible)
    {
        dda(x1, y1, x2, y2);    //after this we will get new co-ordinates
    }
}

void MainWindow::on_pushButton_clicked()        //button for drawing line
{
    click1 = true;      //enabling input for first coordinate of the line
    QMessageBox msg;
    msg.information(0, "Information", "Mouse functionality enabled. Click on 2 different points to draw line between them!");
    ui -> pushButton_3 -> setEnabled(false);        //disabling the button to draw the clipping window
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()      //button to change the colour
{
    QRgb color(QColorDialog::getColor().rgb());
    rgb = color;        //Sets the value to the variable
}

void MainWindow::on_pushButton_3_clicked()      //button to draw the clipping window
{
    diag1 = true;       //enabling input for second diagonal coordinates
    QMessageBox msg;
    msg.information(0, "Information", "Mouse functionality enabled. Click on 2 different points to draw the cliiping window using these 2 points as diagonals!");
    ui -> pushButton -> setEnabled(false);      //disbaling the button to draw line
    ui -> pushButton_3 -> setEnabled(false);    //disabling the button to draw clipping window so that there are no 2 windows drawn
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_4_clicked()      //button to perform the clipping
{
    {
        for (int x = 0; x < height; ++x) // this is for initial black screen
        {
            for (int y = 0; y < width; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));  //setting each pixel to black colour
            }
        }
        dda(diagonal_x[0], diagonal_y[0], diagonal_x[1], diagonal_y[0]);        //calling dda function to draw lines between the diagonal
        dda(diagonal_x[0], diagonal_y[0], diagonal_x[0], diagonal_y[1]);        //coordinates to draw the clipping window
        dda(diagonal_x[1], diagonal_y[1], diagonal_x[1], diagonal_y[0]);
        dda(diagonal_x[1], diagonal_y[1], diagonal_x[0], diagonal_y[1]);
        for (int i = 0; i < noOfLines; i++)
        {
            Clip(x1Line[i], y1Line[i], x2Line[i], y2Line[i]);       //Calling the clip function
        }
    }
}

void MainWindow::on_pushButton_5_clicked()      //button to clear the screen
{
    noOfLines = 0;      //setting the number of lines count to 0
    click1 = false;     //setting all boolean variables to false
    click2 = false;
    diag1 = false;
    diag2 = false;
    ui -> pushButton_4 -> setEnabled(false);    //disabling the button to perform clipping
    ui -> pushButton_3 -> setEnabled(true);     //enabling the button to draw the clipping window
    for (int x = 0; x < height; ++x) // this is for initial black screen
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));  //setting each pixel to black colour
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
