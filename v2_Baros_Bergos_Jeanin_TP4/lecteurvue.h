#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class lecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    explicit lecteurVue(QWidget *parent = nullptr); // Constructeur par défaut
    ~lecteurVue(); // Destructeur

public slots :
    // Déclaration des différents slots
    void demanderFiltres();
    void demanderVitesseDefilement();
    void demanderChargerDiaporama();
    void demanderQuitter();
    void demanderAProposDe();
    void demanderPrecedent();
    void demanderSuivant();
    void demanderPause();
    void demanderChangerModeDefilement();

private:
    Ui::lecteurVue *ui; // Interface utilisateur

};

#endif // LECTEURVUE_H
