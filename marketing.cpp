#include "marketing.h"
#include<QSqlQuery>
#include<QtDebug>
marketing::marketing()
{
    num_promo=0;
    pourcentage_promo=0;
       d_promo="";
       f_promo="";
}
marketing::marketing(int num_promo,int pourcentage_promo,QString d_promo,QString f_promo)
{

    this->num_promo=num_promo;
   this->pourcentage_promo=pourcentage_promo;
    this->d_promo=d_promo;
    this->f_promo=f_promo;


}
bool marketing::ajouter()
{
    QSqlQuery query;
    QString res1 = QString::number(num_promo);
    QString res2 = QString::number(pourcentage_promo);



    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Marketing(num_promo,pourcentage_promo,d_promo,f_promo)""values( :num_promo, :pourcentage_promo, :d_promo, :f_promo)");

    //Création des variables liées
    query.bindValue(":num_promo",num_promo);
    query.bindValue(":pourcentage_promo",pourcentage_promo);
    query.bindValue(":d_promo",d_promo);
    query.bindValue(":f_promo",f_promo);


    return query.exec();//exec() envoie la requête pour l'exécution





}
bool marketing::modifier()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res1 = QString::number(num_promo);
    QString res2 = QString::number(pourcentage_promo);

    query1.prepare("SELECT num_promo FROM Marketing WHERE num_promo=:idA");
    query1.bindValue(":idA",res1);
    query1.exec();
    while(query1.next())
    {
        b++;
    }

    if (b!=0)
    {
    query.prepare("UPDATE Marketing set num_promo = :num_promo, pourcentage_promo = :pourcentage_promo,d_promo = :d_promo,f_promo=:f_promo WHERE num_promo=:num_promo");
    query.bindValue(":num_promo",res1);
    query.bindValue(":pourcentage_promo",res2);
    query.bindValue(":d_promo",d_promo);
    query.bindValue(":f_promo",f_promo);


    return query.exec();//exec() envoie la requête pour l'exécution
}
    else
    {
        return false;
    }
}





QSqlQueryModel * marketing ::afficher()
{


QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Marketing");
return model;

}




bool marketing::supprimer(int idA)
{

               QSqlQuery query;
               QSqlQuery query1;
               int b=0;
               QString res=QString::number(idA);

               query1.prepare("SELECT num_promo FROM Marketing WHERE num_promo=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {


               query.prepare("Delete from Marketing where num_promo=:idA");
               query.bindValue(":idA",res);
               return query.exec(); }

               else
               {
                   return false;
               }
    }
QSqlQueryModel * marketing::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Marketing ORDER BY num_promo");

    return model;
}




QSqlQueryModel * marketing::rechercherID(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Marketing where num_promo like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}
QString marketing:: apercu_pdf()
 {
    QString text="          ****** marketing  ******      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a;


      query.exec("select * from Marketing  ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();

        text += "\n num_promo  : "+i+"\n\n - pourcentage_promo : "+ x+"\n - d_promo : "+ z+"\n - f_promo:"+a+"\n"  ;


     }

             return text ;
 }




