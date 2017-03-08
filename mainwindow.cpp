#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMouseEvent>
#include<cmath>
#define d1 3
#define d2 4
int cc=0,cc8=0,hist[sizex][sizey],arr[sizex][sizey],dt[sizex][sizey],ccl8[sizex][sizey],
ipmaxinten=0,maxintendt=0,FDT[sizex][sizey],r,c,value1,flag1,ccl[sizex][sizey],
localmax[sizex][sizey],binary[sizex][sizey];
double fuzzy[sizex][sizey];
bool inputimg=false, dtimg8=false, cclimg4=false,cclimg8=false,fdtimg8=false,bin=false,hg=false,lclm=false,hgdtimg8=false,ldt=false,lfdt=false;
struct node
{
    int data;
    struct node *next;
};
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

void MainWindow::on_loadimage_clicked()
{
    QString filepath;
    int i,j,red,green,blue,intensity;
    filepath=QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.bmp *.jpg *.jpeg)"));
    if(QString::compare(filepath,QString())!=0)
    {
        QImage image;
        QRgb value;
        bool valid;
        valid=image.load(filepath);
        if(valid)
        {
            ui->ipimage->setPixmap(QPixmap::fromImage(image));
        }
        c=image.width();
        r=image.height();
        ui->heightvalue->setNum(r);
        ui->widthvalue->setNum(c);
        ui->ipimage->setMouseTracking(true);
        image=image.convertToFormat(QImage::Format_RGB32);
        value=qRgb(0,0,0);
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value=image.pixel(i,j);
                red=qRed(value);
                green=qGreen(value);
                blue=qBlue(value);
                intensity=(red+green+blue)/3;
                arr[i][j]=intensity;
                if(intensity>ipmaxinten)ipmaxinten=intensity;
            }
        }
    }
}

/*void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint  local_inpt = ui->ipimage->mapFromGlobal(event->globalPos());
    QPointF img_coord_pt = ui->ipimage->mapFromGlobal(local_inpt);

    double x = img_coord_pt.x();
    double y = img_coord_pt.y();

    /* How can I get a gray level image here
    QRgb rgbValue = pix.toImage().pixel(x,y);

    ui->xcoordinatevalue->setText(QString::number(x));
    ui->ycoordinatevalue->setText(QString::number(y));
    //ui->label_Value->setText(QString::number(rgbValue));
}*/

void MainWindow::on_dt8_clicked()
{
    int i,j,min;
    double v;
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            if(arr[i][j]!=0)dt[i][j]=INT_MAX;
            else
                dt[i][j]=0;
        }
    }
    do
    {
        flag1=0;
        for(j=0;j<r;j++)//Forward Pass
        {
            for(i=0;i<c;i++)
            {
                min=dt[i][j];
                if((i-1>=0)&&((dt[i-1][j]+d1)<min))
                {
                    min=dt[i-1][j]+d1;
                    flag1++;
                }
                if((i-1>=0)&&(j-1>=0)&&((dt[i-1][j-1]+d2)<min))
                {
                    min=dt[i-1][j-1]+d2;
                    flag1++;
                }
                if((j-1>=0)&&((dt[i][j-1]+d1)<min))
                {
                    min=dt[i][j-1]+d1;
                    flag1++;
                }
                if((i+1<c)&&(j-1>=0)&&((dt[i+1][j-1]+d2)<min))
                {
                    min=dt[i+1][j-1]+d2;
                    flag1++;
                }
                dt[i][j]=min;
                //if(min>maxintendt)maxintendt=min;
            }           
        }
        for(j=r-1;j>=0;j--)//Backward Pass
        {
            for(i=c-1;i>=0;i--)
            {
                min=dt[i][j];
                if((i+1<c)&&(j+1<r)&&((dt[i+1][j+1]+d2)<min))
                {
                    min=dt[i+1][j+1]+d2;
                    flag1++;
                }
                if((i+1<c)&&((dt[i+1][j]+d1)<min))
                {
                    min=dt[i+1][j]+d1;
                    flag1++;
                }
                if((j+1<r)&&((dt[i][j+1]+d1)<min))
                {
                    min=dt[i][j+1]+d1;
                    flag1++;
                }
                if((i-1>=0)&&(j+1<r)&&((dt[i-1][j+1]+d2)<min))
                {
                    min=dt[i-1][j+1]+d2;
                    flag1++;
                }
                dt[i][j]=min;
                if(min>maxintendt)maxintendt=min;
            }            
        }
    }while(flag1);
    ui->heightvalue->setNum(maxintendt);
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            v=round((dt[i][j]/(double)maxintendt)*255);
            dt[i][j]=v;
        }
    }
    hgdtimg8=true;
    ldt=true;lfdt=false;
    inputimg=false;dtimg8=true;cclimg4=false;cclimg8=false;fdtimg8=false;bin=false;hg=false;lclm=false;
    drawimage();
}

