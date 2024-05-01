#include "image.h"
#include <iostream>
using namespace std;

Image::Image(string pTitre, string pCategorie, string pChemin):
    titre(pTitre),
    categorie(pCategorie),
    chemin(pChemin){}

Image::Image(const Image& pImage):
    titre(pImage.getTitre()),
    categorie(pImage.getCategorie()),
    chemin(pImage.getChemin()){}

Image::~Image() {}

string Image::getTitre() const
{
    return (*this).titre;
}

string Image::getCategorie() const
{
    return (*this).categorie;
}

string Image::getChemin() const
{
    return (*this).chemin;
}


void Image::setTitre(string pTitre)
{
    (*this).titre = pTitre;
}

void Image::setCategorie(string pCategorie)
{
    (*this).categorie = pCategorie;
}

void Image::setChemin(string pChemin)
{
    (*this).chemin = pChemin;
}

void Image::afficher() const
{
    cout << "image(titre:" << (*this).getTitre() << ", categorie:"
         << (*this).getCategorie() << ", chemin:"<< (*this).getChemin() << ")" << endl;
}
