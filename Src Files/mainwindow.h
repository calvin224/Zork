#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ZorkUL.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
private slots:
    void on_Start_clicked();
    void on_input_clicked();
    void on_north_clicked();
    void on_east_clicked();
    void on_south_clicked();
    void on_west_clicked();
};

#endif // MAINWINDOW_H
