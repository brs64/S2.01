#include "presentation.h"
#include "lecteurvue.h" // pour appeler des méthodes de la vue
#include <QDebug>

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
}

Modele *Presentation::getModele()
{
    return _leModele;
}
LecteurVue *Presentation::getVue()
{
    return _laVue;
}

void Presentation::setModele(Modele *m)
{
    _leModele = m;
}
void Presentation::setVue(LecteurVue *v)
{
    _laVue = v;
}
void Presentation::demandeAvancer() // méthode déclenchée par la vue
{
    (*this).getModele()->avancer();
}
void Presentation::demandeReculer() // méthode déclenchée par la vue
{
    (*this).getModele()->avancer();
}
