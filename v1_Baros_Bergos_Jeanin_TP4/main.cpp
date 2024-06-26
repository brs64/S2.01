#include "diaporama.h"
#include "lecteur.h"
#include "sousProgrammes.h"
#include <iostream>
using namespace std;


int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/
    Images images;          // les images
    Diaporamas diaporamas;  // les diaporamas
    Lecteur lecteur;        // le lecteur principal

    // Chargement des urls des images, chargement des diaporamas
    charger(images);
    charger(diaporamas);

    // Tri des images contenues dans les diaporamas pour les placer dans l'ordre d'apparition (rang) souhaité par l'utilisateur
    for(unsigned short int i = 0; i < lecteur.nbDiapos(); i++)
    {
        for (unsigned int posDiapo = 0; posDiapo < lecteur.getDiapoCourant().nbImages(); posDiapo++)
        {
            diaporamas[posDiapo].triCroissantRang();
        }
    }


    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */

    // Elements autres que les images et diaporamas
    unsigned int diaporamaCourant ; // identifiant du diaporama courant = indice dans le tableau diaporamas
    unsigned int imageCourante ;    // identifiant de l'image courante du diaporama courant
        // = indice de l'image dans le tableau diaporamas[diaporamaCourant].images, trié par ordre croissant de rang

    /* Initialiser le diaporama et l'image courants
     * ---------------
       Les valeurs courantes sont définies par défaut
       --> cela suppose qu'il y a toujours au moins 1 diaporama avec au moins 1 image dedans.
       Autre option (meilleure, à mettre en place dans la version graphique)) :
       - pas de diaporama courant au lancement de l'application
       - le diaporama courant est choisi par l'utilisateur parmi une liste de diaporamas disponibles. */

    diaporamaCourant = 0;
    imageCourante = 0;


    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    unsigned int choixDiaporama ;  // pour saisir le numéro de diaporama choisi par l'utilisiateur
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran
        unsigned int position = diaporamas[diaporamaCourant].localisationImages[imageCourante].pos;
        afficherImageCouranteDansDiaporamaCourant (diaporamas[diaporamaCourant], imageCourante, images[position]);


        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        saisieVerifChoixActionSurImageCourante(choixAction);
        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
        declencherAction(choixAction, diaporamas, diaporamaCourant, imageCourante, images);
    }

    /* Fin
       --------------*/
    cout << "Au revoir " << endl;
}

