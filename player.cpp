#include "player.h"
#include "gamedisplay.h"


Player::Player(QWidget *parent)
    : QMainWindow{parent}
{

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA JUGADOR INICIAL RANDOM//
void GameDisplay::random_player(){

    std::uniform_int_distribution<int>distribution(0,1);
    for(int ix = 0; ix<1; ++ix){
        double value = distribution(*QRandomGenerator::global());
    player_2 = value;
    }
    //ui->prueba->setText(QString::number(player_2));

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE BLOQUEE EL FRAME CON LOS BUTTONS DE AYUDAS//

void GameDisplay::block_player(){
    if (player_2 == 1){
        //parcial_result2();
        ui->play2->setStyleSheet("background: lightgreen");
        ui->play1->setStyleSheet("background: black");
        ui->frame_tag1->setEnabled(false);
        ui->frame_tag2->setEnabled(true);
    }else{
        //parcial_result();
        ui->play1->setStyleSheet("background: lightgreen");
        ui->play2->setStyleSheet("background: black");
        ui->frame_tag2->setEnabled(false);
        ui->frame_tag1->setEnabled(true);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
