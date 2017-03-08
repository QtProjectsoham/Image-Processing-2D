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

class Ui_ipimage
{
public:
    QWidget *centralWidget;
    QLabel *ipimage_2;
    QLabel *opimage;
    QPushButton *loadimage;
    QLabel *lblWidth;
    QLabel *widthvalue;
    QLabel *lblHeight;
    QLabel *heightvalue;
    QLabel *lblCoordinate;
    QLabel *lblMousePosition;
    QLabel *lblRGB;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *Redvalue;
    QLabel *Greenvalue;
    QLabel *Bluevalue;
    QPushButton *binarize;
    QPushButton *dt8;
    QPushButton *histogramequilization;
    QPushButton *ccl4;
    QPushButton *colormap;
    QPushButton *FDT;
    QPushButton *localmaxima;
    QLabel *label_5;
    QLabel *nocc;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ipimage)
    {
        if (ipimage->objectName().isEmpty())
            ipimage->setObjectName(QStringLiteral("ipimage"));
        ipimage->resize(875, 694);
        centralWidget = new QWidget(ipimage);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ipimage_2 = new QLabel(centralWidget);
        ipimage_2->setObjectName(QStringLiteral("ipimage_2"));
        ipimage_2->setGeometry(QRect(10, 10, 350, 350));
        ipimage_2->setMouseTracking(true);
        ipimage_2->setFrameShape(QFrame::Box);
        opimage = new QLabel(centralWidget);
        opimage->setObjectName(QStringLiteral("opimage"));
        opimage->setGeometry(QRect(370, 10, 350, 350));
        opimage->setFrameShape(QFrame::Box);
        loadimage = new QPushButton(centralWidget);
        loadimage->setObjectName(QStringLiteral("loadimage"));
        loadimage->setGeometry(QRect(60, 380, 111, 31));
        lblWidth = new QLabel(centralWidget);
        lblWidth->setObjectName(QStringLiteral("lblWidth"));
        lblWidth->setGeometry(QRect(200, 390, 46, 13));
        lblWidth->setAlignment(Qt::AlignCenter);
        widthvalue = new QLabel(centralWidget);
        widthvalue->setObjectName(QStringLiteral("widthvalue"));
        widthvalue->setGeometry(QRect(260, 390, 46, 13));
        lblHeight = new QLabel(centralWidget);
        lblHeight->setObjectName(QStringLiteral("lblHeight"));
        lblHeight->setGeometry(QRect(350, 390, 46, 13));
        lblHeight->setAlignment(Qt::AlignCenter);
        heightvalue = new QLabel(centralWidget);
        heightvalue->setObjectName(QStringLiteral("heightvalue"));
        heightvalue->setGeometry(QRect(420, 390, 46, 13));
        heightvalue->setAlignment(Qt::AlignCenter);
        lblCoordinate = new QLabel(centralWidget);
        lblCoordinate->setObjectName(QStringLiteral("lblCoordinate"));
        lblCoordinate->setGeometry(QRect(50, 420, 131, 31));
        lblCoordinate->setAlignment(Qt::AlignCenter);
        lblMousePosition = new QLabel(centralWidget);
        lblMousePosition->setObjectName(QStringLiteral("lblMousePosition"));
        lblMousePosition->setGeometry(QRect(170, 420, 121, 21));
        lblMousePosition->setAlignment(Qt::AlignCenter);
        lblRGB = new QLabel(centralWidget);
        lblRGB->setObjectName(QStringLiteral("lblRGB"));
        lblRGB->setGeometry(QRect(80, 460, 81, 21));
        lblRGB->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 460, 46, 13));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 460, 46, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 460, 46, 13));
        Redvalue = new QLabel(centralWidget);
        Redvalue->setObjectName(QStringLiteral("Redvalue"));
        Redvalue->setGeometry(QRect(240, 460, 46, 13));
        Redvalue->setFrameShape(QFrame::Box);
        Greenvalue = new QLabel(centralWidget);
        Greenvalue->setObjectName(QStringLiteral("Greenvalue"));
        Greenvalue->setGeometry(QRect(340, 460, 46, 13));
        Greenvalue->setFrameShape(QFrame::Box);
        Bluevalue = new QLabel(centralWidget);
        Bluevalue->setObjectName(QStringLiteral("Bluevalue"));
        Bluevalue->setGeometry(QRect(450, 460, 46, 13));
        Bluevalue->setFrameShape(QFrame::Box);
        binarize = new QPushButton(centralWidget);
        binarize->setObjectName(QStringLiteral("binarize"));
        binarize->setGeometry(QRect(80, 510, 81, 41));
        dt8 = new QPushButton(centralWidget);
        dt8->setObjectName(QStringLiteral("dt8"));
        dt8->setGeometry(QRect(170, 510, 121, 41));
        histogramequilization = new QPushButton(centralWidget);
        histogramequilization->setObjectName(QStringLiteral("histogramequilization"));
        histogramequilization->setGeometry(QRect(300, 510, 131, 41));
        ccl4 = new QPushButton(centralWidget);
        ccl4->setObjectName(QStringLiteral("ccl4"));
        ccl4->setGeometry(QRect(90, 570, 75, 23));
        colormap = new QPushButton(centralWidget);
        colormap->setObjectName(QStringLiteral("colormap"));
        colormap->setGeometry(QRect(200, 570, 75, 23));
        FDT = new QPushButton(centralWidget);
        FDT->setObjectName(QStringLiteral("FDT"));
        FDT->setGeometry(QRect(320, 570, 75, 23));
        localmaxima = new QPushButton(centralWidget);
        localmaxima->setObjectName(QStringLiteral("localmaxima"));
        localmaxima->setGeometry(QRect(420, 570, 75, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 610, 181, 31));
        nocc = new QLabel(centralWidget);
        nocc->setObjectName(QStringLiteral("nocc"));
        nocc->setGeometry(QRect(230, 620, 46, 13));
        nocc->setFrameShape(QFrame::Box);
        nocc->setAlignment(Qt::AlignCenter);
        ipimage->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ipimage);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 21));
        ipimage->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ipimage);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ipimage->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ipimage);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ipimage->setStatusBar(statusBar);

        retranslateUi(ipimage);

        QMetaObject::connectSlotsByName(ipimage);
    } // setupUi

    void retranslateUi(QMainWindow *ipimage)
    {
        ipimage->setWindowTitle(QApplication::translate("ipimage", "MainWindow", 0));
        ipimage_2->setText(QString());
        opimage->setText(QString());
        loadimage->setText(QApplication::translate("ipimage", "Load Image", 0));
        lblWidth->setText(QApplication::translate("ipimage", "Width", 0));
        widthvalue->setText(QApplication::translate("ipimage", "TextLabel", 0));
        lblHeight->setText(QApplication::translate("ipimage", "Height", 0));
        heightvalue->setText(QApplication::translate("ipimage", "TextLabel", 0));
        lblCoordinate->setText(QApplication::translate("ipimage", "Pixel Coordinate", 0));
        lblMousePosition->setText(QApplication::translate("ipimage", "X = ? , Y = ?", 0));
        lblRGB->setText(QApplication::translate("ipimage", "RGB Value", 0));
        label_2->setText(QApplication::translate("ipimage", "Red", 0));
        label_3->setText(QApplication::translate("ipimage", "Green", 0));
        label_4->setText(QApplication::translate("ipimage", "Blue", 0));
        Redvalue->setText(QString());
        Greenvalue->setText(QString());
        Bluevalue->setText(QString());
        binarize->setText(QApplication::translate("ipimage", "Binarize", 0));
        dt8->setText(QApplication::translate("ipimage", "8 Distance Transform", 0));
        histogramequilization->setText(QApplication::translate("ipimage", "Histogram Equalization", 0));
        ccl4->setText(QApplication::translate("ipimage", "4 CCL", 0));
        colormap->setText(QApplication::translate("ipimage", "Add Colormap", 0));
        FDT->setText(QApplication::translate("ipimage", "FDT", 0));
        localmaxima->setText(QApplication::translate("ipimage", "Local Maxima", 0));
        label_5->setText(QApplication::translate("ipimage", "No. of connected components", 0));
        nocc->setText(QApplication::translate("ipimage", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class ipimage: public Ui_ipimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
