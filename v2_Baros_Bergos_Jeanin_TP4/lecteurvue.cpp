#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QDebug>

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
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

lecteurVue::~lecteurVue()
{
    delete ui;
}

// Implémentation des différents slots

void lecteurVue::demanderPrecedent()
{
    qDebug() << "Je passe à l'image précédente !";
}

void lecteurVue::demanderPause()
{
    qDebug() << "Je mets la lecture en pause !";
}

void lecteurVue::demanderSuivant()
{
    qDebug() << "Je passe à l'image suivante !";
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
}

void lecteurVue::demanderQuitter()
{
    qDebug() << "Je quitte l'application !";
}

void lecteurVue::demanderAProposDe()
{
    qDebug() << "J'affiche la page 'à propos de' !";
}

void lecteurVue::demanderChangerModeDefilement()
{
    qDebug() <<  "Je change le mode de défilement des images !";
}
