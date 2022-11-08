 #include "ui_mainwindow.h"
#include "mainwindow.h"
#include "client.h"
#include<QMessageBox>
#include <QSqlQueryModel>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator (new QIntValidator(100, 9999999, this));
    ui->tab_client->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_b_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    int tel=ui->le_tel->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString adresse=ui->le_adresse->text();
    QString date_naisc=ui->dateEdit_2->text();

Client C(cin,tel,nom,prenom,date_naisc,adresse);

    bool test=C.ajouter();

    if (test)

    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_b_supprimer_clicked()
{
    int cin=ui->le_cin_2->text().toInt();
    bool test=c.supprimer(cin);
            if (test)

            {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("suppression effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("suppression non effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_b_modifier_clicked()
{
    int cin=ui->le_cin_3->text().toInt();
    int tel=ui->le_tel_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString adresse=ui->le_adresse_2->text();
    QString date_naisc=ui->dateEdit->text();
    Client C(cin,tel,nom,prenom,date_naisc,adresse);
    bool test=c.modifier();
            if (test)

            {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("modification  effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("modification non effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}



