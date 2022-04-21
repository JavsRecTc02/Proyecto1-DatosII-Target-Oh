#ifndef GAMERESULTS_H
#define GAMERESULTS_H

#include <QMainWindow>
#include <QObject>
#include "ui_gamedisplay.h"
#include "gamedisplay.h"

class gameResults : public QMainWindow
{
    Q_OBJECT
public:
    explicit gameResults(QWidget *parent = nullptr);

    int game_points;
    int game_points2;
    int fault_couples;

    void finish_result();
    void winner_result();
    void parcial_result();
    void parcial_result2();
    void select_parcialresult();

private:

    Ui::GameDisplay *ui;
    GameDisplay *gameDisplay;

};

#endif // GAMERESULTS_H
