#include "modele.h"
#include <QDialog>


Modele::Modele():
    _manuel(true)
{

}

unsigned int Modele::getVitesseDefilement() const
{
    return m_vitesseDefilement;
}

bool Modele::lecteurVide() const
{
    return (getDiaporama() == nullptr);
}

Lecteur* Modele::getLecteur() const
{
    return lecteur;
}

void Modele::setLecteur(Lecteur* newLecteur)
{
    lecteur = newLecteur;
}

unsigned int Modele::getPosImageCourante() const
{
    return m_posImageCourante;
}

unsigned int Modele::nbImages() const
{
    if (lecteurVide())
    {
        throw string ("lecteur vide");
    }
    return m_MonDiapo->nbImages();
}


Diaporama *Modele::getDiaporama() const
{
    return m_MonDiapo;
}


void Modele::setVitesseDefilement(unsigned int vitesse)
{
    m_vitesseDefilement = vitesse;
}

void Modele::setPosImageCourante(unsigned int pPosImageCourante)
{
    m_posImageCourante = pPosImageCourante;
}


void Modele::setDiaporama(Diaporama *diaporama)
{
    m_MonDiapo = diaporama;
}

void Modele::avancer() {
    qDebug() << "Modele::avance";
    lecteur->avancer();
    qDebug() << "le lecteur à avancé";

    if (!lecteur->getDiaporama()) {
        qDebug() << "Diaporama est nul";
        return;
    }

    ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
    if (!imageCourante) {
        qDebug() << "Aucune image courante";
        return;
    }
}




void Modele::reculer()
{
    qDebug() << "Modele::recule";
    lecteur->reculer();
    qDebug() << "le lecteur à reculé";

    if (!lecteur->getDiaporama()) {
        qDebug() << "Diaporama est nul";
        return;
    }

    ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
    if (!imageCourante) {
        qDebug() << "Aucune image courante";
        return;
    }
}


void Modele::triCroissantRang()
{
    ImageDansDiaporama* pteurImage;
    unsigned int taille = nbImages();
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (images[i]->getRangDansDiaporama() > images[i+1]->getRangDansDiaporama())
            {
                // échanger les 2 éléments
                pteurImage = images[i];
                images[i] = images[i+1];
                images[i+1] = pteurImage;
            }
        }
    }
}

bool Modele::getManuel() const {
    return _manuel;
}
void Modele::setManuel(bool etat)
{
    _manuel = etat;
}

void Modele::changerVitesse() {
    // Implémentation du changement de vitesse
}

void Modele::chargerDiapo() {
    // Implémentation du chargement de diaporama
}