void MainWindow::on_histogramequilization_clicked()
{
    if(hgdtimg8==true)
    {
     int intensity[256],index,i,j,max=-1;
     double normal[256];
     for(i=0;i<256;i++)intensity[i]=0;

     for(j=0;j<r;j++)
     {
        for(i=0;i<c;i++)
        {
            index=dt[i][j];
            intensity[index]=intensity[index]+1;
            if(index>max)max=index;
        }
     }
    ui->heightvalue->setNum(max);
    for(i=1;i<256;i++)//cummulative sum
    {
        intensity[i]=intensity[i]+intensity[i-1];
        normal[i]=(double)(intensity[i]/(double)(r*c))*255;
    }
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            index=dt[i][j];
            hist[i][j]=normal[index];
        }
    }
    }
    else if(fdtimg8==true)
    {

    }
    inputimg=false;dtimg8=false;cclimg4=false;cclimg8=false;fdtimg8=false;bin=false;hg=true;lclm=false;
    drawimage();
}

void MainWindow::on_ccl4_clicked()
{
    int i,j,curlabel=2,min,max,labeltrack[1000],maxlabel=-1;
    double x;
    struct node *curnode,*temp,*ar[1000];
    for(i=0;i<1000;i++)
    {
        ar[i]=(struct node *)malloc(sizeof(struct node));
        ar[i]->data=i;
        ar[i]->next=NULL;
        labeltrack[i]=0;
    }

   for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            if(arr[i][j]!=0)
                ccl[i][j]=1;
            else
                ccl[i][j]=0;
        }
    }

    //first pass
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            if(ccl[i][j]!=0)
            {
                if((i-1>=0&&j-1>=0&&(ccl[i-1][j]<=1)&&(ccl[i][j-1]<=1))||(i-1<0&&j-1<0))
                {
                    ccl[i][j]=curlabel;
                    curlabel=curlabel+1;
                }
                else if(i-1<0&&j-1>=0&&ccl[i][j-1]<=1)
                {
                    ccl[i][j]=curlabel;
                    curlabel=curlabel+1;
                }
                else if(j-1<0&&i-1>=0&&ccl[i-1][j]<=1)
                {
                    ccl[i][j]=curlabel;
                    curlabel=curlabel+1;
                }
                else if(i-1<0&&j-1>=0&&ccl[i][j-1]>1)
                {
                    ccl[i][j]=ccl[i][j-1];
                }
                else if(j-1<0&&i-1>=0&&ccl[i-1][j]>1)
                {
                    ccl[i][j]=ccl[i-1][j];
                }
                else if(i-1>=0&&j-1>=0&&(ccl[i-1][j]>1)&&(ccl[i][j-1]<=1))
                {
                    ccl[i][j]=ccl[i-1][j];
                }
                else if(i-1>=0&&j-1>=0&&(ccl[i-1][j]<=1)&&(ccl[i][j-1]>1))
                {
                    ccl[i][j]=ccl[i][j-1];
                }
                else if(i-1>=0&&j-1>=0&&(ccl[i][j-1]>1)&&(ccl[i-1][j]>1))
                {
                    min=ccl[i-1][j];
                    max=ccl[i][j-1];
                    if(ccl[i][j-1]<min)
                    {
                        min=ccl[i][j-1];
                        max=ccl[i-1][j];
                    }
                    ccl[i][j]=min;
                    curnode=(struct node *)malloc(sizeof(struct node));
                    //temp=(struct node *)malloc(sizeof(struct node));
                    curnode->data=max;
                    curnode->next=NULL;
                    temp=ar[min];
                    if(temp->next==NULL)
                    {
                        temp->next=curnode;
                    }
                    else
                    {
                        curnode->next=temp->next;
                        temp->next=curnode;
                    }
                    curnode=NULL;
                    temp=NULL;
                    free(temp);
                    free(curnode);
                }
            }
        }
    }
    //secondpass
    for(i=2;i<1000;i++)
    {
        temp=ar[i];
        while(temp->next!=NULL)
        {
            temp=temp->next;
            ar[temp->data]->data=ar[i]->data;
        }
    }

    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            ccl[i][j]=ar[ccl[i][j]]->data;
            labeltrack[ccl[i][j]]=labeltrack[ccl[i][j]]+1;
        }
    }
    for(i=2;i<1000;i++)
    {
        if(labeltrack[i]!=0)
        {
            cc++;
            if(i>maxlabel)maxlabel=i;
        }
    }
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            x=round(ccl[i][j]/(double)(maxlabel));
            ccl[i][j]=x*255;
        }
    }
    ui->nocc->setNum(cc);
    inputimg=false;dtimg8=false;cclimg4=true;cclimg8=false;fdtimg8=false;bin=false;hg=false;lclm=false;
    drawimage();
}

