#ifndef GAMETARGETS_H
#define GAMETARGETS_H

#include <QMainWindow>
#include <QObject>
#include "ui_gamedisplay.h"
#include "gamedisplay.h"

class gametargets : public QMainWindow
{
    Q_OBJECT
public:
    explicit gametargets(QWidget *parent = nullptr);

    QVector<QString> targets;
    QHash<QString, QString> repart;
    QPushButton* target_previous;
    QPushButton* target_current;
    int limit_targets;

private:

    Ui::GameDisplay *ui;
    GameDisplay *gameDisplay;

};

#endif // GAMETARGETS_H
