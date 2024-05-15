#ifndef PRESENTATION_H
#define PRESENTATION_H
#include "modele.h"
#include "lecteurvue.h"

class Presentation : public QObject
{
    Q_OBJECT
    private:     // Pour gérer les attributs privés
        // Attributs
        Modele *_leModele; // pointeur pour transmettre les instructions au modèle
        LecteurVue *_laVue; // pointeur pour transmettre les instructions à la vue


        // Getters
        Modele* getModele();
        LecteurVue* getVue();

    public:
        explicit Presentation(QObject *parent = nullptr); //constructeur (par défaut)


        // Setters
        void setModele(Modele *m);
        void setVue(LecteurVue *v);


        //Autres (déclenchées par la vue)
        void demandeAvancer();
        void demandeReculer();
};

#endif // PRESENTATION_H
