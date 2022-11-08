#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"reservation.h"
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_cin->setValidator( new QIntValidator(0,99999999,this));
   ui->tab_reservation->setModel(r.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString num_salle=ui->le_num_salle->text();
    QString type=ui->le_type->text();
reservation R(cin,nom,prenom,num_salle,type);
bool test=R.ajouter();
if(test)
{ui->tab_reservation->setModel(r.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("ajout effectuer.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

     }
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr("ajout n'est pas effectuer.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


 }



void MainWindow::on_supprimer_clicked()
{
    int cin= ui->le_cin_supp->text().toInt();

    bool test=r.supprimer(cin);
    if (test)
    {ui->tab_reservation->setModel(r.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
          {  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("suppression n'est pas effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}
 }

void MainWindow::on_b_modifier_clicked()
{
    int cin=ui->le_cin_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString num_salle=ui->le_num_salle_2->text();
    QString type=ui->le_type_2->text();
     reservation R(cin,nom,prenom,num_salle,type);
    bool test=R.modifier();
    if (test)
    {ui->tab_reservation->setModel(r.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("modification effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
           { QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("modification n'est pas effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}
