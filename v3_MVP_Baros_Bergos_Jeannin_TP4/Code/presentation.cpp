#include "presentation.h"
#include "lecteurvue.h" // pour appeler des méthodes de la vue
#include <QDebug>

Presentation::Presentation(QObject *parent) //constructeur (par défaut)
    : QObject{parent}
{}



// Getters (privés)
Modele *Presentation::getModele()
{
    return _leModele;
}
LecteurVue *Presentation::getVue()
{
    return _laVue;
}



// Setters
void Presentation::setModele(Modele *m)
{
    _leModele = m;
}

void Presentation::setVue(LecteurVue *v)
{
    _laVue = v;
}



// Autres (déclenchées par la vue)
void Presentation::demandeAvancer()
{
    (*this).getModele()->avancer();
}

void Presentation::demandeReculer()
{
    (*this).getModele()->avancer();
}
