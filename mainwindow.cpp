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

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->le_id_2->text().toInt();
            int cin= ui->le_cin_2->text().toInt();
             QString noun= ui->le_nom_2->text();
             QString adresse= ui->le_adresse_2->text();
             QString occupation= ui->le_occupation_2->text();
             QString password= ui->le_mdp_2->text();



           Employes E(id,cin,noun,adresse,occupation,password);
            bool test=E.modifier(id);
            if(test)
            {

                ui->tab_employe->setModel(E.afficher());//refresh
                       QMessageBox::information(nullptr, QObject::tr("effectué"),
                            QObject::tr(" Modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                       ui->le_id_2->clear();
                       ui->le_cin_2->clear();
                       ui->le_nom_2->clear();
                       ui->le_adresse_2->clear();
                       ui->le_occupation_2->clear();
                       ui->le_mdp_2->clear();

           }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                            QObject::tr("non modifié !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->le_id_2->clear();
                ui->le_cin_2->clear();
                ui->le_nom_2->clear();
                ui->le_adresse_2->clear();
                ui->le_occupation_2->clear();
                ui->le_mdp_2->clear();




            }
}


void MainWindow::on_recherche_2_clicked()
{
    Employes Etmp;
    ui->tab_employe->setModel(Etmp.recherche_employe(ui->recherche->text()));
}

void MainWindow::on_tri_id_clicked()
{
    Employes Etmp;
    ui->tab_employe->setModel(Etmp.triID());
}

void MainWindow::on_tri_noun_clicked()
{
    Employes Etmp;
    ui->tab_employe->setModel(Etmp.triNOM());
}
