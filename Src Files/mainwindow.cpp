
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <QPixmap>
#include <QApplication>
#include <QInputDialog>
#include <QLabel>
ZorkUL game;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setText("Press start to play!");

}



void MainWindow::formatMonsters(){
    QPixmap mainchar(":/Images/joe.png");
    ui->mainchar->setPixmap(mainchar.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix;
    QPixmap pix2;
    QPixmap pix3;
    QPixmap pix4;

    for(int i = 0; i < game.getammountofem();i++){
           if(i == 0){
               pix = QPixmap(QString::fromStdString(game.getmoninarray(i).getimage()));
            }
            if(i == 1){
               pix2 = QPixmap(QString::fromStdString(game.getmoninarray(i).getimage()));
           }
            if(i == 2){
               pix3 = QPixmap(QString::fromStdString(game.getmoninarray(i).getimage()));
            }
            if(i == 3){
               pix4 = QPixmap(QString::fromStdString(game.getmoninarray(i).getimage()));
           }

        }

    if(game.getammountofem() == 0){
        ui->Enemy1->clear();
        ui->Enemy2->clear();
        ui->Enemy3->clear();
        ui->Enemy4->clear();
    }
    if(game.getammountofem() ==1) {
    ui->Enemy1->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy2->clear();
    ui->Enemy3->clear();
    ui->Enemy4->clear();
    }
    if(game.getammountofem() ==2) {
    ui->Enemy1->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy2->setPixmap(pix2.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy3->clear();
    ui->Enemy4->clear();
    }
    if(game.getammountofem() ==3) {
    ui->Enemy1->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy2->setPixmap(pix2.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy3->setPixmap(pix3.scaled(100,100,Qt::KeepAspectRatio));}
    ui->Enemy4->clear();

    if(game.getammountofem()== 4) {
    ui->Enemy1->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy2->setPixmap(pix2.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy3->setPixmap(pix3.scaled(100,100,Qt::KeepAspectRatio));
    ui->Enemy4->setPixmap(pix4.scaled(100,100,Qt::KeepAspectRatio));
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Start_clicked(){
ui->textBrowser->setText(game.printWelcome());
formatMonsters();
}

void MainWindow::on_input_clicked(){
  int index =  QInputDialog::getInt(this,"Who do you attack?","Type what you attack");
  string str = to_string(index);
  ui->textBrowser->setText(game.play(Command("attack",str)));
  formatMonsters();
 }


void MainWindow::on_north_clicked(){
    ui->textBrowser->setText(game.play( Command("go","north")));
    formatMonsters();
}
void MainWindow::on_east_clicked(){
ui->textBrowser->setText(game.play( Command("go","east")));
formatMonsters();
}
void MainWindow::on_south_clicked(){
ui->textBrowser->setText(game.play( Command("go","south")));
formatMonsters();
}
void MainWindow::on_west_clicked(){
ui->textBrowser->setText(game.play( Command("go","west")));
formatMonsters();
}

void MainWindow::on_talk_clicked(){
  QString str =  QInputDialog::getMultiLineText(this,"What Do you say?","Type what you say");
  string text = str.toLocal8Bit().constData();
  ui->textBrowser->setText(game.play(Command("talk",text)));
  formatMonsters();
}

void MainWindow::on_take_clicked(){
    QString str =  QInputDialog::getMultiLineText(this,"What Do you take?","Type what you take");
    string text = str.toLocal8Bit().constData();
    ui->textBrowser->setText(game.play(Command("take",text)));
    formatMonsters();
}
void MainWindow::on_use_clicked(){
    QString str =  QInputDialog::getMultiLineText(this,"What Do you use?","Type what you use");
    string text = str.toLocal8Bit().constData();
    ui->textBrowser->setText(game.play(Command("use",text)));
    formatMonsters();
}

