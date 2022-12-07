#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"materiel.h"
#include"popup.h"
#include"popupp.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Ig_Materiel : public QMainWindow
{
    Q_OBJECT

public:
    Ig_Materiel(QWidget *parent = nullptr);
    ~Ig_Materiel();


private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();



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
    Ui::MainWindow *ui;
    Materiel m;
    PopUp *popUp;
    PopUpp *popUpp;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
