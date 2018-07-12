#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

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
    void on_budil_clicked();

    void slotTimerAlarm();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_vkl_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};

#endif // MAINWINDOW_H
