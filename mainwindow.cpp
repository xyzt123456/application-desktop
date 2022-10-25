#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"materiel.h"
#include<QString>
#include<QIntValidator>
#include<QMessageBox>
#include<QRadioButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_mat->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_materiel->setModel(m.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int mat=ui->le_mat->text().toInt();
    QString lib=ui->le_lib->text();
    QString marq=ui->le_marq->text();
    int qte=ui->le_qte->text().toInt();
    float prix=ui->le_prix->text().toFloat();

    int e;

    if(ui->rb_ok->isCheckable())
    {e=0;}
    if(ui->rb_no->isCheckable())
    {e=1;}

    Materiel m(mat,lib,marq,qte,prix,e);
    bool test=m.ajouter();

    QMessageBox msgBox;
    if(test)
        msgBox.setText("ajout avec succes.");
    else
        msgBox.setText("echec d'ajout.");
    msgBox.exec();
}



void MainWindow::on_pb_supp_clicked()
{
    Materiel m1;
    m1.setMatricule(ui->le_mat_supp->text().toInt());
    bool test=m1.supprimer(m1.getMatricule());

    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("suppression avec succes.");
        ui->tab_materiel->setModel(m.afficher());
    }
    else
        msgBox.setText("echec de suppresion.");
    msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int mat=ui->le_mat->text().toInt();
    QString lib=ui->le_lib->text();
    QString marq=ui->le_marq->text();
    int qte=ui->le_qte->text().toInt();
    float prix=ui->le_prix->text().toFloat();
    int e;

    if(ui->rb_ok->isCheckable())
    {e=0;}
    if(ui->rb_no->isCheckable())
    {e=1;}

    Materiel m(mat,lib,marq,qte,prix,e);

    bool test=m.modifier(mat);

    QMessageBox msgBox;
    if(test)
        msgBox.setText("modification avec succes.");
    else
        msgBox.setText("echec de modification.");
    msgBox.exec();
}


