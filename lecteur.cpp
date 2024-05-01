#include "lecteur.h"
#include <iostream>
using namespace std;




Lecteur::Lecteur(const Diaporamas& pLocalisationDiaporamas, unsigned int pPosDiapoCourant, bool pMode):
    localisationDiaporamas(pLocalisationDiaporamas),
    posDiapoCourant(pPosDiapoCourant),
    modeAuto(pMode){}

Lecteur::Lecteur(const Lecteur& pLecteur):
    localisationDiaporamas(pLecteur.getDiapos()),
    posDiapoCourant(pLecteur.getPosDiapoCourant()),
    modeAuto(pLecteur.getMode()){}

Lecteur::~Lecteur() {}

Diaporamas Lecteur::getDiapos() const
{
    return (*this).localisationDiaporamas;
}

unsigned int Lecteur::getPosDiapoCourant() const
{
    return (*this).posDiapoCourant;
}

bool Lecteur::getMode() const
{
    return (*this).modeAuto;
}

void Lecteur::setDiapos(const Diaporamas& pDiapos)
{
    (*this).localisationDiaporamas = pDiapos;
}

void Lecteur::setPosDiapoCourant(unsigned int pPosDiapoCourant)
{
    (*this).posDiapoCourant = pPosDiapoCourant;
}

void Lecteur::setMode(bool pMode)
{
    (*this).modeAuto = pMode;
}

Diaporama Lecteur::getDiapoCourant() const
{
    return (*this).getDiapos()[(*this).getPosDiapoCourant()];
}

unsigned int Lecteur::nbDiapos() const
{
    return (*this).getDiapos().size();
}

void Lecteur::afficherImageCouranteDansDiaporamaCourant() const //Affiche l'image en cours de traitement dans le diaporama
{
    cout << endl << endl;
    cout << "DIAPORAMA : " << (*this).getDiapoCourant().getTitre() << endl << endl;
    cout << (*this).getDiapoCourant().getLocalisationImages()[(*this).getDiapoCourant().getPosImageCourante()].getRang() << " sur " <<  (*this).getDiapoCourant().nbImages() << " / ";
    (*this).getDiapoCourant().getLocalisationImages()[(*this).getDiapoCourant().getPosImageCourante()].afficher();
}

void Lecteur::saisieVerifChoixActionSurImageCourante(char& pChoixAction) //propose et traite les actions possibles de l'utilisateur pendant le diaporama
{
    cout << endl << endl;
    while (true)
    {
        cout  << endl ;
        cout << "ACTIONS :" << "  A-vancer" << "  R-eculer" << "  C-hanger de diaporama " << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}

unsigned int Lecteur::saisieVerifChoixDiaporama() //propose et traite les actions possibles de l'utilisateur pour le choix du diaporama
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
        cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < (*this).nbDiapos(); num++)
        {
            cout << num << ": " << (*this).getDiapos()[num].getTitre();
            if (num != (*this).nbDiapos()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(static_cast<unsigned int>(choixDiaporama) < (*this).nbDiapos()))
        {
            break;
        }
    }
    return choixDiaporama;
}

void Lecteur::declencherAction(char pChoixAction) //Traite les actions saisies par l'utilisateur
{
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
    case 'A':
        (*this).getDiapoCourant().avancer();
        (*this).afficherImageCouranteDansDiaporamaCourant();
        break;
    case 'R':
        (*this).getDiapoCourant().reculer();
        (*this).afficherImageCouranteDansDiaporamaCourant();
        break;
    case 'C' :
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = (*this).saisieVerifChoixDiaporama();
        // Changer de diaporama
        (*this).setPosDiapoCourant(choixDiaporama);
        (*this).getDiapoCourant().setPosImageCourante(0);
        break;

    default : break;
    }
}

void Lecteur::charger (Images& pImages) // charge les images du diaporamas
{
    Image imageACharger;
    imageACharger = Image("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}

void Lecteur::charger (Diaporamas& pDiaporamas) //Charge un diaporama
{
    ImageDansDiaporama imageDansDiapo;

    // Diaporama par défaut
    Diaporama diaporama;

    // L'unique image du diaporama par défaut
    imageDansDiapo.setPos(0);
    imageDansDiapo.setRang(1);
    diaporama.pushBackImage(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.clear();

    // Diaporama de Pantxika
    diaporama.setTitre("Diaporama Pantxika");
    diaporama.setVitesseDefilement(2);

    // Les images du diaporama de Pantxika
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(3);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(2);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(4);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(1);
    diaporama.pushBackImage(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.clear();

    // Diaporama de Thierry
    diaporama.setTitre("Diaporama Thierry");
    diaporama.setVitesseDefilement(4);

    // Les images du diaporama de Thierry
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(1);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(2);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(3);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(4);
    diaporama.pushBackImage(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.clear();

    // Diaporama de Yann
    diaporama.setTitre("Diaporama Yann");
    diaporama.setVitesseDefilement(3);

    // Les images du diaporama de Yann
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(2);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(1);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(4);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(3);
    diaporama.pushBackImage(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.clear();

    // Diaporama de Manu
    diaporama.setTitre("Diaporama Manu");
    diaporama.setVitesseDefilement(1);

    // Les images du diaporama de Yann
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(4);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(3);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(2);
    diaporama.pushBackImage(imageDansDiapo);
    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(1);
    diaporama.pushBackImage(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.clear();
}
