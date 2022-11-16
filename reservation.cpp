#include "reservation.h"
#include<QSqlQueryModel>
#include<QObject>
#include<QtDebug>


reservation::reservation()
{
cin=0;
nom="";
prenom="";
num_salle="";
type="";
}
 reservation::reservation(int cin,QString nom,QString prenom,QString num_salle,QString type)
 {this->cin=cin;
     this->nom=nom;
     this->prenom=prenom;
     this->num_salle=num_salle;
     this->type=type;

 }
 bool reservation::ajouter()
 {
     QSqlQuery query;
     QString cin_string=QString::number(cin);
     query.prepare("INSERT INTO reservation (cin, nom, prenom,num_salle,type) "
                   "VALUES (:cin, :nom, :prenom, :num_salle, :type)");
     query.bindValue(":cin", cin_string);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":num_salle", num_salle);
     query.bindValue(":type", type);
     return query.exec();

 }
 QSqlQueryModel* reservation::afficher()
 {
     QSqlQueryModel *model = new QSqlQueryModel;
           model->setQuery("SELECT * FROM reservation");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_salle"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));


           return model;

 }
 bool reservation::supprimer(int cin)
 {
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    query.prepare("Delete from reservation where cin=:cin");
    query.bindValue(":cin",cin_string);
    return query.exec();
 }
 bool reservation::modifier()
 {
     QSqlQuery query;
     QString cin_string =QString::number(cin);
           query.prepare("update reservation set  nom='" +nom+"',prenom='"+prenom+ " ',num_salle='"+num_salle+"',type='"+type+"' where cin='"+cin_string+"'");
          query.bindValue(":cin", cin_string);
           query.bindValue(":nom",nom );
           query.bindValue(":prenom", prenom);
           query.bindValue(":num_salle", num_salle);
           query.bindValue(":type", type);
           return query.exec();
 }

 QSqlQueryModel* reservation:: trierreservation()
 {

     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from reservation order by nom ");

return model;
 }

 QSqlQueryModel * reservation ::recherche_reservation(QString search)
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     QString qry="select * from reservation where cin like '%"+search+"%' or nom like '%"+search+"%' or prenom like '%"+search+"%' or num_salle like '%"+search+"%'or type like '%"+search+"%' ";
     qDebug()<<qry;
     model->setQuery(qry);
     return model;
 }
int reservation::statistiquesreservation(QString num_salle)
 {
     QSqlQuery query;
         query.prepare("select count(*) from reservation where num_salle=:num_salle ");
         query.bindValue(":num_salle",num_salle);
         query.exec();
         query.next();
         return query.value(0).toInt();
 }
