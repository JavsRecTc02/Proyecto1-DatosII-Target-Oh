 #include "gamedisplay.h"
#include "ui_gamedisplay.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator64>
#include <QDebug>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::remove;

GameDisplay::GameDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameDisplay)
{
    ui->setupUi(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_estade()));
    QObject::connect(ui->target01,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target02,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target03,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target04,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target05,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target06,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target07,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target08,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target09,SIGNAL(clicked()),  this, SLOT(target_select()));
    QObject::connect(ui->target010,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target011,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target012,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target013,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target014,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target015,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target016,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target017,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target018,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target019,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target020,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target021,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target022,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target023,SIGNAL(clicked()), this, SLOT(target_select()));
    QObject::connect(ui->target024,SIGNAL(clicked()), this, SLOT(target_select()));


    //OBJETOS DE VENTAJA PLAYER 1
    QObject::connect(ui->ven_random,SIGNAL(clicked()), this, SLOT(randomize_images()));
    QObject::connect(ui->ven_timer1,SIGNAL(clicked()), this, SLOT(up_timer()));
    QObject::connect(ui->ven_timer2,SIGNAL(clicked()), this, SLOT(down_timer()));
    QObject::connect(ui->ven_double,SIGNAL(clicked()), this, SLOT(double_points()));

    //OBJETOS DE VENTAJA PLAYER 2
    QObject::connect(ui->ven_random2,SIGNAL(clicked()), this, SLOT(randomize_images2()));
    QObject::connect(ui->ven_timer01,SIGNAL(clicked()), this, SLOT(up_timer2()));
    QObject::connect(ui->ven_timer02,SIGNAL(clicked()), this, SLOT(down_timer2()));
    QObject::connect(ui->ven_double2,SIGNAL(clicked()), this, SLOT(double_points2()));

    Start_game();

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE LEE EL NOMBRE DEL PLAYER
void GameDisplay::readtext(QString T,QString Q){
    ui->playertag1->setText(QString(T));
    ui->playertag2->setText(QString (Q));
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE REDUCE EL TIMER CADA SEGUNDO
void GameDisplay::update_timer(){
    time= time.addSecs(-1);
    ui->timer_game->setText(time.toString("m:ss"));
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PRINCIPAL QUE POSEE TODO LO NECESARIO PARA INICIAR EL JUEGO
void GameDisplay::Start_game(){

    targets= {"target01", "target02", "target03", "target04",
              "target05", "target06", "target07", "target08",
              "target09", "target010", "target011", "target012",
              "target013", "target014", "target015", "target016",
              "target017", "target018", "target019", "target020",
              "target021", "target022","target023", "target024"};


    images={"01.png","02.png","03.png","04.png","05.png","06.png","07.png","08.png","09.png","010.png",
           "011.png","012.png"};

    //images_bytes = images.size()* sizeof(images[0]);
    //ui->numbytes->setText(QString::number(images_bytes));

    random_player();
    block_player();

    limit_images = 11;
    limit_targets = 23;
    fault_couples = 12;

    game_points = 0;
    ui->Points_2->setText(QString::number(game_points));
    game_points2 = 0;
    ui->Points_22->setText(QString::number(game_points2));

    random_target(targets);
    random_image(targets, repart, images);
    bytes_images();

    game_starts=false;
    hit=false;

    time.setHMS(0,1,30);
    ui->timer_game->setText(time.toString("m:ss"));
    timer->start(1000);

    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    foreach(QPushButton* b, buttons){
        b->setEnabled(true);
        b->setStyleSheet("#"+b->objectName()+"{}");
    }
    ui->frame->setEnabled(true);
}

/////////////////////////////////////////////////////////////////////////////////////////


//METODO QUE ACTUALIZA EL TIMER Y EL ESTADO ACTUAL DEL JUEGO
void GameDisplay::update_estade(){
    update_timer();
    finish_result();
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA SELECCIONAR DOS TARJETAS//
void GameDisplay::target_select(){
    target_current=qobject_cast<QPushButton*>(sender());
    ui->ven_tag->setText(QString(""));
    show_image();
    target_current->setEnabled(false);
    if(!game_starts){
        target_previous=target_current;
        game_starts = true;
    }
    else{
        select_parcialresult();
        block_player();
        game_starts = false;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

GameDisplay::~GameDisplay()
{
    delete ui;
}


