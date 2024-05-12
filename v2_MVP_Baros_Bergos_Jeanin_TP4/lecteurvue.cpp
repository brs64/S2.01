#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QDebug>
#include "classes_presentation.h"



lecteurVue::lecteurVue(QWidget *parent) : QMainWindow(parent), ui(new Ui::lecteurVue) //constructeur par défaut
{
    ui->setupUi(this);

    // Connexion des signaux des widgets aux slots correspondants
    QObject::connect(ui->precedent, SIGNAL(clicked()), this, SLOT(demanderPrecedent()));
    QObject::connect(ui->pause, SIGNAL(clicked()), this, SLOT(demanderPause()));
    QObject::connect(ui->suivant, SIGNAL(clicked()), this, SLOT(demanderSuivant()));
    QObject::connect(ui->actionVitesse, SIGNAL(triggered()), this, SLOT(demanderVitesseDefilement()));
    QObject::connect(ui->actionFiltre, SIGNAL(triggered()), this, SLOT(demanderFiltres()));
    QObject::connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(demanderChargerDiaporama()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demanderQuitter()));
    QObject::connect(ui->actionAProposDe, SIGNAL(triggered()), this, SLOT(demanderAProposDe()));
    QObject::connect(ui->modeDefilement, SIGNAL(clicked()), this, SLOT(demanderChangerModeDefilement()));
}

lecteurVue::~lecteurVue() //destructeur
{
    delete ui;
}



// Implémentation des différents slots

void lecteurVue::demanderPrecedent()
{
    qDebug() << "Je passe à l'image précédente !";
    _imgDsDiapoCourante->demanderChargerImg();
    if (_lecteurPres.verifAuto()){
        _lecteurPres.changerMode();
    }
}

void lecteurVue::demanderPause()
{
    qDebug() << "Je mets la lecture en pause !";
    if (_lecteurPres.verifAuto()){
        _lecteurPres.changerMode();
    }
}

void lecteurVue::demanderSuivant()
{
    qDebug() << "Je passe à l'image suivante !";
    _imgDsDiapoCourante->demanderChargerImg();
    if (_lecteurPres.verifAuto()){
        _lecteurPres.changerMode();
    }
}

void lecteurVue::demanderVitesseDefilement()
{
    qDebug() << "Je change la vitesse de défilement !";
}

void lecteurVue::demanderFiltres()
{
    qDebug() << "Je change le filtre !";
}

void lecteurVue::demanderChargerDiaporama()
{
    qDebug() << "Je charge un diaporama !";
    _DiapoCourant->demanderChargerDiapo();
}

void lecteurVue::demanderQuitter() //fonctionne
{
    (*this).close();
}

void lecteurVue::demanderAProposDe()
{
    qDebug() << "J'affiche la page 'à propos de' !";
}

void lecteurVue::demanderChangerModeDefilement()
{
    qDebug() <<  "Je change le mode de défilement des images !";
    _lecteurPres.changerMode();

}



// mise à jour de la fenêtre

void lecteurVue::majInfosDiapo() {
    qDebug() << "J'essaie de changer le titre affiché";
    ui->titre->setText("nv titre");
}

void lecteurVue::majInfosImgDsDiapo(){
    qDebug() << "J'essaie de changer le titre affiché";
    ui->titreImage->setText(QString::fromStdString("nv titreImg")); //_DiapoCourant->_modele->getTitre()
    qDebug() << "J'essaie de changer la catégorie affichée";
    ui->categorie->setText(QString::fromStdString("nv catégorie")); //_DiapoCourant->_modele->getcategorie()
    qDebug() << "J'essaie de changer le rang affiché";
    ui->rang->setText(QString::fromStdString("nv rang"));           //_DiapoCourant->_modele->getRang()
    qDebug() << "J'ai tout changé";
}

void lecteurVue::majMode(Mode d){
    if (d == Manuel){
        string d = "Manuel";
        //qDebug() << "J'essaie de changer le mode affiché";
        ui->mode->setText(QString::fromStdString(d));
    }
    else{
        string a = "Auto";
        //qDebug() << "J'essaie de changer le mode affiché";
        ui->mode->setText(QString::fromStdString(a));
    }
}

