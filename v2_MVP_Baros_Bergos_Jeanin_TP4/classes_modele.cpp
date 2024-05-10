#include "classes_modele.h"

string ImgMdl::getTitre() const {
    return (*this).titre;
}
void ImgMdl::setTitre(string s) {
    (*this).titre = s;
}

string ImgMdl::getCategorie() const{
    return (*this).categorie;
}
void ImgMdl::setCategorie(string s){
    (*this).categorie = s;
}

string ImgMdl::getChemin() const{
    return (*this).chemin;
}
void ImgMdl::setChemin(string s){
    (*this).chemin = s;
}

void ImgMdl::afficher() const {

}


void ImgDsDiapoMdl::chargerImgDsDiapo(){
//nous n'avons pas encore d'image à charger
}


void DiapoMdl::chargerDiapo(){
//nous n'avons pas encore de diaporama à charger
}


LecteurMdl::LecteurMdl(){
    (*this).m_mode = Manuel;
}

void LecteurMdl::setMode(Mode m){
    (*this).m_mode = m;
}

Mode LecteurMdl::getMode() const{
    return (*this).m_mode;
}

void LecteurMdl::changerMode(){

    if ((*this).m_mode == Manuel){
        (*this).setMode(Auto);
    }
    else {
        (*this).setMode(Manuel);
    }
}
