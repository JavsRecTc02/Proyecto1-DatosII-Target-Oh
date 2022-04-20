#ifndef PLAYERADVANTAGES_H
#define PLAYERADVANTAGES_H

#include <QMainWindow>
#include <QObject>
#include "ui_gamedisplay.h"
#include "gamedisplay.h"

class playerAdvantages : public QMainWindow
{
    Q_OBJECT
public:
    explicit playerAdvantages(QWidget *parent = nullptr);

    bool hit;
    bool hit2;

    //voids player 1
    void randomize_images();
    void up_timer();
    void down_timer();
    void double_points();

    //voids player 2
    void randomize_images2();
    void up_timer2();
    void down_timer2();
    void double_points2();


private:

    Ui::GameDisplay *ui;
    GameDisplay *gameDisplay;

};

#endif // PLAYERADVANTAGES_H
