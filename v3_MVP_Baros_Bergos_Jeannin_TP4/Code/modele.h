#ifndef MODELE_H
#define MODELE_H
#include <QObject>
#include "diaporama.h"
#include <iostream>
using namespace std;

class Modele : public QObject {
    Q_OBJECT

    private:
        Diaporama* diaporama; //pointeur pour transmettre les instructions à la classe diaporama


    public:
        explicit Modele(QObject *parent = nullptr); //constructeur (par défaut)

        // Setter et getter
        void setDiaporama(Diaporama*);
        Diaporama* getDiaporama();

        // Autres
        void avancer();
        void reculer();
};


#endif // MODELE_H
