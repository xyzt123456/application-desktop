#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"client.h"
#include "smtp.h"
#include "arduino.h"

#include<QPainter>
#include<QTextDocument>
#include<QTextStream>
#include<QPdfWriter>
#include <QDataStream>
#include<QDesktopServices>
#include<QFontDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //CRUD

    void on_b_ajouter_clicked();

    void on_b_supprimer_clicked();

    void on_b_modifier_clicked();

    //métiers

    void on_rechercher_clicked();

    void on_pdf_clicked();

    void on_tri_clicked();

    void on_envoyer_clicked();

    void on_stat_currentChanged(int index);

    void on_stat_2_clicked();

private:
    Ui::MainWindow *ui;
Client c;



private slots:

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_clicked();   // bouton ON

    void on_pushButton_2_clicked(); // bouton OFF

    void on_pushButton_3_clicked(); // bouton +

    void on_pushButton_4_clicked(); // bouton -

    void on_fd_clicked();

private:


    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};





#endif // MAINWINDOW_H



