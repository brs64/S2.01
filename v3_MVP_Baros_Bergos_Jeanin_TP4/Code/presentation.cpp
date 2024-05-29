#include "presentation.h"

Presentation::Presentation()
{
}

Modele *Presentation::getModele()
{
    return _leModele;
}

lecteurVue *Presentation::getVue()
{
    return _laVue;
}

void Presentation::setModel(Modele *m)
{
    _leModele = m;
}

void Presentation::setVue(lecteurVue *v)
{
    _laVue = v;
}

ImageDansDiaporama* Presentation::getImageActuelle()
{
    return _leModele->getDiaporama()->getImageCourante();
}

Diaporama *Presentation::getDiapoActuel()
{
    return getModele()->getDiaporama();
}


void Presentation::demanderAvancer() {
    if (!_leModele) {
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }

    _leModele->avancer();

    Diaporama *diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }
    ImageDansDiaporama* image = _leModele->getLecteur()->getImageCourante();
    _laVue->majPresentation(
        QString::fromStdString(diapo->getTitre()),
        QString::fromStdString(image->getTitre()),
        QString::fromStdString(image->getCategorie()),
        QString::number(image->getRangDansDiaporama()),
        QString::fromStdString(image->getChemin())
        );
    qDebug() << "L'image avance";
}

void Presentation::demanderReculer() {
    if (!_leModele) {
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }

    _leModele->reculer();

    Diaporama *diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }

    ImageDansDiaporama* image = _leModele->getLecteur()->getImageCourante();
    _laVue->majPresentation(
        QString::fromStdString(diapo->getTitre()),
        QString::fromStdString(image->getTitre()),
        QString::fromStdString(image->getCategorie()),
        QString::number(image->getRangDansDiaporama()),
        QString::fromStdString(image->getChemin())
        );
    qDebug() << "L'image recule";
}

void Presentation::demanderPause()
{
    qDebug() << "la lecture est en pause !";
}
void Presentation::demanderDepartArretAuto()
{
    _leModele->departArretAuto();
    qDebug() << "Le défilement d'image se met en pause / avance en mode auto";
}

void Presentation::demanderChangerVitesse()
{

    _leModele->changerVitesse();
    qDebug() << "La fenêtre pour changer la vitesse apparait";
}

void Presentation::demanderChangerMode()
{
    qDebug() << "Le mode change";
}


void Presentation::demanderChargerDiapo()
{
    _leModele->chargerDiapo();
    qDebug() << "On charges une nouvelle diapo";
}

void Presentation::demanderFiltre()
{
    qDebug() << "Affichage des filtres possibles";
}
