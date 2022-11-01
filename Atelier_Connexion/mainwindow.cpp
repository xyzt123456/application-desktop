#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <employes.h>
#include <QIntValidator>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    QString noun=ui->le_nom->text();
    QString adress=ui->le_adresse->text();
    QString occupation=ui->le_occupation->text();
    QString password=ui->le_mdp->text();
    Employes E(id,cin,noun,adress,occupation,password);
        bool test=E.ajouter();
        if(test)
       {
            ui->tab_employe->setModel(E.afficher());
          QMessageBox::information(nullptr, QObject::tr("ok"),
          QObject::tr("ajout effectue.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);

       }
        else
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
         QObject::tr("ajout non effectue.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{
    int id =ui->le_id_sup->text().toInt();
       bool test=E.supprimer(id);
       if(test)
      {
           ui->tab_employe->setModel(E.afficher());
         QMessageBox::information(nullptr, QObject::tr("ok"),
         QObject::tr("suppression effectue.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_employe->setModel(E.afficher());
      }
       else
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
         QObject::tr("suppression non effectue.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}
