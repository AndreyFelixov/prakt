#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "glob.h"
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QPainter>
#include <QSound>

int coco = 1, mode = 1, vkll=1;
QTime t;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tibu=0;buti=0;

    ui->lcdbh->hide();
    ui->lcdbm->hide();
    ui->bud->hide();
    ui->hour->hide();
    ui->minute->hide();
    ui->second->hide();
    ui->label->hide();

    setWindowTitle("Clock");
    QTime t;
    t = QTime::currentTime();
    tttime = QTime::currentTime();
    ui->lcdh->display(t.hour());
    ui->lcdm->display(t.minute());
    ui->lcds->display(t.second());
    ui->label->setPixmap(QPixmap(":/с.png"));
    ui->t1->setPixmap(QPixmap(":/t.png"));
    ui->t2->setPixmap(QPixmap(":/t.png"));
    ui->t3->setPixmap(QPixmap(":/t.png"));
    ui->t4->setPixmap(QPixmap(":/t.png"));
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_budil_clicked()
{

    if (coco==1)
    {
       ui->budil->setText("Электронные");
       ui->lcdh->hide();
       ui->lcdm->hide();
       ui->lcds->hide();
       ui->pushButton_2->hide();
       ui->t1->hide();
       ui->t2->hide();
       ui->t3->hide();
       ui->t4->hide();
       ui->hour->show();
       ui->minute->show();
       ui->second->show();
       ui->label->show();
       coco=0;
    }
    else
    {
        ui->budil->setText("Аналоговые");
        ui->hour->hide();
        ui->minute->hide();
        ui->second->hide();
        ui->label->hide();
        ui->pushButton_2->show();
        ui->lcdh->show();
        ui->lcdm->show();
        ui->lcds->show();
        ui->t1->show();
        ui->t2->show();
        ui->t3->show();
        ui->t4->show();
        coco=1;
    }
}

void MainWindow::slotTimerAlarm()
{
    ttimer = ttimer.addSecs(-1);
    t=t.addSecs(1);
    tttime=tttime.addSecs(1);
    if (mode==1)
    {
        ui->lcdh->display(tttime.hour());
        ui->lcdm->display(tttime.minute());
        ui->lcds->display(tttime.second());
    }
    else
    {
        ui->lcdh->display(ttimer.hour());
        ui->lcdm->display(ttimer.minute());
        ui->lcds->display(ttimer.second());
    }
    if (ttimer.hour()==0 && ttimer.minute()==0 && ttimer.second()==0)
    {
         QSound::play(":/budil.wav");
         tibu=0;
         mode=1;
         ui->pushButton_2->setText("Таймер");
    }

    if (tbudil.hour()==tttime.hour() && tbudil.minute()==tttime.minute() && buti==11)
    {
        buti=0;
        if (vkll==1)
        {
            QSound::play(":/budil.wav");
        }
    }

    if (buti==11)
    {
        ui->lcdbh->display(tbudil.hour());
        ui->lcdbm->display(tbudil.minute());
        ui->lcdbh->show();
        ui->lcdbm->show();
        ui->bud->show();
        ui->vkl->show();

    }
    else
    {
        ui->lcdbh->hide();
        ui->lcdbm->hide();
        ui->bud->hide();
        ui->vkl->hide();
    }

    if (tibu==11)
    {
        ui->pushButton_2->setDisabled(false);
    }
    else
    {
        ui->pushButton_2->setDisabled(true);
    }

    QPixmap shipPixels(":/s.png");
    QPixmap rotatePixmap(shipPixels.size());
    rotatePixmap.fill(Qt::transparent);
    QPainter p(&rotatePixmap);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotatePixmap.size().width() / 2, rotatePixmap.size().height() / 2);
    p.rotate(360*tttime.second()/60);
    p.translate(-rotatePixmap.size().width() / 2, -rotatePixmap.size().height() / 2);
    p.drawPixmap(0, 0, shipPixels);
    p.end();
    shipPixels = rotatePixmap;
    ui->second->setPixmap(shipPixels);

    QPixmap shipPixels1(":/m.png");
    QPixmap rotatePixmap1(shipPixels1.size());
    rotatePixmap1.fill(Qt::transparent);
    QPainter p1(&rotatePixmap1);
    p1.setRenderHint(QPainter::Antialiasing);
    p1.setRenderHint(QPainter::SmoothPixmapTransform);
    p1.setRenderHint(QPainter::HighQualityAntialiasing);
    p1.translate(rotatePixmap1.size().width() / 2, rotatePixmap1.size().height() / 2);
    p1.rotate(6*tttime.minute()+tttime.second()/10);
    p1.translate(-rotatePixmap1.size().width() / 2, -rotatePixmap1.size().height() / 2);
    p1.drawPixmap(0, 0, shipPixels1);
    p1.end();
    shipPixels1 = rotatePixmap1;
    ui->minute->setPixmap(shipPixels1);

    QPixmap shipPixels2(":/h.png");
    QPixmap rotatePixmap2(shipPixels2.size());
    rotatePixmap2.fill(Qt::transparent);
    QPainter p2(&rotatePixmap2);
    p2.setRenderHint(QPainter::Antialiasing);
    p2.setRenderHint(QPainter::SmoothPixmapTransform);
    p2.setRenderHint(QPainter::HighQualityAntialiasing);
    p2.translate(rotatePixmap2.size().width() / 2, rotatePixmap2.size().height() / 2);
    p2.rotate(tttime.hour()*30 + tttime.minute()/2);
    p2.translate(-rotatePixmap2.size().width() / 2, -rotatePixmap2.size().height() / 2);
    p2.drawPixmap(0, 0, shipPixels2);
    p2.end();
    shipPixels2 = rotatePixmap2;
    ui->hour->setPixmap(shipPixels2);

}

void MainWindow::on_pushButton_clicked()
{
    Dialog *dia=new Dialog;
    dia->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (mode==1)
    {
        if (tibu==11)
        {
            mode=2;
            ui->pushButton_2->setText("Часы");
        }
    }
    else
    {
        mode=1;
        ui->pushButton_2->setText("Таймер");
    }
}

void MainWindow::on_vkl_clicked()
{
    if (vkll==1)
    {
        ui->vkl->setText("Включить сигнал");
        vkll=2;
    }
    else
    {
        ui->vkl->setText("Отключить сигнал");
        vkll=1;
    }
}
