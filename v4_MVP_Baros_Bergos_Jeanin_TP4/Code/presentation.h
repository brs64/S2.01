#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include <QTimer>
#include "modele.h"
#include "lecteurvue.h"


class Presentation : public QObject
{
    Q_OBJECT
    private:
        // Attributs
        Modele* _leModele;
        lecteurVue* _laVue;
        QTimer* timer;
        const unsigned int DELAIS = 2000;


    public:
        Presentation(); // Constructeur par défaut

        // Getters
        void setModel(Modele* m);
        Modele *getModele();
        lecteurVue *getVue();
        ImageDansDiaporama* getImageActuelle();
        Diaporama * getDiapoActuel();

        // Setters
        void setVue(lecteurVue* v);

        // Autres
        void demanderAvancer();
        void demanderReculer();
        void demanderDepartArretAuto();
        void demanderChangerVitesse();
        void demanderPause();
        void demanderChangerMode();
        void passerManuel();
        void demanderChargerDiapo();
        void demanderFiltre();
        //void avancerAuto();
};

#endif // PRESENTATION_H
