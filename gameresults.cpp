#include "gameresults.h"

gameResults::gameResults(QWidget *parent)
    : QMainWindow{parent}
{

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE DEFINE LAS CONDICIONES PARA GANAR O PERDER EL JUEGO//
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
/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA VERIFICAR SI EL JUGADOR 1 ACERTO LA PAREJA//
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


//METODO PARA VERIFICAR SI EL JUGADOR 2 ACERTO LA PAREJA//
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

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE SELECCIONE EL RESULTADO PARCIAL DEL JUGADOR ACTUAL//

void GameDisplay::select_parcialresult(){
    if (player_2==1){
        parcial_result2();
    }else{
        parcial_result();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE DEFINE EL GANADOR DEL JUEGO//
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

/////////////////////////////////////////////////////////////////////////////////////////
