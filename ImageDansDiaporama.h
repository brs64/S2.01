#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H
#include <iostream>
using namespace std;
#include "image.h"

class ImageDansDiaporama : public Image {
private :
    unsigned int pos;  // rang de l'image dans le tableau d'images (vector<Images>)
        // = ordre de chargement initial des images dans la table des images
    unsigned int rang;  // rang de l'image dans le diaporama
        // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama
public:
    ImageDansDiaporama(const Image& = Image(), unsigned int=0,unsigned int=0);
    ImageDansDiaporama(const ImageDansDiaporama&);
    ~ImageDansDiaporama();
    unsigned int getPos() const;
    void setPos(unsigned int);
    unsigned int getRang() const;
    void setRang(unsigned int);
};

typedef vector<ImageDansDiaporama> ImagesDansDiaporama;
#endif // TYPE_DIAPORAMA_H
