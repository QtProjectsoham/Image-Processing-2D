#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*Gets the coordinates of cursor from QLabel Signal - sendMousePosition and displays the coordinates in the corresponding Label*/
void MainWindow::showMousePosition(QPoint &pos)
{


}
