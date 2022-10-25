#include "materiel.h"
#include<QSqlQuery>
#include<QString>
#include<QObject>

Materiel::Materiel()
{
    matricule=0;
    libelle="";
    marque="";
    qte=0;
    prix=0;
    etat=1;
}
Materiel::Materiel(int matricule,QString libelle,QString marque,int qte,float prix,int etat)
{
    this->matricule=matricule;
    this->libelle=libelle;
    this->marque=marque;
    this->qte=qte;
    this->prix=prix;
    this->etat=etat;
}
bool Materiel::ajouter()
{
    QString mat_string=QString::number(matricule);
    QString qte_string=QString::number(qte);
    QString prix_string=QString::number(prix);
    QString etat_string=QString::number(etat);

    QSqlQuery query;
          query.prepare("INSERT INTO materiel (matricule, libelle, marque,quantite,prix,etat) "
                        "VALUES (:matricule, :libelle, :marque, :quantite, :prix, :etat)");
          query.bindValue(0, mat_string);
          query.bindValue(1, libelle);
          query.bindValue(2, marque);
          query.bindValue(3, qte_string);
          query.bindValue(4, prix_string);
          query.bindValue(5, etat_string);
          return query.exec();
}
QSqlQueryModel* Materiel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM materiel");
          //pour nommer les colonnes par des noms de notre choix sinon il va afficher les noms des colonnes dans BD
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libéllé"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Marque"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}
bool Materiel::supprimer(int mat)
{
    QString mat_string=QString::number(mat);
    QSqlQuery query;
          query.prepare("DELETE FROM materiel WHERE matricule=:mat ");
          query.bindValue(0, mat_string);
    return query.exec();
}
bool Materiel::modifier(int mat)
{
    QString mat_string=QString::number(mat);
    QString qte_string=QString::number(qte);
    QString prix_string=QString::number(prix);
    QString etat_string=QString::number(etat);

    QSqlQuery query;
          query.prepare(" UPDATE materiel SET libelle = libelle,marque = marque,quantite = qte,prix=prix,etat=etat WHERE mat = matricule");
          query.bindValue(0, mat_string);
          query.bindValue(1, libelle);
          query.bindValue(2, marque);
          query.bindValue(3, qte_string);
          query.bindValue(4, prix_string);
          query.bindValue(5, etat_string);
    return query.exec();

}

