//Write C++ program to draw a concave polygon and fill it with desired color using seed fill algorithm. Apply the concept of inheritance.
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QtDebug>
#include "QColorDialog"
#include <QTime>
#include <iostream>
int vert,i,y,j,temp,k,xi[20];
int a[20],b[20],ver;
bool start;
float slope[20],dx,dy;
QImage img(500,500,QImage::Format_RGB888);
static QColor color;
void delay( int ms ) //Delay function added to slow down the polygon filling process. Not implemented while drawing polygon.
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )

    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *ev) //Mouse press function to draw the polygon.
{
    if(start)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[ver]=p;
        b[ver]=q;
        if(ev->button()==Qt::RightButton) //if right mouse button is cilcked then the polgon will be automatically completed.
        {
            z.dda(a[0],b[0],a[ver-1],b[ver-1],ui);
            start=false;
            QMessageBox message;
            message.information(0,"Drawing complete","Polygon has been completed.Please fill in the color");

        }
        else
        {
            if(ver>0)   //if left mouse button is clicked then the click will record the x and y coordinates and the line will be drawn from previous click.
            {
            z.dda(a[ver],b[ver],a[ver-1],b[ver-1],ui);
            }
        }
        ver++;
    }

}

//void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
//{
//    QRgb bg;
//    int p=ev->pos().x();
//    int q=ev->pos().y();
//    bg=qRgb(0,0,0);
//    for (int i=1;i<ver-1;i++)
//    {
//        int maxx=a[0];
//        if (a[i]>maxx)
//        {
//             maxx=a[i];

//        };
//    }
//    for (int i=1;i<ver-1;i++)
//    {
//        int maxy=b[0];
//        if (b[i]>maxy)
//        {
//             maxy=b[i];

//        };
//    }
//    for (int i=1;i<ver-1;i++)
//    {
//        int minx=a[0];
//        if (a[i]<minx)
//        {
//             minx=a[i];

//        };
//    }
//    for (int i=1;i<ver-1;i++)
//    {
//        int miny=b[0];
//        if (a[i]<miny)
//        {
//             miny=b[i];

//        };
//    }
//    for(j=0;j<ver;j++)
//                        {
//                            for(i=0;i<k-j-1;i++)
//                            {
//                                if(a[i]>a[i+1])
//                                {
//                                    temp = a[i];
//                                    a[i] = a[i+1];
//                                    a[i+1] = temp;
//                                }
//                            }
//                        }
//    for(j=0;j<ver;j++)
//                        {
//                            for(i=0;i<k-j-1;i++)
//                            {
//                                if(b[i]>b[i+1])
//                                {
//                                    temp = b[i];
//                                    b[i] = b[i+1];
//                                    b[i+1] = temp;
//                                }
//                            }
//                        }
//    if(minx<p<maxx ||(miny<q<maxy))
//    {
//      QMessageBox message;
//      message.information(0,"Warning","Click outside polygon");
//    }
//    else {
//        seedfill(p,q,bg);

//        QMessageBox message;
//        message.information(0,"Complete","Successfully filled the polygon");

//}
//}

//void MainWindow::seedfill(int x,int y,QRgb bg)  //4 neighbourhood method used.
//{
//    QRgb c=img.pixel(x,y);
//    if(c==bg)
//    {
//        img.setPixel(x,y,color.rgb());
//        delay(1);
//        seedfill(x+1,y,bg);
//        seedfill(x-1,y,bg);
//        seedfill(x,y+1,bg);
//        seedfill(x,y-1,bg);
//    }
//    ui->label->setPixmap(QPixmap::fromImage(img));

//}
void MainWindow::ScanFill(Ui::MainWindow *ui){  //Scan line fill method used to fill the polygon.
a[ver] = a[0];
b[ver] = b[0];

// set the slope array for all the vertices. If slope is 0 then it is not considered for processing.
for(i=0;i<ver;i++)
{
    dy = b[i+1] - b[i];
    dx = a[i+1] - a[i];
    if(dy == 0.0)
    {
        slope[i] = 1.0;
    }
    if(dx == 0.0)
    {
        slope[i] = 0.0;
    }
    if((dy != 0.0) && (dx != 0.0))
    {
        slope[i] = dx / dy;
    }
}


for(int y=0;y<500;y++)
{
    k = 0;

    // code to generate the scan line table
    // Active edge table generation using the y values which are to be further sorted in the increasing order x.
    for(i=0;i<ver;i++)
    {
        if(((b[i]<=y) && (b[i+1]>y)) || ((b[i]>y) && (b[i+1]<=y)))
        {
            xi[k] = int(a[i] + (slope[i]*(y-b[i])));
            k++;
        }
    }

    //Insertion sort used for sorting.
    //Sorting Active Edge values in order of x values.
    for (i = 1; i < k-1; i++)
        {
            int key = xi[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
            while (j >= 0 && xi[j] > key)
            {
                xi[j + 1] = xi[j];
                j = j - 1;
            }
            xi[j + 1] = key;
        }



    // Taking pairs of values and then filling the polygon.
    for(i=0;i<k;i+=2)
    {
      z.dda(xi[i],y,xi[i+1]+1,y, ui);
      delay(2);
    }

}
QMessageBox message;
        message.information(0,"Complete","Successfully filled the polygon");
}
//User defined class used.
void line::dda(float x1,float y1,float x2,float y2,Ui::MainWindow *ui)// DDA algorithm to draw the required polygon
{
    float m;
    float dx=(x2-x1);  //Calculate value of dx
    float dy=(y2-y1);  //Calculate value of dy
    if(abs(dx)>abs(dy))
    {
        m=abs(dx);
    }
    else
    {
        m=abs(dy);
    }
    float xinc=dx/m;
    float yinc=dy/m;
    img.setPixel(x1,y1,color.rgb());
    int i=0;
    while(i<m)
    {
        x1=x1+xinc;
        y1=y1+yinc;
        img.setPixel(x1,y1,color.rgb());
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));


}

void MainWindow::on_pushButton_clicked() //push button to get the color. This will inhance the UI.
{
    color= QColorDialog::getColor();
};
void MainWindow::on_pushButton_2_clicked() //push button to clear the screen. All the pixels are reset to black color and the values the x and y coordinates are
{                                          //cleared so a new polygon can be drawn.
    for (int x = 0; x < 500; ++x)
        {
            for (int y = 0; y < 500; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
        ui->label->setPixmap(QPixmap::fromImage(img));
        for(int q=0;q<=ver;q++)
        {
            a[ver]=0;
            b[ver]=0;
        };
        ver=0;
        start=true;
}
void MainWindow::on_pushButton_3_clicked()  //push button to fill in the polygon.
{
    ScanFill(ui);
}
