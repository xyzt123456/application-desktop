#include "employes.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


Employes::Employes()
{
     id=0;
     cin=0;
     noun="";
     adress="";
     occupation="";
     password="";
}
Employes::Employes(int id,int cin,QString noun,QString adress,QString occupation,QString password)
{
    this->id=id;
    this->cin=cin;
    this->noun=noun;
    this->adress=adress;
    this->occupation=occupation;
    this->password=password;


}
int Employes::getid(){return id;};
int Employes::getcin(){return cin;};
QString Employes::getnoun(){return noun;};
QString Employes::getadress(){return adress;};
QString Employes::getoccupation(){return occupation;};
QString Employes::getpassword(){return password;};
void Employes::setid(int id){ this->id=id;};
void Employes::setcin(int cin){this->cin=cin;};
void Employes::setnoun(QString noun){this->noun=noun;};
void Employes::setadress(QString adress){this->adress=adress;};
void Employes::setoccupation(QString occupation){this->occupation=occupation;};
void Employes::setpassword(QString password){this->password=password;};



bool Employes::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString cin_string= QString::number(cin);

         query.prepare("INSERT INTO Employe (id, cin, noun, adress,occupation,password) "
                       "VALUES (:id, :cin, :name, :adress, :occupation, :password)");
         query.bindValue(":id", id_string);
         query.bindValue(":cin", cin_string);
         query.bindValue(":name", noun);
         query.bindValue(":adress", adress);
         query.bindValue(":occupation", occupation);
         query.bindValue(":password", password);
         return query.exec();

}
bool Employes::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from employe where ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel* Employes::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM Employe");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("noun"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("adress"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("occupation"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("password"));


return model;

}
bool Employes::modifier(int id)
{
    QSqlQuery query;

       QString res= QString::number(id);
       query.prepare("UPDATE Employe SET id=:id, cin=:cin, noun=:noun, adress=:adress,occupation=:occupation,password=:password WHERE id=:id ");

       query.bindValue(":id", id);
       query.bindValue(":cin", cin);
       query.bindValue(":name", noun);
       query.bindValue(":adress", adress);
       query.bindValue(":occupation", occupation);
       query.bindValue(":password", password);





          return  query.exec();
}
QSqlQueryModel * Employes::recherche_employe(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from employe where id like '%"+search+"%' or cin like '%"+search+"%' or noun like '%"+search+"%' or adress like '%"+search+"%' or occupation like '%"+search+"%' or password like '%"+search+"%' ";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}
QSqlQueryModel * Employes::triID()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY id");
    return model;

}
QSqlQueryModel * Employes::triNOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY noun");
    return model;

}
int Employes::statistiquesemployes(QString occ)
{
    QSqlQuery query;
    query.prepare("select count(*) from employe where occupation=:occ ");
    query.bindValue(":occ",occ);
    query.exec();
    query.next();

    return query.value(0).toInt();

}

