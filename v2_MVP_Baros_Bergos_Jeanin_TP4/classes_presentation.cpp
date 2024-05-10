#include "classes_presentation.h"
#include "classes_modele.h"
#include "lecteurvue.h"




/*
void ImgPres::demandeChangerTitre(string s) {
    _modele->setTitre(s);
}

void ImgPres::demandeChangerCat(string s) {
    _modele->setCategorie(s);

}

void ImgPres::demandeChangerChemin(string s) {
    _modele->setChemin(s);
}
*/



//méthodes de ImgDsDiapoPres

void ImgDsDiapoPres::demanderChargerImg(){
    _modele->chargerImgDsDiapo();
    _lecteur->majInfosImgDsDiapo();
}



//méthodes de DiapoPres

DiapoPres::DiapoPres(){} //constructeur par défaut

void DiapoPres::demanderChargerDiapo(){
    _modele->chargerDiapo();
    _lecteur->majInfosDiapo();
}



//méthodes de LecteurPres

LecteurPres::LecteurPres(){} //constructeur par défaut

bool LecteurPres::verifAuto(){
    if (_modele->getMode() == Auto){
        return true;
    }
    return false;
}

void LecteurPres::changerMode(){
    _modele->LecteurMdl::changerMode();
    if (_modele->getMode() == Manuel){
        _lecteur->majMode(Manuel);
    }
    else{
        _lecteur->majMode(Auto);
    }
}





























/*
void DiapoPres::demandeChangerTitre(string) {

}
*/

void DiapoPres::demandeChangerVitesse(unsigned int) {

}
/*
void DiapoPres::demandeChangerlocImgs(ImagesDansDiaporama) {

}

void DiapoPres::demandeChangerPosImgCourate(unsigned int) {

}
*/

// ###############################################################




