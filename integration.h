#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QWidget>

#include "employes.h"
#include"materiel.h"
#include"popup.h"
#include"popupp.h"
#include"arduino.h"
#include <QMainWindow>

namespace Ui {
class integration;
}

class integration : public QMainWindow
{
    Q_OBJECT

public:
    explicit integration(QWidget *parent = nullptr);
    ~integration();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_modifier_clicked();

    void on_recherche_2_clicked();

    void on_tri_id_clicked();

    void on_tri_noun_clicked();



    void on_PDF_clicked();

    void on_statistique_clicked();

    void on_qr_clicked();

    void on_pb_ajouter_m_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_m_clicked();


//materiels
    void on_recherche_clicked();

    void on_pdf_clicked();

    void on_pb_map_clicked();

    void on_pb_stat_clicked();

    void on_pb_decr_clicked();

    void on_pb_cr_clicked();

    void on_pb_notification_clicked();

    void on_pb_refrech_clicked();

    void update();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

private:
    Ui::integration *ui;
    Employes E;
    Materiel m;
    PopUp *popUp;
    PopUpp *popUpp;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
