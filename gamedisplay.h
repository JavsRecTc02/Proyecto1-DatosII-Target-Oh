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

    void restart_game();
    void Start_game();

    QVector<QString> targets;
    QHash<QString, QString> repart;

    int game_points;
    int game_points2;
    int player_2;
    int limit_images;
    int limit_targets;
    int images_bytes;
    bool game_starts;
    bool hit;
    bool hit2;
    int fault_couples;

    QVector <QString> images;

    QPushButton* target_previous;
    QPushButton* target_current;


private slots:
    void random_player();

    void update_estade();
    void update_timer();
    void finish_result();
    void winner_result();
    void random_target(QVector<QString> &targets);
    void random_image(QVector<QString> &targets, QHash<QString, QString> &repart, QVector<QString> images);   
    void show_image();

    void parcial_result();  
    void select_parcialresult();

    void restart_targets();
    void target_select();
    void refresh_targets();
    void eliminate_targets();
    void eliminate_images();

    void randomize_images();
    void up_timer();
    void down_timer();
    void double_points();

    //voids player 2
    void parcial_result2();
    void randomize_images2();
    void up_timer2();
    void down_timer2();
    void double_points2();
    void block_player();


private:
    Ui::GameDisplay *ui;
    GameDisplay *newgame;
};

#endif // GAMEDISPLAY_H
