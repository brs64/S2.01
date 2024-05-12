#ifndef PRESENTATION_H
#define PRESENTATION_H
#include "modele.h"
#include "lecteurvue.h"

class Presentation : public QObject
{ Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);
private: // pour gérer les attributs privés
    Modele* getModele();
    LecteurVue* getVue();
public :
    void setModele(Modele *m);
    void setVue(LecteurVue *v);
    void demandeAvancer();
    void demandeReculer();
private:
    Modele *_leModele; // pointeur sur le modèle
    LecteurVue *_laVue; // pointeur sur la vue, dont le nom de
};

#endif // PRESENTATION_H
