#include "diaporama.h"
#include <iostream>
using namespace std;


Diaporama::Diaporama(const ImagesDansDiaporama& pImagesDansDiaporama, string pTitre, unsigned int pVitesseDefilement, unsigned int pPosImageCourante):
    titre(pTitre),
    vitesseDefilement(pVitesseDefilement),
    localisationImages(pImagesDansDiaporama),
    posImageCourante(pPosImageCourante){}

Diaporama::Diaporama(const Diaporama& pDiaporama):
    titre(pDiaporama.getTitre()),
    vitesseDefilement(pDiaporama.getVitesseDefilement()),
    localisationImages(pDiaporama.getLocalisationImages()),
    posImageCourante(pDiaporama.getPosImageCourante()){}

Diaporama::~Diaporama() {}

string Diaporama::getTitre() const
{
    return (*this).titre;
}

unsigned int Diaporama::getVitesseDefilement() const
{
    return (*this).vitesseDefilement;
}

unsigned int Diaporama::getPosImageCourante() const
{
    return (*this).posImageCourante;
}

ImagesDansDiaporama Diaporama::getLocalisationImages() const
{
    return (*this).localisationImages;
}

void Diaporama::setTitre(string pTitre)
{
    (*this).titre = pTitre;
}

void Diaporama::setVitesseDefilement(unsigned int pVitesseDefilement)
{
    (*this).vitesseDefilement = pVitesseDefilement;
}

void Diaporama::setPosImageCourante(unsigned int pPosImageCourante)
{
    (*this).posImageCourante = pPosImageCourante;
}

void Diaporama::setLocalisationImages(ImagesDansDiaporama& pLocalisationImages)
{
    (*this).localisationImages = pLocalisationImages;
}

ImageDansDiaporama Diaporama::getImageCourante() const
{
    return (*this).getLocalisationImages()[posImageCourante];
}

void Diaporama::avancer() //envoie à l'image suivante
{
    if((*this).getPosImageCourante() == (*this).nbImages() - 1)
    {
        (*this).setPosImageCourante(0);
    }
    else
    {
        (*this).setPosImageCourante((*this).posImageCourante + 1);
    }
}

void Diaporama::reculer() //renvoie à l'image précédente
{
    if((*this).getPosImageCourante() == 0)
    {
        (*this).setPosImageCourante((*this).nbImages() - 1);
    }
    else
    {
        (*this).setPosImageCourante((*this).posImageCourante - 1);
    }
}


unsigned int Diaporama::nbImages() const
{
    return (*this).getLocalisationImages().size();
}


void Diaporama::triCroissantRang()
{   //tri par ordre croissant les images du diaporama par la méthode du triBulle
    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = (*this).nbImages()-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if ((*this).getLocalisationImages()[i].getRang() > (*this).getLocalisationImages()[i+1].getRang())
            {
                // echanger les 2 éléments
                imageDansDiapo = (*this).getLocalisationImages()[i];
                (*this).getLocalisationImages()[i] = (*this).getLocalisationImages()[i+1];
                (*this).getLocalisationImages()[i+1] = imageDansDiapo;
            }
        }
    }
}

void Diaporama::pushBackImage(const ImageDansDiaporama& pImageDansDiaporama)
{
    (*this).localisationImages.push_back(pImageDansDiaporama);
}

void Diaporama::clear()
{
    (*this).localisationImages.clear();
}
