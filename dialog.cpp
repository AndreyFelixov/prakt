#include "dialog.h"
#include "ui_dialog.h"
#include <QTime>
#include "glob.h"

int mod;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->hour->hide();
    ui->min->hide();
    ui->pushButton->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_budil_clicked()
{
    ui->budil->setDisabled(true);
    ui->timer->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->hour->show();
    ui->min->show();
    ui->pushButton->show();
    QTime t = QTime::currentTime();
    ui->hour->setValue(t.hour());
    ui->min->setValue(t.minute());
    mod = 2;
}

void Dialog::on_timer_clicked()
{
    ui->timer->setDisabled(true);
    ui->budil->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->hour->show();
    ui->min->show();
    ui->pushButton->show();
    ui->hour->setValue(0);
    ui->min->setValue(0);
    mod = 1;
}

void Dialog::on_pushButton_clicked_44()
{
    if (mod==1)
    {
        ttimer.setHMS(ui->hour->value(),ui->min->value(),0);
        tibu=11;
    }
    if (mod==2)
    {
        tbudil.setHMS(ui->hour->value(),ui->min->value(),0);
        buti=11;
    }
    if (mod==3)
    {
        tttime.setHMS(ui->hour->value(),ui->min->value(),0);
    }
    ui->pushButton->setDisabled(true);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->timer->setDisabled(false);
    ui->budil->setDisabled(false);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton->setDisabled(false);
    ui->hour->show();
    ui->min->show();
    ui->pushButton->show();
    ui->hour->setValue(0);
    ui->min->setValue(0);
    mod = 3;
}
