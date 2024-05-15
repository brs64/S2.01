#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H
#include <iostream>
using namespace std;
#include "image.h"

class ImageDansDiaporama : public Image {
    public:
        // Attributs
        unsigned int pos;  // rang de l'image dans le tableau d'images (vector<Images>)
            // = ordre de chargement initial des images dans la table des images
        unsigned int rang;  // rang de l'image dans le diaporama
            // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama


        // Constructeurs et destructeur
        ImageDansDiaporama(const Image& = Image(), unsigned int=0,unsigned int=0); //constructeur par défaut
        ImageDansDiaporama(const ImageDansDiaporama&); //constructeur de copie

        ~ImageDansDiaporama();


        // Setters et getters
        void setPos(unsigned int);
        void setRang(unsigned int);

        unsigned int getPos() const;
        unsigned int getRang() const;
};

typedef vector<ImageDansDiaporama> ImagesDansDiaporama;
#endif // TYPE_DIAPORAMA_H
