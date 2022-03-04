#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE
class func
{
private:
    friend class ass;
public:
    void BresenhamCircle(int,int,int,Ui::MainWindow *ui);
    void DDALine(float,float,float,float,Ui::MainWindow *ui);
    void BresenhamLine(int,int,int,int,Ui::MainWindow *ui);
};
class ass
{
private:
    friend class MainWindow;
    friend class func;
    void Assignment6a(Ui::MainWindow *ui);
    void Assignment6b(Ui::MainWindow *ui);
    func a;


};

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ass obj;



private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
