#include "gameimages.h"
#include "gamedisplay.h"

gameimages::gameimages(QWidget *parent)
    : QMainWindow{parent}
{

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE MUESTRA LA IMAGEN ASIGNADA A CADA TARJETA//
void GameDisplay::show_image(){
    QString target_name= target_current->objectName();//nombre del TARGET
    QString img = repart[target_name];//nombre de la IMAGEN
    target_current->setStyleSheet("#"+target_name+"{ background-image:url(://"+img+")}");

}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE SELECCIONA UNA IMAGEN EN EL ARRAY PARA DOS TARJETAS//
void GameDisplay::random_image(QVector<QString> &targets, QHash<QString, QString> &repart, QVector<QString> images){
    auto iterator = targets.begin();
    //int limit = (images.size());
    for (int i = 0; i <= limit_images; i++){
        QString file_name = images[i];
        repart[(*iterator)]=file_name;
        iterator++;
        repart[(*iterator)]=file_name;
        iterator++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

// METODO QUE ELIMINA LAS IMAGENES REPETIDAS//
void GameDisplay::eliminate_images(){
    //int limit1 = (images.size());
    QString namecurr = target_current->objectName();
    QString nameimgs = repart[namecurr];

    for (int i=0; i <= limit_images; i++){
        if (nameimgs == images[i]){
            images.erase(images.begin()+i);
            //erase(images, images[i]);

            break;
        }
    }
    limit_images--;
    bytes_images();
}

/////////////////////////////////////////////////////////////////////////////////////////

//METODO QUE OBTENGA LA CANTIDAD DE BYTES EN USO DE VECTOR DE LAS IMAGENES//
void GameDisplay::bytes_images(){
    int bytes=0;
    for (int i=0; i <= limit_images; i++){
        int a = sizeof(images[i]);
        bytes += a;
    }
    ui->numbytes->setText(QString::number(bytes));
}
