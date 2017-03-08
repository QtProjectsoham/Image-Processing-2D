/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *loadimage;
    QPushButton *dt8;
    QLabel *ipimage;
    QLabel *opimage;
    QLabel *label;
    QLabel *heightvalue;
    QLabel *label_2;
    QLabel *widthvalue;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *xcoordinatevalue;
    QLabel *label_6;
    QLabel *ycoordinatevalue;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *Redvalue;
    QLabel *label_8;
    QLabel *Greenvalue;
    QLabel *label_9;
    QLabel *Bluevalue;
    QPushButton *histogramequilization;
    QPushButton *ccl4;
    QPushButton *binarize;
    QPushButton *colormap;
    QPushButton *FDT;
    QPushButton *localmaxima;
    QLabel *label_10;
    QLabel *nocc;
    QPushButton *ccl8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1075, 837);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loadimage = new QPushButton(centralWidget);
        loadimage->setObjectName(QStringLiteral("loadimage"));
        loadimage->setGeometry(QRect(720, 0, 121, 41));
        dt8 = new QPushButton(centralWidget);
        dt8->setObjectName(QStringLiteral("dt8"));
        dt8->setGeometry(QRect(820, 150, 111, 41));
        ipimage = new QLabel(centralWidget);
        ipimage->setObjectName(QStringLiteral("ipimage"));
        ipimage->setGeometry(QRect(10, 10, 350, 350));
        ipimage->setMouseTracking(true);
        ipimage->setScaledContents(true);
        opimage = new QLabel(centralWidget);
        opimage->setObjectName(QStringLiteral("opimage"));
        opimage->setGeometry(QRect(10, 380, 350, 350));
        opimage->setScaledContents(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(960, 10, 51, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        heightvalue = new QLabel(centralWidget);
        heightvalue->setObjectName(QStringLiteral("heightvalue"));
        heightvalue->setGeometry(QRect(1010, 10, 51, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(850, 10, 41, 21));
        label_2->setFont(font);
        widthvalue = new QLabel(centralWidget);
        widthvalue->setObjectName(QStringLiteral("widthvalue"));
        widthvalue->setGeometry(QRect(900, 10, 51, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 60, 121, 31));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(850, 60, 16, 31));
        QFont font1;
        font1.setPointSize(10);
        label_4->setFont(font1);
        xcoordinatevalue = new QLabel(centralWidget);
        xcoordinatevalue->setObjectName(QStringLiteral("xcoordinatevalue"));
        xcoordinatevalue->setGeometry(QRect(870, 65, 41, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(940, 70, 21, 16));
        label_6->setFont(font1);
        ycoordinatevalue = new QLabel(centralWidget);
        ycoordinatevalue->setObjectName(QStringLiteral("ycoordinatevalue"));
        ycoordinatevalue->setGeometry(QRect(970, 70, 41, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(720, 100, 81, 21));
        label_5->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(800, 102, 31, 21));
        label_7->setFont(font1);
        Redvalue = new QLabel(centralWidget);
        Redvalue->setObjectName(QStringLiteral("Redvalue"));
        Redvalue->setGeometry(QRect(830, 102, 41, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(880, 103, 46, 20));
        label_8->setFont(font1);
        Greenvalue = new QLabel(centralWidget);
        Greenvalue->setObjectName(QStringLiteral("Greenvalue"));
        Greenvalue->setGeometry(QRect(920, 103, 46, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(970, 103, 31, 20));
        label_9->setFont(font1);
        Bluevalue = new QLabel(centralWidget);
        Bluevalue->setObjectName(QStringLiteral("Bluevalue"));
        Bluevalue->setGeometry(QRect(1010, 103, 46, 20));
        histogramequilization = new QPushButton(centralWidget);
        histogramequilization->setObjectName(QStringLiteral("histogramequilization"));
        histogramequilization->setGeometry(QRect(940, 150, 121, 41));
        ccl4 = new QPushButton(centralWidget);
        ccl4->setObjectName(QStringLiteral("ccl4"));
        ccl4->setGeometry(QRect(720, 200, 91, 41));
        binarize = new QPushButton(centralWidget);
        binarize->setObjectName(QStringLiteral("binarize"));
        binarize->setGeometry(QRect(720, 150, 91, 41));
        colormap = new QPushButton(centralWidget);
        colormap->setObjectName(QStringLiteral("colormap"));
        colormap->setGeometry(QRect(820, 250, 111, 41));
        FDT = new QPushButton(centralWidget);
        FDT->setObjectName(QStringLiteral("FDT"));
        FDT->setGeometry(QRect(940, 200, 121, 41));
        QFont font2;
        font2.setPointSize(8);
        FDT->setFont(font2);
        localmaxima = new QPushButton(centralWidget);
        localmaxima->setObjectName(QStringLiteral("localmaxima"));
        localmaxima->setGeometry(QRect(720, 250, 91, 41));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(720, 310, 141, 41));
        nocc = new QLabel(centralWidget);
        nocc->setObjectName(QStringLiteral("nocc"));
        nocc->setGeometry(QRect(870, 320, 71, 21));
        ccl8 = new QPushButton(centralWidget);
        ccl8->setObjectName(QStringLiteral("ccl8"));
        ccl8->setGeometry(QRect(820, 200, 111, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1075, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        loadimage->setText(QApplication::translate("MainWindow", "Load Image", 0));
        dt8->setText(QApplication::translate("MainWindow", "8-Distance Transform", 0));
        ipimage->setText(QString());
        opimage->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Height", 0));
        heightvalue->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Width", 0));
        widthvalue->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Pixel Coordinate", 0));
        label_4->setText(QApplication::translate("MainWindow", "X", 0));
        xcoordinatevalue->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Y", 0));
        ycoordinatevalue->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", " RGB Value", 0));
        label_7->setText(QApplication::translate("MainWindow", " Red", 0));
        Redvalue->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Green", 0));
        Greenvalue->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", " Blue", 0));
        Bluevalue->setText(QString());
        histogramequilization->setText(QApplication::translate("MainWindow", "Histogram Equilization", 0));
        ccl4->setText(QApplication::translate("MainWindow", "4-CCL", 0));
        binarize->setText(QApplication::translate("MainWindow", "Binarize", 0));
        colormap->setText(QApplication::translate("MainWindow", "Add color map", 0));
        FDT->setText(QApplication::translate("MainWindow", "FDT", 0));
        localmaxima->setText(QApplication::translate("MainWindow", "Local Maxima", 0));
        label_10->setText(QApplication::translate("MainWindow", "No. of connected component", 0));
        nocc->setText(QString());
        ccl8->setText(QApplication::translate("MainWindow", "8-CCL", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
