#include "ui_lecteurvue.h"
#include "presentation.h"
#include "modele.h"
#include <QDebug>
#include <QMessageBox>
#include <QImage>

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);
    ui->mode->setText("Manuel");

    // Connexions pour les boutons
    QObject::connect(ui->suivant, SIGNAL(clicked()), this, SLOT(demanderAvancer()));
    QObject::connect(ui->precedent, SIGNAL(clicked()), this, SLOT(demanderReculer()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterApplication()));
    QObject::connect(ui->modeDefilement, SIGNAL(clicked()), this, SLOT(demanderChangerMode()));

    // Connexions pour les actions du menu
    QObject::connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(demanderChargerDiapo()));
    QObject::connect(ui->actionFiltre, SIGNAL(triggered()), this, SLOT(demanderFiltre()));
    QObject::connect(ui->actionVitesse, SIGNAL(triggered()), this, SLOT(demanderChangerVitesse()));
    QObject::connect(ui->actionAProposDe, SIGNAL(triggered()), this, SLOT(demanderAProposDe()));

    // navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->precedent, ui->modeDefilement);
    QWidget::setTabOrder(ui->modeDefilement, ui->suivant);
}
lecteurVue::~lecteurVue()
{
    delete ui;
}

Presentation *lecteurVue::getPresentation() const
{
    return m_MaPresentation;
}



void lecteurVue::majPresentation(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin) {
    qDebug() << "Émission de imageChange avec: " << titreDiapo << titreImage << categorie << rang << chemin;
    ui->titre->setText(titreDiapo);
    qDebug() << "le titre : " << titreDiapo ;
    ui->titreImage->setText(titreImage);
    ui->categorie->setText(categorie);
    ui->rang->setText(rang);
    ui->image->setPixmap(QPixmap(chemin));

    this->update();
}


void lecteurVue::setPresentation(Presentation * p)
{
    m_MaPresentation = p;
}

void lecteurVue::demanderPause()
{
    m_MaPresentation->demanderPause();
}

void lecteurVue::demanderAvancer(){
    qDebug() << "Demande d'avancer";
    m_MaPresentation->demanderAvancer();
    m_MaPresentation->passerManuel();
}

void lecteurVue::demanderReculer(){
    qDebug() << "Demande à reculer";
    m_MaPresentation->demanderReculer();
    m_MaPresentation->passerManuel();
}

void lecteurVue::demanderChangerVitesse(){
    qDebug() << "Demande à changer la vitesse";
    m_MaPresentation->demanderChangerVitesse();
}

void lecteurVue::demanderChangerMode(){
    qDebug() << "Demande à changer de mode";

    m_MaPresentation->demanderChangerMode();
}

void lecteurVue::demanderChargerDiapo(){
    qDebug() << "Demande à charger un nouveau diaporama";
    m_MaPresentation->demanderChargerDiapo();
}
void lecteurVue::demanderFiltre(){
    qDebug() << "Demande à changer le filtre des images";
    m_MaPresentation->demanderFiltre();
}
void lecteurVue::quitterApplication() {
    QApplication::quit();
}

void lecteurVue::demanderAProposDe()
{
    qDebug() << "J'affiche la page 'à propos de' !";
    QString titre = "A propos";
    QString message = "Version : V6 MVP\n\n"
                      "Date de création : 06/05/2024\n\n"
                      "Auteurs : BAROS Arthur, BERGOS Ugo, JEANNIN Guillem";

    QMessageBox::information(nullptr, titre, message);
}

void lecteurVue::afficherMode(QString pMode){
    ui->mode->setText(pMode);
}
