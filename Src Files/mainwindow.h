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
    void formatMap();
    void formatNPCs();
    void formatMonsters();
    void formatItems();
    void findpicture(int i);
private slots:
    void on_Start_clicked();
    void on_input_clicked();
    void on_north_clicked();
    void on_east_clicked();
    void on_south_clicked();
    void on_west_clicked();
    void on_talk_clicked();
    void on_take_clicked();
    void on_use_clicked();
    void on_inventory_clicked();
};


#endif // MAINWINDOW_H
