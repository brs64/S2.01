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
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();
    Presentation * getPresentation() const;
    void setPresentation(Presentation *);
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
