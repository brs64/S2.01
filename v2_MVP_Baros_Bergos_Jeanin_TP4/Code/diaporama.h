#ifndef DIAPORAMA_H
#define DIAPORAMA_H
#include "ImageDansDiaporama.h"
#include <vector>

class Diaporama {
public:
    string titre; // titre du diaporama
    unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
    ImagesDansDiaporama localisationImages; // images du diaporama
    unsigned int posImageCourante;

    Diaporama(const ImagesDansDiaporama& = ImagesDansDiaporama(), string="Diaporama par defaut",unsigned int=2, unsigned int=0);
    Diaporama(const Diaporama&);
    ~Diaporama();
    string getTitre() const;
    void setTitre(string);
    unsigned int getVitesseDefilement() const;
    void setVitesseDefilement(unsigned int);
    unsigned int getPosImageCourante() const;
    void setPosImageCourante(unsigned int);
    ImagesDansDiaporama getLocalisationImages() const;
    void setLocalisationImages(ImagesDansDiaporama&);

    ImageDansDiaporama getImageCourante() const;
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
