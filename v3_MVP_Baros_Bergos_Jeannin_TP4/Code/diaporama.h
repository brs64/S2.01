#ifndef DIAPORAMA_H
#define DIAPORAMA_H
#include "ImageDansDiaporama.h"
#include <vector>

class Diaporama {
    public:
        // Attributs
        string titre; // titre du diaporama
        unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
        ImagesDansDiaporama localisationImages; // images du diaporama
        unsigned int posImageCourante;


        // Constructeurs et destructeur
        Diaporama(const ImagesDansDiaporama& = ImagesDansDiaporama(), string="Diaporama par defaut",unsigned int=2, unsigned int=0); //constructeur par défaut
        Diaporama(const Diaporama&); //constructeur de copie

        ~Diaporama();


        // Setters et getters
        void setTitre(string);
        void setVitesseDefilement(unsigned int);
        void setPosImageCourante(unsigned int);
        void setLocalisationImages(ImagesDansDiaporama&);

        string getTitre() const;
        unsigned int getVitesseDefilement() const;
        unsigned int getPosImageCourante() const;
        ImagesDansDiaporama getLocalisationImages() const;

        ImageDansDiaporama getImageCourante() const;


        // Autres
        void avancer(); // incrémente pPosImageCourante, modulo nbImages(pDiaporama)
        void reculer(); // décrémente pPosImageCourante, modulo nbImages(pDiaporama)

        unsigned int nbImages() const; // affiche la taille du diaporama pDiaporama

        void triCroissantRang ();
        /* Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
       A garder aussi lors de l'implémentation de la BD */

        void pushBackImage(const ImageDansDiaporama&);

        void clear();
};

typedef vector<Diaporama> Diaporamas;
#endif // DIAPORAMA_H
