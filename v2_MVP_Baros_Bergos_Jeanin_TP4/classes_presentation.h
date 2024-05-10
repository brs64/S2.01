#ifndef CLASSES_PRESENTATION_H
#define CLASSES_PRESENTATION_H
#include "classes_modele.h"


// sert d'intermédiaire entre vue et présentaiton
//=> gère les mises à jour des infos (présentation)
//=> transmet les infos que la vue doit afficher

class lecteurVue;

class ImgPres {                           // du coup, classe entière inutile ?

    public:
        // void demandeChangerTitre(string);     inutile, non ? On ne peut pas changer le titre d'une image depuis le lecteur
        // void demandeChangerCat(string);       inutile, non ? On ne peut pas changer la catégorie d'une image depuis le lecteur
        // void demandeChangerChemin(string);    inutile, non ? On ne peut pas changer le chemin d'une image depuis le lecteur



    private:
        ImgMdl *_modele; //pointeur de la classe Img (image) de la partie Modèle
        lecteurVue *_lecteur; //pointeur vers la classe lecteur de la partie Vue

    };


class ImgDsDiapoPres {

    private:
        ImgDsDiapoMdl *_modele; //pointeur vers la classe ImgDsDiapo (image dans un diaporama) de la partie Modèle
        lecteurVue *_lecteur; //pointeur vers la classe lecteur de la partie Vue

    public:
        // void demandeChangerPos(string);       inutile, non ? On ne peut pas changer la position d'une image dans diaporama depuis le lecteur
        // void demandeChangerRang(string);      inutile, non ? On ne peut pas changer le rang d'une image dans diaporama depuis le lecteur
        void demanderChargerImg(); //charge l'image dans le lecteur
};


class DiapoPres {

    private:
        DiapoMdl *_modele; //pointeur vers la classe Diapo (diaporama) de la partie Modèle
        lecteurVue *_lecteur; //pointeur vers la classe lecteur de la partie Vue

    public:
        DiapoPres();
        void demanderChargerDiapo();
        void demandeChangerVitesse(unsigned int);
        // void demandeChangerTitre(string);                inutile, non ? On ne peut pas changer le titre d'un diaporama depuis le lecteur
        // void demandeChangerlocImgs(ImagesDansDiaporama); inutile, non ? On ne peut pas changer le chemin du dossier d'images depuis le lecteur
        // void demandeChangerPosImgCourate(unsigned int);  inutile, non ? On ne peut pas changer le chemin de l'image courante depuis le lecteur
    };


class LecteurPres {

    private:
        LecteurMdl *_modele; //pointeur vers la classe lecteur de la partie Modele
        lecteurVue *_lecteur; //pointeur vers la classe lecteur de la partie Vue

    public:
        LecteurPres(); //constructeur par défaut
        bool verifAuto(); // renvoie true si le lecteur est en mode Auto
        void changerMode(); //change le mode de défilement du lecteur
};






    #endif // CLASSES_PRESENTATION_H
