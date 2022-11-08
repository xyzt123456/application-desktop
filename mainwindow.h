#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"reservation.h"
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

    void on_b_ajouter_clicked();

    void on_supprimer_clicked();

    void on_b_modifier_clicked();

private:
    Ui::MainWindow *ui;
    reservation r;
};

#endif // MAINWINDOW_H
