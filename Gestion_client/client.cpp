#include "client.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include  <QString>
#include <QtDebug>
#include <QObject>
Client::Client()
{
  cin=0;
  tel=0;
  nom="";
  prenom="";
  adresse="";
  date_naisc="";
}

Client::Client(int cin,int tel,QString nom,QString prenom,QString adresse,QString date_naisc)
{ this->cin=cin;
  this->tel=tel;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->date_naisc=date_naisc;

}
    int Client::getCin(){return cin;}
    int Client::getTel(){return tel;}
    QString Client::getNom(){return nom;}
    QString Client::getPrenom(){return prenom;}
    QString Client::getAdresse(){return adresse;}
    QString Client::getDate_naisc(){return date_naisc;}

    void Client:: setCin(int cin){this->cin=cin;}
    void Client::setTel(int tel){this->tel=tel;}
    void Client::setNom (QString nom){this->nom=nom;}
    void Client::setPrenom(QString prenom){this->prenom=prenom;}
    void Client::setAdresse(QString adresse){this->adresse=adresse;}
    void Client::setDate_naisc(QString date_naisc){this->date_naisc=date_naisc;}

    bool Client::ajouter()
    {
        QSqlQuery query;
        QString cin_string=QString::number(cin);
        QString tel_string=QString::number(tel);
        query.prepare("INSERT INTO client (cin, nom,prenom,date_de_naissance,adresse,telephone) "
                      "VALUES (:cin, :nom, :prenom,:date_de_naissance,adresse,telephone)");
        query.bindValue(":cin", cin_string);
        query.bindValue(":telephone", tel_string);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":date_de_naissance", date_naisc);
        query.bindValue(":adresse", adresse);

        return query.exec();


    }
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

               model->setQuery("SELECT * FROM client");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naisc"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));

               return model;

}
bool Client::supprimer(int cin)
{
  QSqlQuery query;
QString cin_string=QString::number(cin);
query.prepare("delete from client where CIN= :cin");
query.bindValue(":id",cin_string);
return query.exec();
}
bool Client::modifier()
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString tel_string=QString::number(tel);
    query.prepare("update client set nom='"+nom+"',prenom='"+prenom+"',date_naisc='"+date_naisc+"',adresse='"+adresse+"',tel='"+tel_string+"'where cin='"+cin_string+"'");
    /*query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_de_naissance", date_naisc);
    query.bindValue(":adresse", adresse);
     query.bindValue(":telephone", tel_string);*/

    return query.exec();

}
