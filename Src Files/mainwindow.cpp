
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <QPixmap>
#include <QApplication>
#include <QInputDialog>
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
  int index =  QInputDialog::getInt(this,"Who do you attack?","Type what you attack");
  string str = to_string(index);
  ui->textBrowser->setText(game.play(Command("attack",str)));

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

void MainWindow::on_talk_clicked(){
  QString str =  QInputDialog::getMultiLineText(this,"What Do you say?","Type what you say");
  string text = str.toLocal8Bit().constData();
  ui->textBrowser->setText(game.play(Command("talk",text)));
}

void MainWindow::on_take_clicked(){
    QString str =  QInputDialog::getMultiLineText(this,"What Do you take?","Type what you take");
    string text = str.toLocal8Bit().constData();
    ui->textBrowser->setText(game.play(Command("take",text)));
}
void MainWindow::on_use_clicked(){
    QString str =  QInputDialog::getMultiLineText(this,"What Do you use?","Type what you use");
    string text = str.toLocal8Bit().constData();
    ui->textBrowser->setText(game.play(Command("use",text)));

}

