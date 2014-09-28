#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>

/*包含C库文件*/
extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
}



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QImage *frame;  //一帧图片
    unsigned char *pRgb;  //
    unsigned char *pY;
    unsigned char *pU;
    unsigned char *pV;

    QTimer *timer; //FPS

    FILE *file;

private slots:
    void paintEvent(QPaintEvent *evt);
   };

#endif // WIDGET_H
