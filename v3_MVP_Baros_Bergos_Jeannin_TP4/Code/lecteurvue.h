#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "modele.h"

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE
class Presentation ;

class LecteurVue : public QMainWindow
{
    Q_OBJECT
    private:
        Ui::lecteurVue *ui; // Interface utilisateur
        Presentation* _laPresentation; // pointeur pour transmettre les instructions à la présentation


    public:
        explicit LecteurVue(QWidget *parent = nullptr); // Constructeur par défaut
        ~LecteurVue(); // Destructeur


        // Setter et getter
        Presentation* getPresentation();
        void setPresentation(Presentation*);


    public slots : // Déclaration des différents slots
        void demanderFiltres();
        void demanderVitesseDefilement();
        void demanderChargerDiaporama();
        void demanderQuitter();
        void demanderAProposDe();
        void demanderPrecedent();
        void demanderSuivant();
        void demanderPause();
        void demanderChangerModeDefilement();
};

#endif // LECTEURVUE_H
