#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QObject>
#include "ui_gamedisplay.h"
#include "gamedisplay.h"

//class GameDisplay;

class Player : public QMainWindow
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);

    int player_2;

    void random_player();
    void block_player();

private:

    Ui::GameDisplay *ui;
    GameDisplay *porfa;

};

#endif // PLAYER_H
