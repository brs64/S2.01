#include "diaporama.h"

Diaporama::Diaporama():id(1), titre(""), vitesseDefilement(0) {
    images.clear();
    db = database();
}

Diaporama::~Diaporama()
{
    vider();
}

unsigned int Diaporama::getId() const
{
    return id;
}

string Diaporama::getTitre() const
{
    return titre;
}

int Diaporama::getVitesseDefilement() const
{
    return vitesseDefilement;
}

ImagesDiaporama Diaporama::getImages() const
{
    return images;
}

unsigned int Diaporama::getPosImageCourante() const
{
    return posImageCourante;
}

ImageDansDiaporama* Diaporama::getImageCourante() const
{
    return getImages()[getPosImageCourante()];
}

unsigned int Diaporama::nbImages() const
{
    return images.size();
}

void Diaporama::setId(unsigned int pId)
{
    id = pId;
}

void Diaporama::setTitre()
{
    QSqlQuery query;

   if (db.openDataBase()) {
    query.prepare("SELECT titreDiaporama FROM Diaporamas WHERE idDiaporama = :idDiaporama");
    query.bindValue(":idDiaporama", id);

    if(query.exec() && query.next())
    {
        this->titre = query.value(0).toString().toStdString();
    }
    else
    {
        qDebug() << "Erreur lors du chargement du titre : " << query.lastError().text() << "id = " << id;
    }
   }
   db.closeDataBase();
}

void Diaporama::setVitesseDefilement()
{
    if (db.openDataBase()) {
    QSqlQuery query;
    query.prepare("SELECT vitesseDefilement FROM Diaporamas WHERE idDiaporama = :idDiaporama");
    query.bindValue(":idDiaporama", this->id);

    if(query.exec() && query.next())
    {
        this->vitesseDefilement = query.value(0).toUInt();
    }
    else
    {
        qDebug() << "Erreur lors du chargement de la vitesse de défilement : " << query.lastError().text();
    }
    }
    db.closeDataBase();
}

void Diaporama::setImages(const ImagesDiaporama& pImages)
{
    images = pImages;
}

void Diaporama::ajouterImageEnFin(ImageDansDiaporama* pImage)
{
    images.push_back(pImage);

    // post-condition : nbImages() > 0
}

void Diaporama::enleverImageEnFin()
{
    if (nbImages() != 0)
    {
        images.pop_back();
    }

    // post-condition : nbImages() >= 0
}

void Diaporama::vider()
{
    unsigned int taille = nbImages();
    for (unsigned int i = 0; i < taille ; i++)
    {
        enleverImageEnFin(); /* Removes the last element in the vector,
                              effectively reducing the container size by one.
                              AND deletes the removed element */
    }
    // post-condition : nbImages() == 0
}

void Diaporama::charger()
{
    ImageDansDiaporama* imageACharger;
    QSqlQuery query;
    QString requete;

    if (db.openDataBase()) {
        requete = QString("SELECT F.nomFamille, DI.uriPhoto, DI.titrePhoto, DDD.rang "
                          "FROM Diapos DI "
                          "JOIN Familles F ON F.idFamille = DI.idFam "
                          "JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = DI.idphoto "
                          "JOIN Diaporamas D ON D.idDiaporama = DDD.idDiaporama "
                          "WHERE D.idDiaporama = :diaporamaId "
                          "ORDER BY DDD.rang;");
        query.prepare(requete);
        // Bind the external parameter value to the placeholder
        query.bindValue(":diaporamaId", id);

        if (query.exec()) {
            while (query.next()) {
                int rang = query.value(3).toInt();
                std::string categorie = query.value(0).toString().toStdString();
                std::string nomPersonnages = query.value(2).toString().toStdString();
                std::string path = ":/images/" + query.value(1).toString().toStdString();
                imageACharger = new ImageDansDiaporama(rang, categorie, nomPersonnages, path);
                ajouterImageEnFin(imageACharger);
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        }
        db.closeDataBase();
    } else {
        qDebug() << "Erreur lors de la connexion à la base de données";
    }

    trierParRangCroissant();  // trier par ordre croissant des rangs
}


void Diaporama::trierParRangCroissant()
{
    ImageDansDiaporama* pteurImage;
    unsigned int taille = nbImages();
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (images[i]->getRangDansDiaporama() > images[i+1]->getRangDansDiaporama())
            {
                // echanger les 2 éléments
                pteurImage = images[i];
                images[i] = images[i+1];
                images[i+1] = pteurImage;
            }
        }
    }
}
