#include "gametargets.h"

gametargets::gametargets(QWidget *parent)
    : QMainWindow{parent}
{

}

/////METODO PARA QUE LAS TARJETAS SEAN RANDOM////
void GameDisplay::random_target(QVector<QString> &targets){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(targets.begin(), targets.end(), std::default_random_engine(seed));
}


/////METODO QUE REINICIA LAS TARJETAS CON SU FONDO ORIGINAL////
void GameDisplay::restart_targets(){
    target_current->setStyleSheet("#"+target_current->objectName()+"{}");
    target_previous->setStyleSheet("#"+target_previous->objectName()+"{}");
    target_current->setEnabled(true);
    target_previous->setEnabled(true);
    ui->frame->setEnabled(true);
}


/////METODO PARA ACTUALIZAR LAS TARJETAS E IMAGENES UTILIZADAS////
void GameDisplay::refresh_targets(){
    eliminate_images();
    eliminate_targets();
    random_image(targets, repart, images);
    random_target(targets);
    ui->frame->setEnabled(true);
}



/////METODO ELIMINAR TARJETAS CON EL MISMO NOMBRE////
void GameDisplay::eliminate_targets(){
    //int limit = (targets.size());
    QString namecurr = target_current->objectName();
    QString nameprev = target_previous->objectName();
    for (int i = 0; i <= limit_targets; i++){
        if (namecurr == targets[i]){
            targets.erase(targets.begin()+i);
            //erase(targets, targets[i]);
            limit_targets--;
        }
        else{
            if (nameprev == targets[i]){
                targets.erase(targets.begin()+i);
                limit_targets--;
                //erase(targets, targets[i]);
                //targets.remove(i);

            }
        }
    }
}
