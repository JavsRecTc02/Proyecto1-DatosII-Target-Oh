#ifndef GAMEIMAGES_H
#define GAMEIMAGES_H

#include <QMainWindow>
#include <QObject>
#include "ui_gamedisplay.h"
#include "gamedisplay.h"

class gameimages : public QMainWindow
{
    Q_OBJECT
public:
    explicit gameimages(QWidget *parent = nullptr);

    QVector <QString> images;

    int limit_images;
    int images_bytes;
    void bytes_images();

private:

    Ui::GameDisplay *ui;
    GameDisplay *gameDisplay;
};

#endif // GAMEIMAGES_H
