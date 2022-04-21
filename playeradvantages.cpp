#include "playeradvantages.h"

playerAdvantages::playerAdvantages(QWidget *parent)
    : QMainWindow{parent}
{

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA LA VENTAJA DE RANDOMIZE//

void GameDisplay::randomize_images(){
    ui->ven_tag->setText(QString("RANDOMIZE!"));
    ui->frame->setEnabled(false);
    random_image(targets, repart, images);
    random_target(targets);
    ui->frame->setEnabled(true);
    ui->ven_random->setEnabled(false);
    ui->ven_random->hide();

}

//METODO PARA LA VENTAJA RANDOMIZE//

void GameDisplay::randomize_images2(){
    ui->ven_tag->setText(QString("RANDOMIZE!"));
    ui->frame->setEnabled(false);
    random_image(targets, repart, images);
    random_target(targets);
    ui->frame->setEnabled(true);
    ui->ven_random2->setEnabled(false);
    ui->ven_random2->hide();

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODOS PARA LA VENTAJA DEL TIMER PLAYER 1//

void GameDisplay::up_timer(){
    time= time.addSecs(15);
    ui->ven_tag->setText(QString("INCREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer1->setEnabled(false);
    ui->ven_timer1->hide();
    ui->ven_timer2->setEnabled(false);
    ui->ven_timer2->hide();

}

void GameDisplay::down_timer(){
    time= time.addSecs(-15);
    ui->ven_tag->setText(QString("DECREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer1->setEnabled(false);
    ui->ven_timer1->hide();
    ui->ven_timer2->setEnabled(false);
    ui->ven_timer2->hide();
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA LA VENTAJA DEL TIMER PLAYER 2//

void GameDisplay::up_timer2(){
    time= time.addSecs(15);
    ui->ven_tag->setText(QString("INCREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer01->setEnabled(false);
    ui->ven_timer01->hide();
    ui->ven_timer02->setEnabled(false);
    ui->ven_timer02->hide();

}
void GameDisplay::down_timer2(){
    time= time.addSecs(-15);
    ui->ven_tag->setText(QString("DECREASED TIME!"));
    ui->timer_game->setText(time.toString("m:ss"));
    ui->ven_timer01->setEnabled(false);
    ui->ven_timer01->hide();
    ui->ven_timer02->setEnabled(false);
    ui->ven_timer02->hide();
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO PARA LA VENTAJA DOUBLE PLAYER 1//
void GameDisplay::double_points(){
    hit = true;
    ui->ven_double->setEnabled(false);
    ui->ven_double->hide();

}

//METODO PARA LA VENTAJA DOUBLE PLAYER 2//
void GameDisplay::double_points2(){
    hit2 = true;
    ui->ven_double2->setEnabled(false);
    ui->ven_double2->hide();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
