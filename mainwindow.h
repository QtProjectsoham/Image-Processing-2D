#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define sizex 350
#define sizey 350

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_loadimage_clicked();

    void on_dt8_clicked();

    void on_histogramequilization_clicked();

    void on_ccl4_clicked();
    void on_binarize_clicked();
    void on_colormap_clicked();


    void on_FDT_clicked();

    void on_localmaxima_clicked();

    void on_ccl8_clicked();

protected:
    //void        mouseMoveEvent( QMouseEvent * );
    void drawimage();
   // void        mousePressEvent( QMouseEvent * );
    //void        wheelEvent(QWheelEvent *);

private:
    Ui::MainWindow *ui;
    QPixmap pix;
};

#endif // MAINWINDOW_H
