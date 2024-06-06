#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>
#include "modele.h"

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class Presentation;
class lecteurVue : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::lecteurVue *ui;
        Presentation * m_MaPresentation;


    public:
        lecteurVue(QWidget *parent = nullptr); // Constructeur par défaut
        ~lecteurVue(); // Destructeur par défaut

        // Getter
        Presentation * getPresentation() const;

        // Setter
        void setPresentation(Presentation *);

        // Autres
        void afficherMode(QString); // permet d'afficher le mode de défilement du diaporama dans la fenêtre
        void initializeConnections();


    public slots:
        void demanderPause();
        void demanderAvancer();
        void demanderReculer();
        void demanderChangerVitesse();
        void demanderChangerMode();
        void demanderFiltre();
        void demanderChargerDiapo();
        void demanderAProposDe();
        void quitterApplication();
        void majPresentation(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin);
};
#endif // LECTEURVUE_H
