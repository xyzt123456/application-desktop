#include "salle.h"
#include<QSqlQuery>
#include<QtDebug>
salle::salle()
{
    //initialisation
    id=0;
    nb_table=0;
    nb_chaise=0;

       nom="";
       type="";
}
salle::salle(int id,int nb_table,QString type,QString nom,int nb_chaise)
{
    //Appel
    this->id=id;
   this->nb_table=nb_table;
    this->type=type;
    this->nom=nom;
    this->nb_chaise=nb_chaise;



}
bool salle::ajouter()
{
    //initialisation int to string
    QSqlQuery query;
    QString res1 = QString::number(id);
    QString res2 = QString::number(nb_table);
    QString res3 = QString::number(nb_chaise);



    //insertion :prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into salle(id,nb_table,type,nom,nb_chaise)""values( :id, :nb_table, :type, :nom, :nb_chaise)");

    //Création des variables liées
    query.bindValue(":id",res1);
    query.bindValue(":nb_table",res2);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);
    query.bindValue(":nb_chaise",res3);


    return query.exec();//exec() envoie la requête pour l'exécution





}
bool salle::modifier()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res1 = QString::number(id);
    QString res2 = QString::number(nb_table);
    QString res3 = QString::number(nb_chaise);

    query1.prepare("SELECT id FROM salle WHERE id=:idA");
    query1.bindValue(":idA",res1);
    query1.exec();
    while(query1.next())
    {
        b++;
    }

    //mis a jour et envoyer a la base
    if (b!=0)
    {
    query.prepare("UPDATE salle set id=:id,nb_table=:nb_table,type=:type,nom=:nom,nb_chaise=:nb_chaise WHERE id=:id");
    query.bindValue(":id",res1);
    query.bindValue(":nb_table",res2);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);
    query.bindValue(":nb_chaise",res3);

    return query.exec();//exec() envoie la requête pour l'exécution
}
    else
    {
        return false;
    }
}





QSqlQueryModel * salle ::afficher()
{

    //Affichage des donnee de la base

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from salle");
return model;

}




bool salle::supprimer(int idA)
{
    //si le id est le meme tout les information vont etre supprimer
               QSqlQuery query;
               QSqlQuery query1;
               int b=0;
               QString res=QString::number(idA);

               query1.prepare("SELECT id FROM salle WHERE id=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {


               query.prepare("Delete from salle where id=:idA");
               query.bindValue(":idA",res);
               return query.exec(); }

               else
               {
                   return false;
               }
    }

QSqlQueryModel * salle::AfficherTrieID()
{
    //tri par ordre croissant de l'id
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM salle ORDER BY id");

    return model;
}




QSqlQueryModel * salle::rechercherID(QString id)
{
    //upload les information de l'id inseree dans la recherche
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from salle where id like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}
QString salle:: apercu_pdf()
 {
    QString text="          ****** salles  ******      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,b;  //chaque variable va prendre un champs


     //afficage sous forme de pdf
     query.exec("select * from salle  ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();
         b=query.value(4).toString();
        text += "\n -id  : "+i+"\n - nb_table : "+ x+"\n - type : "+ z+"\n - nom:"+a+"\n - nb_chaise:"+b+"\n"  ;


     }

             return text ;
 }