void MainWindow::on_binarize_clicked()
{
    int i,j;
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            if(arr[i][j]!=0)binary[i][j]=100;
            else
                binary[i][j]=0;
        }
    }
    inputimg=false;dtimg8=false;cclimg4=false;cclimg8=false;fdtimg8=false;bin=true;hg=false;lclm=false;
    drawimage();
}

void MainWindow::drawimage()
{
    int i,j,x;
    QImage opimg(c,r,QImage::Format_RGB32);
    QRgb value;
    if(dtimg8==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                if(dt[i][j]>255)
                {
                    //x=(dt[i][j]/(double)maxintendt);
                    //if(x!=0)printf("X is non zero");
                    //value1=(double)((double)x*255);
                     value1=255;
                }
                else value1=dt[i][j];
                value=qRgb(value1,value1,value1);
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    else if(hg==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value1=hist[i][j];
                value=qRgb(value1,value1,value1);
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    else if(bin==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value1=binary[i][j];
                value=qRgb(value1,value1,value1);
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    else if(fdtimg8==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value1=FDT[i][j];
                value=qRgb(value1,value1,value1);
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    else if(cclimg4==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value1=ccl[i][j];
                value=qRgb(value1,value1,value1);
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        cc=0;
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    else if(cclimg8==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value1=ccl8[i][j];
                if(value1!=0)
                {
                      if(cc8==1)
                      {
                       value=qRgb(0,0,255);
                      }
                      else if(cc8==2)
                      {
                        if(value1==2)
                        value=qRgb(0,0,255);
                        else
                        value=qRgb(255,0,0);
                      }
                      else if(cc8==3)
                      {

                      }
                }
                else
                {
                  value=qRgb(0,0,0);
                }
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        cc8=0;
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    else if(lclm==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                value1=localmax[i][j];
                if(value1!=0)value1=value1+25;
                if(value1>255)value1=255;
                value=qRgb(value1,value1,value1);
                opimg.setPixel(QPoint(i,j),value);
            }
        }
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
}

void MainWindow::on_colormap_clicked()
{
    int ri=1,gi=1,bi=249,red,green,blue,stp=4,x,i,j;
    red=ri;green=gi;blue=bi;
    if(dtimg8==true)
    {
    QImage opimg(c,r,QImage::Format_RGB32);
    QRgb value;
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            x=dt[i][j];
            if(x!=0)
            {
                if(x<=63)
                {
                    green=gi+(x-1)*stp;
                }
                else if(x>63&&x<=125)
                {
                    blue=bi-(x-63)*stp;

                }
                else if(x>125&&x<=187)
                {
                    red=ri+(x-125)*stp;
                }
                else if(x>187&&x<=249)
                {
                    green=249-(x-187)*stp;
                }
                else if(x>249&&x<=255)
                {
                    red=255;
                    green=0;
                    blue=0;
                }
                value=qRgb(red,green,blue);
            }
            else
            {
                value=qRgb(0,0,0);
            }

            opimg.setPixel(QPoint(i,j),value);
        }
    }
    ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    if(fdtimg8==true)
    {
    QImage opimg(c,r,QImage::Format_RGB32);
    QRgb value;
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            x=FDT[i][j];
            if(x!=0)
            {
                if(x<=63)
                {
                    green=gi+(x-1)*stp;
                }
                else if(x>63&&x<=125)
                {
                    blue=bi-(x-63)*stp;

                }
                else if(x>125&&x<=187)
                {
                    red=ri+(x-125)*stp;
                }
                else if(x>187&&x<=249)
                {
                    green=249-(x-187)*stp;
                }
                else if(x>249&&x<=255)
                {
                    red=255;
                    green=0;
                    blue=0;
                }
                value=qRgb(red,green,blue);
            }
            else
            {
                value=qRgb(0,0,0);
            }

            opimg.setPixel(QPoint(i,j),value);
        }
    }
    ui->opimage->setPixmap(QPixmap::fromImage(opimg));
    }
    if(cclimg4==true)
    {
        QImage opimg(c,r,QImage::Format_RGB32);
        QRgb value;
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                x=ccl[i][j];
                if(x!=0)
                {
                    if(x<=63)
                    {
                        green=gi+(x-1)*stp;
                    }
                    else if(x>63&&x<=125)
                    {
                        blue=bi-(x-63)*stp;

                    }
                    else if(x>125&&x<=187)
                    {
                        red=ri+(x-125)*stp;
                    }
                    else if(x>187&&x<=249)
                    {
                        green=249-(x-187)*stp;
                    }
                    else if(x>249&&x<=255)
                    {
                        red=255;
                        green=0;
                        blue=0;
                    }
                    value=qRgb(red,green,blue);
                }
                else
                {
                    value=qRgb(0,0,0);
                }

                opimg.setPixel(QPoint(i,j),value);
            }
        }
        ui->opimage->setPixmap(QPixmap::fromImage(opimg));
      }
}

