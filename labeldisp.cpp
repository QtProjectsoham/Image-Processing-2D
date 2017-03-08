#include "labeldisp.h"
#include<QPoint>
#include<QPixmap>
#include<QFileDialog>
labeldisp::labeldisp(QWidget *parent) :
    QLabel(parent)
{
    fname="D:/QT/MouseTracker/g1.png";  /*Default or initial Location from which picture to be uploaded*/
    color = Qt::red;
    pixmap = new QPixmap(fname);
}
/*Draws the image in the label and then draws the criss cross lines*/
void labeldisp::paintEvent(QPaintEvent *)
{
    QPainter pa(this);
    pa.setPen(QPen(Qt::white,1));
    //image.load(fname);
    //image = image.scaledToWidth(this->size().width(),Qt::SmoothTransformation);
    //QPixmap img = QPixmap::fromImage(image);
    pa.drawPixmap(0,0,*pixmap);
    pa.drawLine(point.x(),0,point.x(),this->size().height());
    pa.drawLine(0,point.y(),this->size().width(),point.y());
}

void labeldisp::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::RightButton)
                color = color == Qt::red ? Qt::blue : Qt::red;
            else {
                pressed = 1;
                draw(ev);
    }
}

void labeldisp::mouseReleaseEvent(QMouseEvent *ev)
{
    pressed = 0;
}
/*Mouse event to get the current cursor coordinates and send it to Main Window*/
void labeldisp::mouseMoveEvent(QMouseEvent *ev)
{
    QString fileName = this->objectName();
    double x,y;
    point = ev->pos();
    if(point.x() <= this->size().width() && point.y() <= this->size().height())
    {
        if(fileName.compare("lblMouse")==0) /*If the current QLabel is lblMouse then send coordinate as it is*/
        {
            if(point.x() >=0 && point.y()>=0)
            {
                emit sendMousePosition(point);
            }
        }
        else /*The current QLabel is the lblImage, hence modify the coordinates by adding maxWidth & MaxHeight so that
        it can be calculated properly for 2nd Image in Main Window*/
        {
            x=point.x();
            y=point.y();
            x=x+this->size().width();
            y=y+this->size().height();
            QPoint temp(x,y);
            emit sendMousePosition(temp);
        }
        //draw(ev);
        repaint();
    }
}
/*Gets the location of image file sent from Main Window and loads that image*/
void labeldisp::getImgFileName(QString fileName)
{
    fname = fileName;
    bool valid = image.load(fname);
    if(valid)
    {
        pixmap = new QPixmap(fname);
        repaint();  /*Repaint actually draws the loaded image in the QLabel*/
    }
    else
    {
        this->setText("Failed to Load Image");
    }
}

void labeldisp::draw(QMouseEvent *e){
    if (pressed) {
        QPainter painter(pixmap);
        painter.setPen(color);
        int x = e->pos().x();
        int y = e->pos().y();
        painter.drawPoint(x+1,y);
        painter.drawPoint(x-1,y);
        painter.drawPoint(x,y+1);
        painter.drawPoint(x,y-1);
        repaint();
    }
}
