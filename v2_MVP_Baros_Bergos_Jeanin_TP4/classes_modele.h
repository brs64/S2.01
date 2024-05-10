#ifndef CLASSES_MODELE_H
#define CLASSES_MODELE_H
#include <vector>
#include <iostream>
using namespace std;

class ImgMdl {

    private:
        string titre;              // intitulé de l'image
        string categorie;          // catégorie de l'image (personne, animal, objet)
        string chemin;             // chemin d'accès de l'image


    public:
        ImgMdl(string="", string="", string=""); //constructeur par défaut
        ImgMdl(const ImgMdl&); //constructeur de copie
        ~ImgMdl(); //destructeur


        //setters et getters
        string getTitre() const;
        void setTitre(string);

        string getCategorie() const;
        void setCategorie(string);

        string getChemin() const;
        void setChemin(string);


        //autre
        void afficher() const; //affiche les informations de l'image (dans le terminal)
};

typedef vector<ImgMdl> Images;


class ImgDsDiapoMdl : public ImgMdl {

    private:
        unsigned int pos;  // rang de l'image dans le tableau d'images (vector<Images>)
                           // = ordre de chargement initial des images dans la table des images
        unsigned int rang;  // rang de l'image dans le diaporama
                            // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama


    public:
        ImgDsDiapoMdl(const ImgMdl& = ImgMdl(), unsigned int=0,unsigned int=0); //constructeur par défaut
        ImgDsDiapoMdl(const ImgDsDiapoMdl&); //constructeur de copie
        ~ImgDsDiapoMdl(); //destructeur


        //setters et getters
        unsigned int getPos() const;
        void setPos(unsigned int);

        unsigned int getRang() const;
        void setRang(unsigned int);


        //autre
        void chargerImgDsDiapo(); //charge l'image dans un diaporama
};

typedef vector<ImgDsDiapoMdl> ImagesDansDiaporama;


class DiapoMdl {

    private:
        string titre; // titre du diaporama
        unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
        ImagesDansDiaporama localisationImages; // images du diaporama
        unsigned int posImageCourante;


    public:
        DiapoMdl(const ImagesDansDiaporama& = ImagesDansDiaporama(), string="Diaporama par defaut",unsigned int=2, unsigned int=0); //constructeur par défaut
        DiapoMdl(const DiapoMdl&);// constructeur de copie
        ~DiapoMdl(); //destructeur

        //setters et getters
        string getTitre() const;
        void setTitre(string);

        unsigned int getVitesseDefilement() const;
        void setVitesseDefilement(unsigned int);

        ImagesDansDiaporama getLocalisationImages() const;
        void setLocalisationImages(ImagesDansDiaporama&);

        unsigned int getPosImageCourante() const;
        void setPosImageCourante(unsigned int);

        ImgDsDiapoMdl getImageCourante() const;


        //autres
        void changerTitre(string);

        void chargerDiapo();

        void avancer(); // incrémente pPosImageCourante, modulo nbImages(pDiaporama)
        void reculer(); // décrémente pPosImageCourante, modulo nbImages(pDiaporama)

        unsigned int nbImages() const; // affiche la taille du diaporama pDiaporama

        void triCroissantRang ();
        /* Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
       A garder aussi lors de l'implémentation de la BD */

        void pushBackImage(const ImgDsDiapoMdl&); //retire une image du diaporama
        void clear(); //vide le diaporama
};

typedef vector<DiapoMdl> Diaporamas;


enum Mode {Manuel, Auto};

class LecteurMdl {

    private:
        Mode m_mode;

    public:
        LecteurMdl(); //constructeur par défaut
        ~LecteurMdl(); //destructeur

        //setter et getter
        void setMode(Mode);
        Mode getMode() const;

        //autre
        void changerMode(); //change le mode de défilement du lecteur
};













































#endif // CLASSES_MODELE_H
