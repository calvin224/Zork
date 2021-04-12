
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
    QPixmap bkgnd(":/Images/zorkuiRoomA.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

void MainWindow::formatMap(){
    QPixmap pix (QString::fromStdString(game.currentRoom->getMapImage()));
    ui->Map->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));

    QPixmap background = QPixmap(QString::fromStdString(game.currentRoom->getRoomImage()));
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void MainWindow::formatMonsters(){
    QPixmap mainchar(":/Images/joe.png");
    ui->mainchar->setPixmap(mainchar.scaled(200,200,Qt::KeepAspectRatio));
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

void MainWindow::formatItems(){
    QPixmap pix;
    QPixmap pix2;
    QPixmap pix3;
    QPixmap pix4;
    QPixmap pix5;
    QPixmap pix6;
    QPixmap pix7;
    QPixmap pix8;


    for(int i = 0; i < game.getAmountofItems();i++){
           if(i == 0){
               pix = QPixmap(QString::fromStdString(game.getIteminList(i).getimage()));
            }
            if(i == 1){
               pix2 = QPixmap(QString::fromStdString(game.getIteminList(i).getimage()));
           }
            if(i == 2){
               pix3 = QPixmap(QString::fromStdString(game.getIteminList(i).getimage()));
            }
            if(i == 3){
               pix4 = QPixmap(QString::fromStdString(game.getIteminList(i).getimage()));
           }

        }

    if(game.getAmountofItems() == 0){
        ui->Item1->clear();
        ui->Item2->clear();
        ui->Item3->clear();
        ui->Item4->clear();
    }
    if(game.getAmountofItems() ==1) {
    ui->Item1->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item2->clear();
    ui->Item3->clear();
    ui->Item4->clear();
    }
    if(game.getAmountofItems() ==2) {
    ui->Item1->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item2->setPixmap(pix2.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item3->clear();
    ui->Item4->clear();
    }
    if(game.getAmountofItems() ==3) {
    ui->Item1->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item2->setPixmap(pix2.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item3->setPixmap(pix3.scaled(80,80,Qt::KeepAspectRatio));}
    ui->Item4->clear();

    if(game.getAmountofItems() == 4) {
    ui->Item1->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item2->setPixmap(pix2.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item3->setPixmap(pix3.scaled(80,80,Qt::KeepAspectRatio));
    ui->Item4->setPixmap(pix4.scaled(80,80,Qt::KeepAspectRatio));
    }

    for(int i = 0; i < game.getAmountofInvItems();i++){
           if(i == 0){
               pix5 = QPixmap(QString::fromStdString(game.getIteminInventory(i).getimage()));
            }
            if(i == 1){
               pix6 = QPixmap(QString::fromStdString(game.getIteminInventory(i).getimage()));
           }
            if(i == 2){
               pix7 = QPixmap(QString::fromStdString(game.getIteminInventory(i).getimage()));
            }
            if(i == 3){
               pix8 = QPixmap(QString::fromStdString(game.getIteminInventory(i).getimage()));
           }

        }

    if(game.getAmountofInvItems() == 0){
        ui->PlayerItem1->clear();
        ui->PlayerItem2->clear();
        ui->PlayerItem3->clear();
        ui->PlayerItem4->clear();
    }
    if(game.getAmountofInvItems() ==1) {
    ui->PlayerItem1->setPixmap(pix5.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem2->clear();
    ui->PlayerItem3->clear();
    ui->PlayerItem4->clear();
    }
    if(game.getAmountofInvItems() ==2) {
    ui->PlayerItem1->setPixmap(pix5.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem2->setPixmap(pix6.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem3->clear();
    ui->PlayerItem4->clear();
    }
    if(game.getAmountofInvItems() ==3) {
    ui->PlayerItem1->setPixmap(pix5.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem2->setPixmap(pix6.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem3->setPixmap(pix7.scaled(80,80,Qt::KeepAspectRatio));}
    ui->PlayerItem4->clear();

    if(game.getAmountofInvItems() == 4) {
    ui->PlayerItem1->setPixmap(pix5.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem2->setPixmap(pix6.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem3->setPixmap(pix7.scaled(80,80,Qt::KeepAspectRatio));
    ui->PlayerItem4->setPixmap(pix8.scaled(80,80,Qt::KeepAspectRatio));
    }

    if (game.currentRoom->shortDescription() == "Hidden Shrine" && game.currentRoom->addItemFromRoom("Enchanted Sword") >= 0) {
    QPixmap shrine(":/Images/swordStone.png");
    ui->ShrineItem->setPixmap(shrine.scaled(100,100,Qt::KeepAspectRatio));
    } else {
        ui->ShrineItem->clear();
    }
}

void MainWindow::formatNPCs(){
    if (game.currentRoom->shortDescription() == "Main Hallway") {
    QPixmap NPC(":/Images/oldman.png");
    ui->NPC->setPixmap(NPC.scaled(200,200,Qt::KeepAspectRatio));
    } else {
        ui->NPC->clear();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Start_clicked(){
ui->textBrowser->setText(game.printWelcome());
formatMonsters();
formatItems();
formatMap();
formatNPCs();
}

void MainWindow::on_input_clicked(){
  int index =  QInputDialog::getInt(this,"Who do you attack?","Type what you attack");
  string str = to_string(index);
  ui->textBrowser->setText(game.play(Command("attack",str)));
  formatMonsters();
  formatItems();
  formatMap();
  formatNPCs();
 }


void MainWindow::on_north_clicked(){
    ui->textBrowser->setText(game.play( Command("go","north")));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}
void MainWindow::on_east_clicked(){
    ui->textBrowser->setText(game.play( Command("go","east")));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}
void MainWindow::on_south_clicked(){
    ui->textBrowser->setText(game.play( Command("go","south")));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}
void MainWindow::on_west_clicked(){
    ui->textBrowser->setText(game.play( Command("go","west")));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}

void MainWindow::on_talk_clicked(){
  QString str =  QInputDialog::getMultiLineText(this,"What Do you say?","Type what you say");
  string text = str.toLocal8Bit().constData();
  ui->textBrowser->setText(game.play(Command("talk",text)));
  formatMonsters();
  formatItems();
  formatMap();
}

void MainWindow::on_take_clicked(){
    QString str =  QInputDialog::getMultiLineText(this,"What Do you take?","Type what you take");
    string text = str.toLocal8Bit().constData();
    ui->textBrowser->setText(game.play(Command("take",text)));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}
void MainWindow::on_use_clicked(){
    QString str =  QInputDialog::getMultiLineText(this,"What Do you use?","Type what you use");
    string text = str.toLocal8Bit().constData();
    ui->textBrowser->setText(game.play(Command("use",text)));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}
void MainWindow::on_inventory_clicked(){
    ui->textBrowser->setText(game.play( Command("inventory","")));
    formatMonsters();
    formatItems();
    formatMap();
    formatNPCs();
}

