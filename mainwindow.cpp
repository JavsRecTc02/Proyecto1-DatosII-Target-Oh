#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamedisplay.h"
#include "ui_gamedisplay.h"

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

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA CREAR UNA SEGUNDA VENTANA//
void MainWindow::on_play_clicked()
{
    hide();
    QString player_1 = ui->nick1->text();
    QString player_2 = ui->nick2->text();
    gameDisplay = new GameDisplay(this);
    gameDisplay->readtext(player_1,player_2);
    gameDisplay->show();

}

/////////////////////////////////////////////////////////////////////////////////////////

