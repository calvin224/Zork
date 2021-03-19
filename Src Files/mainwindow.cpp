
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <QPixmap>
#include <QApplication>
ZorkUL temp;

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
ui->textBrowser->setText(temp.printWelcome());
}

void MainWindow::on_input_clicked(){
  ui->textBrowser->setText(temp.play());
}



