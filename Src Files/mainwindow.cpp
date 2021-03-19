
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <QPixmap>
#include <QApplication>
ZorkUL game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Start_clicked(){
ui->textBrowser->setText(game.printWelcome());
}

void MainWindow::on_input_clicked(){
  ui->textBrowser->setText(game.play( Command("attack","1")));

}
void MainWindow::on_north_clicked(){
    ui->textBrowser->setText(game.play( Command("go","north")));

}
void MainWindow::on_east_clicked(){
ui->textBrowser->setText(game.play( Command("go","east")));
}
void MainWindow::on_south_clicked(){
ui->textBrowser->setText(game.play( Command("go","south")));
}
void MainWindow::on_west_clicked(){
ui->textBrowser->setText(game.play( Command("go","west")));
}



