#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include <vector>
#include "diaporama.h"
#include "lecteur.h"

class ImageDansDiaporama;
typedef std::vector<ImageDansDiaporama*> ImagesDiaporama;
class Modele : public QObject
{
    Q_OBJECT

    private:

        // Attributs
        string m_titre;
        float m_vitesseDefilement;
        bool _manuel;
        unsigned int m_posImageCourante;
        vector <ImageDansDiaporama> m_localisationImages;
        Diaporama* m_MonDiapo;
        ImagesDiaporama images;
        Lecteur * lecteur;

        bool lecteurVide() const;
        void triCroissantRang();

    public:
        Modele(); // Constructeur par défaut

        // Getters
        unsigned int getVitesseDefilement() const;
        Diaporama* getDiaporama() const;
        unsigned int getPosImageCourante() const;
        bool getManuel() const;
        Lecteur *  getLecteur() const;

        unsigned int nbImages() const;


        // Setters
        void setVitesseDefilement(unsigned int);
        void setDiaporama(Diaporama *);
        void setPosImageCourante(unsigned int pPosImageCourante);
        void setManuel(bool);
        void setLecteur(Lecteur * newLecteur);

        // Autres
        void avancer();
        void reculer();
        void departArretAuto();
        void changerVitesse();
        void chargerDiapo();

    signals:
        void imageChange(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin);

};

#endif // MODELE_H
