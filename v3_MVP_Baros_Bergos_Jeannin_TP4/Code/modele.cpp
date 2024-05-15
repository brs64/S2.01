#include "modele.h"

Modele::Modele(QObject *parent) //constructeur (par défaut)
    : QObject{parent}
{}



// Setter et getter
void Modele::setDiaporama(Diaporama* d){
    (*this).diaporama = d;
}

Diaporama* Modele::getDiaporama()
{
    return (*this).diaporama;
}



// Autres
void Modele::avancer(){
    if((*this).getDiaporama()->getPosImageCourante() == (*this).getDiaporama()->nbImages() - 1)
    {
        (*this).getDiaporama()->setPosImageCourante(0);
    }
    else
    {
        (*this).getDiaporama()->setPosImageCourante((*this).getDiaporama()->posImageCourante + 1);
    }
}

void Modele::reculer(){
    if((*this).getDiaporama()->getPosImageCourante() == 0)
    {
        (*this).getDiaporama()->setPosImageCourante((*this).getDiaporama()->nbImages() - 1);
    }
    else
    {
        (*this).getDiaporama()->setPosImageCourante((*this).getDiaporama()->posImageCourante - 1);
    }
}
