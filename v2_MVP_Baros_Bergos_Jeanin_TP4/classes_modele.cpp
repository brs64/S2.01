#include "classes_modele.h"



//Méthodes ImgMdl


//constructeurs et destructeur
ImgMdl::ImgMdl(string t, string ch, string cat): //constructeur par défaut
    titre(t),
    chemin(ch),
    categorie(cat){
}

ImgMdl::ImgMdl(const ImgMdl& img): //constructeur de copie
    titre(img.titre),
    chemin(img.chemin),
    categorie(img.categorie){
}

ImgMdl::~ImgMdl(){
}


//setters et getters
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


//autre
void ImgMdl::afficher() const {

}



//Méthodes ImgDsDiapoMdl


//constructeurs et destructeur
ImgDsDiapoMdl::ImgDsDiapoMdl(const ImgMdl& img, unsigned int p, unsigned int r): //constructeur par défaut
    ImgMdl(img),
    pos(p),
    rang(r){
}

ImgDsDiapoMdl::ImgDsDiapoMdl(const ImgDsDiapoMdl & img):
    ImgMdl(img),
    pos(img.pos),
    rang(img.rang){
}

ImgDsDiapoMdl::~ImgDsDiapoMdl(){
}


//setters et getters
unsigned int ImgDsDiapoMdl::getPos() const{
    return (*this).pos;
}

void ImgDsDiapoMdl::setPos(unsigned int p){
    (*this).pos = p;
}

unsigned int ImgDsDiapoMdl::getRang() const{
    return (*this).rang;
}

void ImgDsDiapoMdl::setRang(unsigned int r){
    (*this).rang = r;
}


//autre
void ImgDsDiapoMdl::chargerImgDsDiapo(){
//nous n'avons pas encore d'image à charger
}



//Méthodes de DiapoMdl


//constructeurs et destructeur
DiapoMdl::DiapoMdl(const ImagesDansDiaporama& img, string t, unsigned int v, unsigned int p): //constructeur par défaut
    titre(t),
    vitesseDefilement(v),
    localisationImages(img),
    posImageCourante(p){
}

DiapoMdl::DiapoMdl(const DiapoMdl& diapo):
    titre(diapo.titre),
    vitesseDefilement(diapo.vitesseDefilement),
    localisationImages(diapo.localisationImages),
    posImageCourante(diapo.posImageCourante){
}

DiapoMdl::~DiapoMdl(){
}


//setters et getters
string DiapoMdl::getTitre() const{
    return (*this).titre;
}

void DiapoMdl::setTitre(string s){
    (*this).titre = s;
}

unsigned int DiapoMdl::getVitesseDefilement() const{
    return (*this).vitesseDefilement;
}

void DiapoMdl::setVitesseDefilement(unsigned int v){
    (*this).vitesseDefilement = v;
}

ImagesDansDiaporama DiapoMdl::getLocalisationImages() const{
    return (*this).localisationImages;
}


void DiapoMdl::setLocalisationImages(ImagesDansDiaporama& l){
    (*this).localisationImages = l;
}

unsigned int DiapoMdl::getPosImageCourante() const{
    return (*this).posImageCourante;
}

void DiapoMdl::setPosImageCourante(unsigned int p){
    (*this).posImageCourante = p;
}

ImgDsDiapoMdl DiapoMdl::getImageCourante() const{
//nous n'avons pas encore d'image à retourner
}



//autre
void DiapoMdl::chargerDiapo(){
//nous n'avons pas encore de diaporama à charger
}

unsigned int DiapoMdl::nbImages() const{
    return (*this).getLocalisationImages().size();
}

void DiapoMdl::avancer(){
    if((*this).getPosImageCourante() == (*this).nbImages() - 1)
    {
        (*this).setPosImageCourante(0);
    }
    else
    {
        (*this).setPosImageCourante((*this).posImageCourante + 1);
    }
}


void DiapoMdl::reculer(){
    if((*this).getPosImageCourante() == 0)
    {
        (*this).setPosImageCourante((*this).nbImages() - 1);
    }
    else
    {
        (*this).setPosImageCourante((*this).posImageCourante - 1);
    }
}

void DiapoMdl::triCroissantRang(){   //tri par ordre croissant les images du diaporama par la méthode du triBulle
    ImgDsDiapoMdl img;
    for (unsigned int ici = (*this).nbImages()-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if ((*this).getLocalisationImages()[i].getRang() > (*this).getLocalisationImages()[i+1].getRang())
            {
                // echanger les 2 éléments
                img = (*this).getLocalisationImages()[i];
                (*this).getLocalisationImages()[i] = (*this).getLocalisationImages()[i+1];
                (*this).getLocalisationImages()[i+1] = img;
            }
        }
    }
}

void DiapoMdl::clear(){
    //ne pouvant par charger le diaporama, nous ne pouvons pas le décharger
}



//Méthodes de LecteurMdl


//constructeur et destructeur
LecteurMdl::LecteurMdl(): //constructeur par défaut
    m_mode(Manuel){
}

LecteurMdl::~LecteurMdl(){
}


//setters et getters
void LecteurMdl::setMode(Mode m){
    (*this).m_mode = m;
}

Mode LecteurMdl::getMode() const{
    return (*this).m_mode;
}


//autre
void LecteurMdl::changerMode(){

    if ((*this).m_mode == Manuel){
        (*this).setMode(Auto);
    }
    else {
        (*this).setMode(Manuel);
    }
}
