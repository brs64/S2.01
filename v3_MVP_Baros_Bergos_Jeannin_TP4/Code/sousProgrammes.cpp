#include "sousProgrammes.h"
#include "image.h"
#include "diaporama.h"

void charger(Diaporamas& pDiaporamas)
{
    Image imageACharger;
    ImageDansDiaporama imageDansDiapo;
    Diaporama diaporama;

    // Diaporama par défaut
    diaporama.titre = "Diaporama par defaut";
    diaporama.vitesseDefilement = 1;

    // L'unique image du diaporama par défaut
    imageDansDiapo.pos = 0;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Pantxika
    diaporama.titre = "Diaporama Pantxika";
    diaporama.vitesseDefilement = 2;

    // Les images du diaporama de Pantxika
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Thierry
    diaporama.titre = "Diaporama Thierry";
    diaporama.vitesseDefilement = 4;

    // Les images du diaporama de Thierry
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Yann
    diaporama.titre = "Diaporama Yann";
    diaporama.vitesseDefilement = 3;

    // Les images du diaporama de Yann
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Manu
    diaporama.titre = "Diaporama Manu";
    diaporama.vitesseDefilement = 1;

    // Les images du diaporama de Yann
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

}
void charger (Images& pImages) {
    Image imageACharger;
    imageACharger = Image("objet", "", "..\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Blanche Neige", "..\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Alice", "..\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("animal", "Mickey", "..\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Pinnochio", "..\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("objet", "chateau", "..\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Minnie", "..\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("animal", "Bambi", "..\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}
