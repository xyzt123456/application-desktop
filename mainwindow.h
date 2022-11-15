#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>

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
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_modifier_clicked();

    void on_recherche_2_clicked();

    void on_tri_id_clicked();

    void on_tri_noun_clicked();



    void on_PDF_clicked();

    void on_statistique_clicked();

    void on_qr_clicked();

private:
    Ui::MainWindow *ui;
    Employes E;
};

#endif // MAINWINDOW_H
