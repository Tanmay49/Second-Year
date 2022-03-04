#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <math.h>
#include<QTime>
#define height 600
#define width 800

QImage img(width, height, QImage::Format_RGB888);
QRgb rgb(qRgb(255,255,255));

void delay( int ms )
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )

    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void func::BresenhamCircle(int xCenter, int yCenter, int radius,Ui::MainWindow *ui) //defining Bresenham Circle drawing algorithm
{
    int x = 0;
            int y = radius;
            int d = 3 - (2 * radius);
            int x_arr[1000], y_arr[1000];
            int count = 0;
            while (x <= y)
            {
                if (d > 0)
                {
                    d = d + 4 * (x - y) + 10;
                    y--;
                }
                else
                {
                    d = d + (4 * x) + 6;
                }
                x++;
                img.setPixel(xCenter + x, yCenter - y, rgb); // this is the first octant of the circle
                ui->label->setPixmap(QPixmap::fromImage(img));
                ui->label->show();
                x_arr[count] = x,
                y_arr[count] = y;
                count++;
                delay(50);
            }

            for(int i = 0; i < count; i++)      //This is the second octant
            {

                img.setPixel(xCenter + y_arr[i], yCenter - x_arr[i], rgb);
                delay(50);
                ui->label->setPixmap(QPixmap::fromImage(img));
                ui->label->show();
            }

            for(int i = 0; i < count; i++)      //This is the second quadrant. Reflection about y-axis.
            {

                img.setPixel(xCenter - y_arr[i], yCenter - x_arr[i], rgb);
                img.setPixel(xCenter - x_arr[i], yCenter - y_arr[i], rgb);
                delay(50);
                ui->label->setPixmap(QPixmap::fromImage(img));
                ui->label->show();
            }

            for(int i = 0; i < count; i++)      //These are the 3rd and 4th quadrants. Reflection about x-axis.
            {
                img.setPixel(xCenter + x_arr[i], yCenter + y_arr[i], rgb);
                img.setPixel(xCenter - x_arr[i], yCenter + y_arr[i], rgb);
                img.setPixel(xCenter + y_arr[i], yCenter + x_arr[i], rgb);
                img.setPixel(xCenter - y_arr[i], yCenter + x_arr[i], rgb);
                delay(50);
                ui->label->setPixmap(QPixmap::fromImage(img));
                ui->label->show();
            }
}

void func::BresenhamLine(int x1, int y1, int x2, int y2,Ui::MainWindow *ui)
{
    int dx = abs(x2 - x1);                                  //calculating the dx vaue
    int sx;
    //if x1 > x2 then we need to decrement otherwise we increment
    if(x1<x2)
    {
        sx=1;
    }
    else
    {
        sx=-1;
    }

    int dy = -abs(y2 - y1);
    int sy;

    //if y1<y2 then we increment else we decrement
    if(y1<y2)
    {
        sy=1;       //setting up for increment
    }
    else
    {
        sy=-1;      //setting up for decrement
    }
    int err = dx + dy;      // error value as we have taken dy negative so its dx - dy
                            // err is to get the integer value of the nearest pixel

    while (true)
    {
        img.setPixel(x1, y1, rgb);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;               // calculating the decision parameter
        if (e2 >= dy)                   //checking condition for corresponding increment
        {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

//defining function for DDA line algorithm
void func::DDALine(float x1, float y1, float x2, float y2,Ui::MainWindow *ui)
{

    float dx = (x2 - x1);
    float dy = (y2 - y1);
    float step;

    //determining the no. of steps for code to run
    if (abs(dx)>=abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    //value by which coordinates will be incremented every iteration
    dx = dx / step;
    dy = dy / step;

    float x = x1, y = y1;
    int i = 1;                  //setting up increment for calculating no. of steps

    //repeating process for no of steps
    while (i <= step)
    {
        img.setPixel(x, y, rgb);
        x += dx;
        y += dy;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

//printing pattern of assignment 6A
void ass::Assignment6a(Ui::MainWindow *ui)
{
    int xC = ui->textEdit->toPlainText().toInt();
    int yC = ui->textEdit_2->toPlainText().toInt();
    int rad = ui->textEdit_3->toPlainText().toInt();

    //triangle formed is equilateral
    float x1 = xC + rad * (float)sqrt(3) / 2;
    float x2 = xC - rad * (float)sqrt(3) / 2;
    float y1 = yC + rad / 2;

    //drawing the two concentric circles
    a.BresenhamCircle(xC, yC, rad,ui);
    a.BresenhamCircle(xC, yC, rad / 2,ui);

    //drawing the lines
    a.DDALine(x1, y1, x2, y1,ui);
    a.DDALine(x1, y1, xC, (float)yC - rad,ui);
    a.BresenhamLine(x2, y1, (float)xC, (float)yC - rad,ui);
}

//printing pattern of assignment 6B
void ass::Assignment6b(Ui::MainWindow *ui)
{
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_4->toPlainText().toInt();
    int y2 = ui->textEdit_5->toPlainText().toInt();

    a.DDALine(x1,y1,x2,y1,ui);
    a.DDALine(x2,y1,x2,y2,ui);
    a.DDALine(x2,y2,x1,y2,ui);
    a.DDALine(x1,y2,x1,y1,ui);

    int x1c = (x1 + x2)/2;
    int y1c = (y1 + y2)/2;

    // c0ordinates are (x1c, y1), (x2,y1c), (x1c, y2), (x1, y1c) respectively

    a.BresenhamLine(x1c, y1, x2, y1c,ui);
    a.BresenhamLine(x2, y1c, x1c, y2,ui);
    a.BresenhamLine(x1c, y2, x1, y1c,ui);
    a.BresenhamLine(x1, y1c, x1c, y1,ui);

    // coordinates for the points are ( (x1c+x1)/2 , (y1 + y1c)/2 ) , center coordinates are = x1+x2/2 , y1+y2/2

    // center = x1c, y1c

    float h1 = abs(x1-x2)/2;
    float w1 = abs(y1-y2)/2;

    float reqRadius = h1 * w1 / sqrt(h1*h1+w1*w1);

    a.BresenhamCircle(x1c, y1c, reqRadius,ui);
}

//defining all the pushButton functions
void MainWindow::on_pushButton_clicked()
{
    QMessageBox message;
    if(ui->textEdit->toPlainText().isEmpty()||ui->textEdit_2->toPlainText().isEmpty()||ui->textEdit_3->toPlainText().isEmpty())
    {
        message.information(0,"Warning!","Fields except for x2 and y2 cannot be left empty!");
    }
    else
    {
       for (int x = 0; x < width; ++x)
       {
          for (int y = 0; y < height; ++y)
          {
             img.setPixel(x, y, qRgb(0, 0, 0));
          }
       }
       ui->label->setPixmap(QPixmap::fromImage(img));
       obj.Assignment6a(ui);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw
    rgb = color;
}

void MainWindow::on_pushButton_3_clicked()
{
    for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
        ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox message;
    if(ui->textEdit->toPlainText().isEmpty()||ui->textEdit_2->toPlainText().isEmpty()||ui->textEdit_4->toPlainText().isEmpty()||ui->textEdit_5->toPlainText().isEmpty())
    {
        message.information(0,"Warning!","Fields except for radius cannot be left empty!");
    }
    else
    {
        for (int x = 0; x < width; ++x)
        {
           for (int y = 0; y < height; ++y)
           {
              img.setPixel(x, y, qRgb(0, 0, 0));
           }
        }
       ui->label->setPixmap(QPixmap::fromImage(img));
       obj.Assignment6b(ui);
    }

}

