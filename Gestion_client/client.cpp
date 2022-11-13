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
  type="";
}

Client::Client(int cin,int tel,QString nom,QString prenom,QString adresse,QString date_naisc,QString type)
{ this->cin=cin;
  this->tel=tel;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->date_naisc=date_naisc;
  this->type=type;

}
    int Client::getCin(){return cin;}
    int Client::getTel(){return tel;}
    QString Client::getNom(){return nom;}
    QString Client::getPrenom(){return prenom;}
    QString Client::getAdresse(){return adresse;}
    QString Client::getDate_naisc(){return date_naisc;}
    QString Client::getType(){return type;}

    void Client:: setCin(int cin){this->cin=cin;}
    void Client::setTel(int tel){this->tel=tel;}
    void Client::setNom (QString nom){this->nom=nom;}
    void Client::setPrenom(QString prenom){this->prenom=prenom;}
    void Client::setAdresse(QString adresse){this->adresse=adresse;}
    void Client::setDate_naisc(QString date_naisc){this->date_naisc=date_naisc;}
    void Client::setType(QString type){this->type=type;}

    bool Client::ajouter()
    {
        QSqlQuery query;
        QString cin_string=QString::number(cin);
        QString tel_string=QString::number(tel);
        query.prepare("INSERT INTO client (cin, nom,prenom,date_de_naissance,telephone,adresse) "
                      "VALUES (:cin, :nom, :prenom,:date_de_naissance,:telephone,:type,:adresse)");
        query.bindValue(":cin", cin_string);
        query.bindValue(":nom", tel_string);
        query.bindValue(":prenom", nom);
        query.bindValue(":date_de_naissance", prenom);
        query.bindValue(":telephone", date_naisc);
        query.bindValue(":adresse", type);
        query.bindValue(":type",adresse);

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
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));


               return model;

}
bool Client::supprimer(int cin)
{
  QSqlQuery query;
QString cin_string=QString::number(cin);
query.prepare("delete from client where CIN= :cin");
query.bindValue(":cin",cin_string);
return query.exec();
}
bool Client::modifier()
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString tel_string=QString::number(tel);
    query.prepare("update client set nom='"+nom+"',prenom='"+prenom+"',date_naisc='"+date_naisc+"',='"+type+"',adresse='"+adresse+"',tel='"+tel_string+"'where cin='"+cin_string+"'");

    return query.exec();

}

QSqlQueryModel *Client::recherche_client(QString recherche)

{ QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM client WHERE cin like '"+recherche+"%' or nom like '"+recherche+"%' or prenom like '"+recherche+"%' or date_naisc like '"+recherche+"%' or tel like '"+recherche+"%' or type like '"+recherche+"%' or adresse like '"+recherche+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naisc"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));


    return model;

}

QSqlQueryModel * Client::tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel;

          model->setQuery("SELECT * FROM client ORDER BY nom ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

