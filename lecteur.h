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
    void setPosDiapoCourant(unsigned int);
    unsigned int getPosDiapoCourant() const;
    void setMode(bool);
    bool getMode() const;

    Diaporama getDiapoCourant() const;
    unsigned int nbDiapos() const;
    void afficherImageCouranteDansDiaporamaCourant() const;
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void declencherAction(char);
    void charger (Images&);
    void charger (Diaporamas&);
};

#endif // LECTEUR_H
