#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include "classes_modele.h"
#include <QMainWindow>
#include "classes_presentation.h"


QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class ImgPres;
class ImgDsDiapoPres;
class DiapoPres;
class LecteurPres;

class lecteurVue : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::lecteurVue *ui; // Interface utilisateur
        ImgPres *_imgCourante; //pointeur vers la classe Img de la partie Présentaton
        ImgDsDiapoPres *_imgDsDiapoCourante; //pointeur vers la classe ImgDsDiapo (image dans un diaporama) de la partie Présentaton
        DiapoPres *_DiapoCourant; //pointeur vers la classe Diapo (diaporama)à de la partie Présentaton
        LecteurPres _lecteurPres; //pointeur vers la classe lecteur de la partie Présentaton

    public:
        explicit lecteurVue(QWidget *parent = nullptr); // Constructeur par défaut
        ~lecteurVue(); // Destructeur

        //setters et getters
        void setUi(Ui::lecteurVue*);
        Ui::lecteurVue* getUi();

        void setImgCourante(ImgPres*);
        ImgPres* getImgCourante();

        void setUi(ImgDsDiapoPres*);
        ImgDsDiapoPres* getImgDsDiapo();

        void setUi(DiapoPres *);
        DiapoPres* getDiapo();

        // mise à jour de la fenêtre
        void majInfosImgDsDiapo();
        void majInfosDiapo();
        void majMode(Mode);



    public slots :
        // Déclaration des différents slots
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
