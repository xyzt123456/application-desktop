#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>


#include"client.h"
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


    void on_b_ajouter_clicked();

    void on_b_supprimer_clicked();

    void on_b_modifier_clicked();

    void on_rechercher_clicked();

    void on_pdf_clicked();

    void on_tri_clicked();

private:
    Ui::MainWindow *ui;
Client c;
};

#endif // MAINWINDOW_H
