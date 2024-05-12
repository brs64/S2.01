#include "modele.h"

Modele::Modele(QObject *parent)
    : QObject{parent}
{}

Diaporama* Modele::getDiaporama()
{
    return (*this).diaporama;
}

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
