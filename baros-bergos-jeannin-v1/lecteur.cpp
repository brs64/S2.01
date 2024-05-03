#include "lecteur.h"
#include <iostream>
using namespace std;




Lecteur::Lecteur(const Diaporamas& pLocalisationDiaporamas, unsigned int pPosDiapoCourant, bool pMode):
    localisationDiaporamas(pLocalisationDiaporamas),
    posDiapoCourant(pPosDiapoCourant),
    modeAuto(pMode){}

Lecteur::Lecteur(const Lecteur& pLecteur):
    localisationDiaporamas(pLecteur.getDiapos()),
    posDiapoCourant(pLecteur.getPosDiapoCourant()),
    modeAuto(pLecteur.getMode()){}

Lecteur::~Lecteur() {}

Diaporamas Lecteur::getDiapos() const
{
    const Diaporamas a = (*this).localisationDiaporamas;
    return a;
}

unsigned int Lecteur::getPosDiapoCourant() const
{
    return (*this).posDiapoCourant;
}

bool Lecteur::getMode() const
{
    return (*this).modeAuto;
}

void Lecteur::setDiapos(const Diaporamas& pDiapos)
{
    (*this).localisationDiaporamas = pDiapos;
}

void Lecteur::setPosDiapoCourant(unsigned int pPosDiapoCourant)
{
    (*this).posDiapoCourant = pPosDiapoCourant;
}

void Lecteur::setMode(bool pMode)
{
    (*this).modeAuto = pMode;
}

Diaporama Lecteur::getDiapoCourant() const
{
    return (*this).getDiapos()[(*this).getPosDiapoCourant()];
}

unsigned int Lecteur::nbDiapos() const
{
    return (*this).getDiapos().size();
}
