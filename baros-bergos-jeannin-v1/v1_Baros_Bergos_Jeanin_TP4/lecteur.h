#ifndef LECTEUR_H
#define LECTEUR_H
#include "diaporama.h"

class Lecteur
{
private:
    Diaporamas localisationDiaporamas;
    unsigned int posDiapoCourant;
    bool modeAuto;
public:
    Lecteur(const Diaporamas& = Diaporamas(), unsigned int=0, bool=false);
    Lecteur(const Lecteur&);
    ~Lecteur();
    void setDiapos(const Diaporamas&);
    Diaporamas getDiapos() const;
    void setPosDiapoCourant(unsigned int); // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    unsigned int getPosDiapoCourant() const;
    void setMode(bool);
    bool getMode() const;

    Diaporama getDiapoCourant() const;
    unsigned int nbDiapos() const;
};

#endif // LECTEUR_H
