#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include <iostream>
#include <QLabel>
using namespace std;

// Module de manipulation d'éléments de type Image

class Image {
    public:
        // Attributs
        string titre;              // intitulé de l'image
        string categorie;          // catégorie de l'image (personne, animal, objet)
        string chemin;             // chemin d'accès de l'image


        // Constructeurs et destructeur
        Image(string="Dos", string="Dos", string="/disney/cartesDisney/Disney_0.png"); //constructeur par défaut
        Image(const Image&); //constructeur de copie

        ~Image();


        // Setters et getters
        void setTitre(string);
        void setCategorie(string);
        void setChemin(string);

        string getTitre() const;
        string getCategorie() const;
        string getChemin() const;


        // Autre
        void afficher() const; //affiche les informations relatives à l'image
};

typedef vector<Image> Images;
#endif // IMAGE_H
