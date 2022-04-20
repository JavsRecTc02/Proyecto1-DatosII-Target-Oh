#ifndef RESTARTGAME_H
#define RESTARTGAME_H

#include <QMainWindow>
#include <QObject>
#include "ui_gamedisplay.h"
#include "gamedisplay.h"

class Restartgame : public QMainWindow
{
    Q_OBJECT
public:
    explicit Restartgame(QWidget *parent = nullptr);

    void restart_game();

private:

    Ui::GameDisplay *ui;
    GameDisplay *gameDisplay;

};

#endif // RESTARTGAME_H
