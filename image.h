#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include <iostream>
using namespace std;

// Module de manipulation d'éléments de type Image

class Image {
private:
    string titre;              // intitulé de l'image
    string categorie;          // catégorie de l'image (personne, animal, objet)
    string chemin;
public:
    Image(string="", string="", string="");
    Image(const Image&);
    ~Image();
    string getTitre() const;
    void setTitre(string);
    string getCategorie() const;
    void setCategorie(string);
    string getChemin() const;
    void setChemin(string);

    void afficher() const;
};

typedef vector<Image> Images;
#endif // IMAGE_H
