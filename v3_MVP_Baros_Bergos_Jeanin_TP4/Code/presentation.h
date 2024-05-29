#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "lecteurvue.h"


class Presentation : public QObject
{
    Q_OBJECT
private:
    Modele* _leModele;
    lecteurVue* _laVue;

public:
    Presentation();

    void setModel(Modele* m);
    void setVue(lecteurVue* v);
    Modele *getModele();
    lecteurVue *getVue();

    ImageDansDiaporama* getImageActuelle();
    Diaporama * getDiapoActuel();

    void demanderAvancer();
    void demanderReculer();
    void demanderDepartArretAuto();
    void demanderChangerVitesse();
    void demanderPause();
    void demanderChangerMode();
    void demanderChargerDiapo();
    void demanderFiltre();
};

#endif // PRESENTATION_H
