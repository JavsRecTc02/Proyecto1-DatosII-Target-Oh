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

//METODO QUE LEE EL NOMBRE DEL PLAYER
void GameDisplay::readtext(QString T,QString Q){
    ui->playertag1->setText(QString(T));
    ui->playertag2->setText(QString (Q));
}

//METODO QUE SELECCIONE EL RESULTADO PARCIAL DEL JUGADOR ACTUAL

void GameDisplay::select_parcialresult(){
    if (player_2==1){
        parcial_result2();
    }else{
        parcial_result();
    }
}

//METODO QUE REDUCE EL TIMER CADA SEGUNDO
void GameDisplay::update_timer(){
    time= time.addSecs(-1);
    ui->timer_game->setText(time.toString("m:ss"));
}

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

    images_bytes = images.size()* sizeof(images[0]);
    ui->numbytes->setText(QString::number(images_bytes));

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

    game_starts=false;
    hit=false;

    time.setHMS(0,1,0);
    ui->timer_game->setText(time.toString("m:ss"));
    timer->start(1000);

    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    foreach(QPushButton* b, buttons){
        b->setEnabled(true);
        b->setStyleSheet("#"+b->objectName()+"{}");
    }
    ui->frame->setEnabled(true);
}

///////////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE DEFINE LAS CONDICIONES PARA GANAR O PERDER EL JUEGO
void GameDisplay::finish_result(){
    msgBox.setWindowTitle("Game Over");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setEscapeButton(QMessageBox::No);

    if (fault_couples==0){
        timer->stop();
        winner_result();
        //msgBox.setText("You Win! Points:" + QString::number(game_points)+"\nPlay again?");
        if(QMessageBox::Yes == msgBox.exec()){
            ui->frame->setEnabled(false);
            //Start_game();
            restart_game();
        }
        else{
            QCoreApplication::quit();
        }
    }
     else{
        if(time.toString()=="00:00:00"){
            timer->stop();
            ui->frame->setEnabled(false);
            winner_result();
            //msgBox.setText("You lose, Restart?");
            if (QMessageBox::Yes == msgBox.exec()){
                //Start_game();
                restart_game();
            }
            else{
                QCoreApplication::quit();
            }
        }
    }
}

//METODO QUE DEFINE EL GANADOR DEL JUEGO
void GameDisplay::winner_result(){
    if (game_points > game_points2){
        QString player1 = ui->playertag1->text();
        msgBox.setText("Player 1: " + player1 + " Win! Points:" + QString::number(game_points)+"\nPlay again?");
    }
    if (game_points==game_points2){
        msgBox.setText("Tied game! \nPlay again?");
    }
    if(game_points< game_points2){
        QString player2 = ui->playertag2->text();
        msgBox.setText("Player 2: " + player2 + " Win! Points:" + QString::number(game_points2)+"\nPlay again?");
    }
}

//METODO PARA VERIFICAR SI EL JUGADOR 1 ACERTO LA PAREJA
void GameDisplay::parcial_result(){
    if(repart[target_current->objectName()]==repart[target_previous->objectName()]){
        game_points+=100;
        if (hit == true){
            game_points+=100;
            ui->Points_2->setText(QString::number(game_points));
            hit=false;
        }
        ui->Points_2->setText(QString::number(game_points));
        fault_couples--;
        ui->frame->setEnabled(false);
        QTimer::singleShot(1200, this, SLOT(refresh_targets()));
        finish_result();
    }else{
        game_points-=20;
        if (hit == true){
            game_points-=40;
            ui->Points_2->setText(QString::number(game_points));
            hit=false;
        }
        ui->Points_2->setText(QString::number(game_points));
        ui->frame->setEnabled(false);
        QTimer::singleShot(1000, this, SLOT(restart_targets()));
    }
    player_2 = 1;
    //ui->play1->setStyleSheet("background: black");
    //ui->play2->setStyleSheet("background: green");
 }

