#include "restartgame.h"

Restartgame::Restartgame(QWidget *parent)
    : QMainWindow{parent}
{

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA REINICIAR EL JUEGO//
void GameDisplay::restart_game(){
    hide();
    QString player_1 = ui->playertag1->text();
    QString player_2 = ui->playertag2->text();
    newgame = new GameDisplay;
    newgame->readtext(player_1,player_2);
    newgame->show();
}

/////////////////////////////////////////////////////////////////////////////////////////
