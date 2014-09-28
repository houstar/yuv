#include "widget.h"
#include "ui_widget.h"
#include "yuv2rgb.h"


#define WIDTH (176)
#define HEIGHT (144)

bool YV12ToBGR24_Pinknoise(unsigned char* pYUV,unsigned char* pBGR24,int width,int height)
{
    if (width < 1 || height < 1 || pYUV == NULL || pBGR24 == NULL)
        return false;
    unsigned char *yData = pYUV;
    unsigned char *vData = &pYUV[width * height];
    unsigned char *uData = &vData[width * height >> 2];
    yuv420_2_rgb888(pBGR24,yData,uData,vData,width,height,width,width>>1,width*3,yuv2rgb565_table,0);
    return true;
}


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1024,768);
    ui->label->setGeometry(0,0,1024,768);

    file = fopen("/home/houstar/out.yuv","rb");
    if(file == NULL){
        ui->label->setText("Error");
    }


    pY = (unsigned char *)malloc(WIDTH*HEIGHT*sizeof(char)*3);

    pRgb = (unsigned char *)malloc(WIDTH*HEIGHT*sizeof(char)*3);

   // painter = new QPainter(this);
    frame = new QImage(pRgb,WIDTH,HEIGHT,QImage::Format_RGB888);


    fseek(file,0,SEEK_END);
    int lSize=ftell(file);
    rewind(file);

    fread(pY,1,lSize,file);
    fclose(file);


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(30);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::paintEvent(QPaintEvent *evt)
{

    YV12ToBGR24_Pinknoise(pY,pRgb,WIDTH,HEIGHT);
   frame->loadFromData(pRgb,WIDTH*HEIGHT*3*sizeof(char));
//   frame->load("/home/houstar/baidu.jpg");


   ui->label->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));
}