void MainWindow::on_FDT_clicked()
{
    int i,j,mini,maxi=0,iter=0;
    double v;
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            v=arr[i][j]/(double)ipmaxinten;
            fuzzy[i][j]=v;
        }
    }
    for(j=0;j<r;j++)//prefdt
    {
        for(i=0;i<c;i++)
        {
            if(arr[i][j]!=0)
            {
                FDT[i][j]=INT_MAX;
            }
            else
            {
                FDT[i][j]=0;
            }
        }
    }
    do
    {
        iter++;
        flag1=0;
        for(j=0;j<r;j++)//Forward Pass
        {
            for(i=0;i<c;i++)
            {
                mini=FDT[i][j];
                if((i-1>=0)&&((FDT[i-1][j]+(fuzzy[i-1][j]+fuzzy[i][j])*3)<mini))
                {
                    mini=FDT[i-1][j]+(fuzzy[i-1][j]+fuzzy[i][j])*3;
                    flag1++;
                }
                if((i-1>=0)&&(j-1>=0)&&((FDT[i-1][j-1]+(fuzzy[i-1][j-1]+fuzzy[i][j])*4)<mini))
                {
                    mini=FDT[i-1][j-1]+(fuzzy[i-1][j-1]+fuzzy[i][j])*4;
                    flag1++;
                }
                if((j-1>=0)&&((FDT[i][j-1]+(fuzzy[i][j-1]+fuzzy[i][j])*3)<mini))
                {
                    mini=FDT[i][j-1]+(fuzzy[i][j-1]+fuzzy[i][j])*3;
                    flag1++;
                }
                if((i+1<c)&&(j-1>=0)&&((FDT[i+1][j-1]+(fuzzy[i+1][j-1]+fuzzy[i][j])*4)<mini))
                {
                    mini=FDT[i+1][j-1]+(fuzzy[i+1][j-1]+fuzzy[i][j])*4;
                    flag1++;
                }
                FDT[i][j]=mini;
                if(mini>maxi)maxi=mini;
            }
        }
        for(j=r-1;j>=0;j--)//Backward Pass
        {
            for(i=c-1;i>=0;i--)
            {
                mini=FDT[i][j];;
                if((i+1<c)&&(j+1<r)&&((FDT[i+1][j+1]+(fuzzy[i+1][j+1]+fuzzy[i][j])*4)<mini))
                {
                    mini=FDT[i+1][j+1]+(fuzzy[i+1][j+1]+fuzzy[i][j])*4;
                    flag1++;
                }
                if((i+1<c)&&((FDT[i+1][j]+(fuzzy[i+1][j]+fuzzy[i][j])*3)<mini))
                {
                    mini=FDT[i+1][j]+(fuzzy[i+1][j]+fuzzy[i][j])*3;
                    flag1++;
                }
                if((j+1<r)&&((FDT[i][j+1]+(fuzzy[i][j+1]+fuzzy[i][j])*3)<mini))
                {
                    mini=FDT[i][j+1]+(fuzzy[i][j+1]+fuzzy[i][j])*3;
                    flag1++;
                }
                if((i-1>=0)&&(j+1<r)&&((FDT[i-1][j+1]+(fuzzy[i-1][j+1]+fuzzy[i][j])*4)<mini))
                {
                    mini=FDT[i-1][j+1]+(fuzzy[i-1][j+1]+fuzzy[i][j])*4;
                    flag1++;
                }
                FDT[i][j]=mini;
                if(mini>maxi)maxi=mini;
            }
        }
    }while(flag1);
    for(j=0;j<r;j++)
    {
        for(i=0;i<c;i++)
        {
            v=round((FDT[i][j]/(double)maxi)*255);
            FDT[i][j]=v;
        }
    }
    lfdt=true;ldt=false;
    inputimg=false;dtimg8=false;cclimg4=false;cclimg8=false;fdtimg8=true;bin=false;hg=false;lclm=false;
    drawimage();
}