//METODO PARA VERIFICAR SI EL JUGADOR 2 ACERTO LA PAREJA
void GameDisplay::parcial_result2(){
    if(repart[target_current->objectName()]==repart[target_previous->objectName()]){
        game_points2+=100;
        if (hit2 == true){
            game_points2+=100;
            ui->Points_22->setText(QString::number(game_points2));
            hit2=false;
        }
        ui->Points_22->setText(QString::number(game_points2));
        fault_couples--;
        ui->frame->setEnabled(false);
        QTimer::singleShot(1200, this, SLOT(refresh_targets()));
        finish_result();
    }else{
        game_points2-=20;
        if (hit2 == true){
            game_points2-=40;
            ui->Points_22->setText(QString::number(game_points2));
            hit2=false;
        }
        ui->Points_22->setText(QString::number(game_points2));
        ui->frame->setEnabled(false);
        QTimer::singleShot(1000, this, SLOT(restart_targets()));
    }
    player_2 = 0;
    //ui->play1->setStyleSheet("background: green");
    //ui->play2->setStyleSheet("background: black");
 }


//METODO QUE ACTUALIZA EL TIMER Y EL ESTADO ACTUAL DEL JUEGO
void GameDisplay::update_estade(){
    update_timer();
    finish_result();
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA SELECCIONAR DOS TARJETAS
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


////////////////////////////////////// VENTAJAS PLAYER ////////////////////////////////////////
//METODO PARA LA VENTAJA DE RANDOMIZE

void GameDisplay::randomize_images(){
    ui->ven_tag->setText(QString("RANDOMIZE!"));
    ui->frame->setEnabled(false);
    random_image(targets, repart, images);
    random_target(targets);
    ui->frame->setEnabled(true);
    ui->ven_random->setEnabled(false);
    ui->ven_random->setStyleSheet("background: black");

}

//METODO PARA LA VENTAJA RANDOMIZE

void GameDisplay::randomize_images2(){
    ui->ven_tag->setText(QString("RANDOMIZE!"));
    ui->frame->setEnabled(false);
    random_image(targets, repart, images);
    random_target(targets);
    ui->frame->setEnabled(true);
    ui->ven_random2->setEnabled(false);
    ui->ven_random2->setStyleSheet("background: black");

}


//METODOS PARA LA VENTAJA DEL TIMER PLAYER 1

void GameDisplay::up_timer(){
    time= time.addSecs(15);
    ui->ven_tag->setText(QString("INCREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer1->setEnabled(false);
    ui->ven_timer1->setStyleSheet("background: black");
    ui->ven_timer2->setEnabled(false);
    ui->ven_timer2->setStyleSheet("background: black");

}
void GameDisplay::down_timer(){
    time= time.addSecs(-15);
    ui->ven_tag->setText(QString("DECREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer1->setEnabled(false);
    ui->ven_timer1->setStyleSheet("background: black");
    ui->ven_timer2->setEnabled(false);
    ui->ven_timer2->setStyleSheet("background: black");
}

//METODO PARA LA VENTAJA DEL TIMER PLAYER 2

void GameDisplay::up_timer2(){
    time= time.addSecs(15);
    ui->ven_tag->setText(QString("INCREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer01->setEnabled(false);
    ui->ven_timer01->setStyleSheet("background: black");
    ui->ven_timer02->setEnabled(false);
    ui->ven_timer02->setStyleSheet("background: black");

}
void GameDisplay::down_timer2(){
    time= time.addSecs(-15);
    ui->ven_tag->setText(QString("DECREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer01->setEnabled(false);
    ui->ven_timer01->setStyleSheet("background: black");
    ui->ven_timer02->setEnabled(false);
    ui->ven_timer02->setStyleSheet("background: black");
}

//METODO PARA LA VENTAJA DOUBLE PLAYER 1
void GameDisplay::double_points(){
    hit = true;
    ui->ven_double->setEnabled(false);
    ui->ven_double->setStyleSheet("background: black");

}

//METODO PARA LA VENTAJA DOUBLE PLAYER 2
void GameDisplay::double_points2(){
    hit2 = true;
    ui->ven_double2->setEnabled(false);
    ui->ven_double2->setStyleSheet("background: black");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA REINICIAR EL JUEGO
void GameDisplay::restart_game(){
    hide();
    QString player_1 = ui->playertag1->text();
    QString player_2 = ui->playertag2->text();
    newgame = new GameDisplay;
    newgame->readtext(player_1,player_2);
    newgame->show();
}

GameDisplay::~GameDisplay()
{
    delete ui;
}


