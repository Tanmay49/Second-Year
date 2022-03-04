#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class line{
public:
    void dda(float,float,float,float,Ui::MainWindow*);
//    void arr();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    line z;

private slots:

//   void seedfill(int x,int y,QRgb);

    void ScanFill(Ui::MainWindow *);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;




protected:
    void mousePressEvent(QMouseEvent *ev);
  // void mouseDoubleClickEvent(QMouseEvent *ev);

};
#endif // MAINWINDOW_H
