#include "lecteurvue.h"
#include "presentation.h"
#include "modele.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // créer le modèle
    Modele *m = new Modele();
    // créer la présentation
    Presentation *p = new Presentation();
    // créer la vue
    LecteurVue w;
    // faire pointer la présentation vers la vue et le modèle
    p->setVue(&w);
    p->setModele(m);
    // faire pointer la vue vers la présentation
    w.setPresentation(p);



    // afficher la vue et démarrer la boucle d'attente des messages
    w.show();
    return a.exec();
}