void MainWindow::on_localmaxima_clicked()
{
    int lmax,i,j,p,q,ws=2,flg;


    for(j=0;j<r;j++)
        for(i=0;i<c;i++)
            localmax[i][j] = 0;

    if(ldt==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                if(dt[i][j]!=0)
                {
                lmax=dt[i][j];
                flg=0;
                for(q=j-ws;q<=j+ws;q++)
                {
                    for(p=i-ws;p<=i+ws;p++)
                    {
                        if(p>=0&&p<c&&q>=0&&q<r)
                            if(dt[p][q]>lmax)
                            {
                                lmax=dt[p][q];
                                flg++;
                            }
                    }
                }
                if(flg==0)
                {
                    localmax[i][j]=lmax;
                }
                else
                    localmax[i][j]=0;
                }
            }
        }
    }
    else if(lfdt==true)
    {
        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                if(FDT[i][j]!=0)
                {
                lmax=FDT[i][j];
                flg=0;
                for(q=j-ws;q<=j+ws;q++)
                {
                    for(p=i-ws;p<=i+ws;p++)
                    {
                        if(p>=0&&p<c&&q>=0&&q<r)
                            if(FDT[p][q]>lmax)
                            {
                                lmax=FDT[p][q];
                                flg++;
                            }
                    }
                }
                if(flg==0)
                {
                    localmax[i][j]=lmax;
                }
                else
                    localmax[i][j]=0;
                }
            }
        }
    }
    lclm=true;inputimg=false;dtimg8=false;cclimg4=false;cclimg8=false;fdtimg8=false;bin=false;hg=false;
    drawimage();
}

