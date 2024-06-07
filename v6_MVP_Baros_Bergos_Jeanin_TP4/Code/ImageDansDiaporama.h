#ifndef IMAGE_DANS_DIAPORAMA_H
#define IMAGE_DANS_DIAPORAMA_H
#include <iostream>
using namespace std;

class ImageDansDiaporama
{

    private:
        // Attributs
        unsigned int rangDansDiaporama;         /* rang de l'image au sein du diaporama auquel l'image est associée */
        string titre;              // intitulé de l'image
        string categorie;          // catégorie de l'image (personne, animal, objet)
        string chemin;             // chemin complet vers le dossier où se trouve l'image

    public:
        ImageDansDiaporama(unsigned int pRangDansDiaporama=0, // Constructeur
                           string pCategorie="defaut", string pTitre="defaut", string pChemin = ":/images/Disney_tapis.gif");
        ~ImageDansDiaporama(); // Destructeur

        // Getters
        unsigned int getRangDansDiaporama() const;
        string getCategorie() const;
        string getTitre() const;
        string getChemin() const;

        // Setters
        void setRangDansDiaporama (unsigned int pRangDansDiaporama);
        void setTitre (string pTitre);
        void setCategorie (string pCategorie);
        void setChemin (string pChemin);

        // Autre.s
        void afficher();    // affiche tous les champs de l'image
};

#endif // IMAGE_DANS_DIAPORAMA_H
