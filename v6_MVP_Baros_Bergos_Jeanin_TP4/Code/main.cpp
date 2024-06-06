#include "presentation.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //créer le lecteur
    Lecteur* l = new Lecteur();

    // créer le modèle
    Modele *m = new Modele();

    // créer la présentation
    Presentation *p = new Presentation();

    // créer la vue
    lecteurVue w;

    // faire pointer la présentation vers la vue et le modèle
    p->setVue(&w);
    p->setModel(m);

    // faire pointer la vue vers la présentation
    w.setPresentation(p);

    // charger le Diaporama
    l->changerDiaporama(1);

    // faire pointer le modèle vers le lecteur
    m->setLecteur(l);
    // afficher la vue et démarrer la boucle d'attente des messages

    w.show();
    return a.exec();
}
