#include "client.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include  <QString>
#include <QtDebug>
#include <QObject>
/*#include<QtCharts/QPieSeries>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSlice>
#include<QtCharts/QChart>
#include<QtCharts/QChartView>
#include<QtCharts/QPieSlice>
#include <Charts>
*/
Client::Client()
{
  cin=0;
  tel=0;
  nbr=0;
  code=0;
  nom="";
  prenom="";
  adresse="";
  date_naisc="";
  type="";
  date_de_res="";
}

Client::Client(int cin,QString nom,QString prenom,QString date_naisc,int tel,QString type,int nbr,QString adresse,QString date_de_res,int code)

{ this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->date_naisc=date_naisc;
  this->tel=tel;
  this->type=type;
  this->nbr=nbr;
  this->adresse=adresse;
  this->date_de_res=date_de_res;
  this->code=code;



}
    int Client::getCin(){return cin;}
    QString Client::getNom(){return nom;}
    QString Client::getPrenom(){return prenom;}
    QString Client::getDate_naisc(){return date_naisc;}
    int Client::getTel(){return tel;}
    QString Client::getType(){return type;}
    int Client::getNbr(){return nbr;}
    QString Client::getAdresse(){return adresse;}
    QString Client::getDate_de_res(){return date_de_res;}
    int Client::getCode(){return code;}





    void Client::setCin(int cin){this->cin=cin;}
    void Client::setNom (QString nom){this->nom=nom;}
    void Client::setPrenom(QString prenom){this->prenom=prenom;}
    void Client::setDate_naisc(QString date_naisc){this->date_naisc=date_naisc;}
    void Client::setTel(int tel){this->tel=tel;}
    void Client::setType(QString type){this->type=type;}
    void Client::setNbr(int  nbr){this->nbr=nbr;}
    void Client::setAdresse(QString adresse){this->adresse=adresse;}
    void Client::setDate_de_res(QString date_de_res){this->date_de_res=date_de_res;}
    void Client::setCode(int code){this->code=code;}


    bool Client::ajouter()
    {
        QSqlQuery query;
        QString cin_string=QString::number(cin);
        QString tel_string=QString::number(tel);
        QString nbr_string=QString::number(nbr);
        QString code_string=QString::number(code);

        query.prepare("INSERT INTO CLIENT (CIN,NOM,PRENOM,DATE_DE_NAISANNCE,TELEPHONE,TYPE,NBR,ADRESSE,DATE_DE_RES,CODE) "
                      "values (:CIN , :NOM, :PRENOM,:DATE_DE_NAISANNCE,:TELEPHONE,:TYPE,:NBR,:ADRESSE,:DATE_DE_RES,:CODE)");
        query.bindValue(0, cin_string);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, date_naisc);
        query.bindValue(4, tel_string);
        query.bindValue(5, type);
        query.bindValue(6,nbr);
        query.bindValue(7,adresse);
        query.bindValue(8,date_de_res);
        query.bindValue(9,code_string);

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
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr"));
               model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
               model->setHeaderData(8, Qt::Horizontal, QObject::tr("date_de_res"));
               model->setHeaderData(9,Qt::Horizontal,  QObject::tr("code"));



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
    QString nbr_string=QString::number(nbr);
    QString code_string=QString::number(code);
    query.prepare("update client set NOM='"+nom+"',PRENOM='"+prenom+"',DATE_DE_NAISANNCE='"+date_naisc+"',TELEPHONE='"+tel_string+"',TYPE='"+type+"',NBR='"+nbr_string+"',ADRESSE='"+adresse+"', DATE_DE_RES='"+date_de_res+"', CODE='"+code_string+"' where CIN='"+cin_string+"'");

    return query.exec();

}

QSqlQueryModel *Client::recherche_client(QString recherche)

{ QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM client WHERE CIN like '"+recherche+"%' or NOM like '"+recherche+"%' or PRENOM like '"+recherche+"%' or DATE_DE_NAISANNCE like '"+recherche+"%' or TELEPHONE like '"+recherche+"%' or TYPE like '"+recherche+"%' or ADRESSE like '"+recherche+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naisc"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("date_de_res"));
    model->setHeaderData(9,Qt::Horizontal,  QObject::tr("code"));


    return model;

}

QSqlQueryModel * Client::tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel;

          model->setQuery("SELECT * FROM client ORDER BY nom ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naisc"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("date_de_res"));
          model->setHeaderData(9,Qt::Horizontal,  QObject::tr("code"));

    return model;
}

QSqlQueryModel *Client::client_fidele()
{
    QSqlQueryModel* model=new QSqlQueryModel();

               model->setQuery("SELECT * FROM client where nbr>=5");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naisc"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr"));
               model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
               model->setHeaderData(8, Qt::Horizontal, QObject::tr("date_de_res"));
               model->setHeaderData(9,Qt::Horizontal,  QObject::tr("code"));


               return model;
}
