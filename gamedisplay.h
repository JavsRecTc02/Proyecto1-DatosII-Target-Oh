#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QVector>
#include <QHash>
#include <QString>
#include <random>
#include <QPushButton>
#include <iostream>
#include <vector>
#include <QRandomGenerator64>


using namespace std;

class Player;
class gameimages;
class gametargets;
class playerAdvantages;
class gameResults;

namespace Ui {
class GameDisplay;
}

class GameDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameDisplay(QWidget *parent = nullptr);
    ~GameDisplay();
    //QString player_1;
    void readtext(QString T,QString Q);

    QTimer *timer=new QTimer();
    QTime time;
    QMessageBox msgBox;

    void random_player();
    void restart_game();
    void Start_game();
    void bytes_images();
    void show_image();

    QVector<QString> targets;
    QHash<QString, QString> repart;
    QVector <QString> images;    

    int game_points;
    int game_points2;
    int fault_couples;
    int player_2;
    int limit_images;
    int limit_targets;

    bool game_starts;
    bool hit;
    bool hit2;


    QPushButton* target_previous;
    QPushButton* target_current;

    void eliminate_targets();
    void eliminate_images();
    void block_player();


    void parcial_result2();
    void parcial_result();
    void select_parcialresult();
    void finish_result();
    void winner_result();


private slots:

    void random_target(QVector<QString> &targets);
    void random_image(QVector<QString> &targets, QHash<QString, QString> &repart, QVector<QString> images);

    void update_timer();
    void update_estade();
    void restart_targets();
    void target_select();
    void refresh_targets();

    //voids player 1 power ups

    void randomize_images();
    void up_timer();
    void down_timer();
    void double_points();

    //voids player 2 power ups

    void randomize_images2();
    void up_timer2();
    void down_timer2();
    void double_points2();



private:
    Ui::GameDisplay *ui;
    GameDisplay *newgame;
};

#endif // GAMEDISPLAY_H
