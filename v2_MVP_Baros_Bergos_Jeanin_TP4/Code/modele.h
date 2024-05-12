#ifndef MODELE_H
#define MODELE_H
#include <QObject>
#include "diaporama.h"
#include <iostream>
using namespace std;

class Modele : public QObject {
    Q_OBJECT

    private:
        Diaporama* diaporama;


    public:
        explicit Modele(QObject *parent = nullptr);

        Diaporama* getDiaporama();
        void setDiaporama(Diaporama*);

        void avancer();
        void reculer();
};


#endif // MODELE_H
