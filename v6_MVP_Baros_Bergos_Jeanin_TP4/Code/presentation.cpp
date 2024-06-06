#include "presentation.h"
#include "diaporama.h"
Presentation::Presentation()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(demanderAvancer()));
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
    qDebug() << "essaie d'avancer";
    if (!_leModele) {
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }

    _leModele->avancer();
/*
    if(getModele()->getManuel())
    {
        demanderChangerMode();
    }
*/
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

    if(getModele()->getManuel())
    {
        demanderChangerMode();
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
    Diaporama *diapo = _leModele->getLecteur()->getDiaporama();
    unsigned int temps = DELAIS * (diapo->getVitesseDefilement());
    qDebug() << "La vitesse de defilement : " << temps;
    QString modeDef;
    qDebug() << "Le mode change, il était à: " << getModele()->getManuel();
    if (getModele()->getManuel()) {
        getModele() -> setManuel(false);
        qDebug() << "auto";
        modeDef = "Auto";
        timer->start(temps); // * getModele()->getVitesseDefilement()
        qDebug() << "chrono lancé. actuellement à : " << timer;
        qDebug() << "chrono continue. actuellement à : " << timer;
    }
    else {
        getModele() -> setManuel(true);
        modeDef = "Manuel";
        timer->stop();  // Arrêter le timer lorsque le mode est changé en manuel.
        disconnect(timer, SIGNAL(timeout()), this, SLOT(avancer())); //utile ?
        }
    getVue()->afficherMode(modeDef);
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

/*
void Presentation::avancerAuto()
{
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
*/

void Presentation::passerManuel(){
    if (!getModele()->getManuel()){
        demanderChangerMode();
    }
}