void MainWindow::on_ccl8_clicked()
{
    int i,j,p,q,temp1,c1,c2,curlabel=1,nz,neighbor[4],component[1000],min;
    struct node *curnode,*temp,*ar[1000];
    cc8=0;
    for(i=0;i<1000;i++)
    {
        ar[i]=(struct node *)malloc(sizeof(struct node));
        ar[i]->data=i;
        ar[i]->next=NULL;
        component[i]=0;
    }
    for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
                if(arr[i][j]==0)ccl8[i][j]=1;
                else
                    ccl8[i][j]=0;
            }
        }

    //First pass

            for(j=0;j<r;j++)
            {
                for(i=0;i<c;i++)
                {
                    if(arr[i][j]!=0)
                    {
                        nz=0;
                        for(c1=0;c1<4;c1++)neighbor[c1]=0;
                        if(i-1>=0&&ccl8[i-1][j]>1)
                        {
                            neighbor[0]=ccl8[i-1][j];
                            nz++;
                        }
                        else if(i-1>=0&&j-1>=0&&ccl8[i-1][j-1]>1)
                        {
                            neighbor[1]=ccl8[i-1][j-1];
                            nz++;
                        }
                        else if(j-1>=0&&ccl8[i][j-1]>1)
                        {
                            neighbor[2]=ccl8[i][j-1];
                            nz++;
                        }
                        else if(i+1<c&&j-1>=0&&ccl8[i+1][j-1]>1)
                        {
                            neighbor[3]=ccl8[i+1][j-1];
                            nz++;
                        }

                        if(nz==0)
                        {
                            curlabel++;
                            ccl8[i][j]=curlabel;
                        }
                        else
                        {
                            for(p=0;p<4;p++)
                            {
                                min=p;
                                for(q=p+1;q<4;q++)
                                {
                                    if(neighbor[q]<neighbor[min])min=q;
                                }
                                temp1=neighbor[p];
                                neighbor[p]=neighbor[min];
                                neighbor[min]=temp1;
                            }
                            for(c1=0;c1<4;c1++)
                            {
                                if(neighbor[c1]>1)
                                {
                                    min=neighbor[c1];
                                    break;
                                }
                            }
                            ccl8[i][j]=min;
                            curnode=(struct node *)malloc(sizeof(struct node));
                            for(c2=c1+1;c2<4;c2++)
                            {
                                temp=ar[min];
                                curnode=(struct node *)malloc(sizeof(struct node));
                                curnode->data=neighbor[c2];
                                curnode->next=NULL;
                                if(temp->next==NULL)
                                {
                                    temp->next=curnode;
                                }
                                else
                                {
                                    curnode->next=temp->next;
                                    temp->next=curnode;
                                }
                                curnode=NULL;
                                temp=NULL;
                                free(temp);
                                free(curnode);
                            }
                        }
                    }
                }
            }
        //Second pass
    for(i=2;i<1000;i++)
    {
        temp=ar[i];
        while(temp->next!=NULL)
        {
            temp=temp->next;
            ar[temp->data]->data=ar[i]->data;
        }
    }

        for(j=0;j<r;j++)
        {
            for(i=0;i<c;i++)
            {
               ccl8[i][j]=ar[ccl8[i][j]]->data;
               component[ccl8[i][j]]=component[ccl8[i][j]]+1;
            }
        }
    for(i=2;i<1000;i++)
    {
        if(component[i]!=0)
        {
            cc8++;
        }
    }
    ui->nocc->setNum(cc8);
    inputimg=false;dtimg8=false;cclimg8=true;cclimg4=false;fdtimg8=false;bin=false;hg=false;lclm=false;
    drawimage();
}
