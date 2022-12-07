#ifndef SALLE_H
#define SALLE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMouseEvent>

class salle
{
private:
    int id,nb_table,nb_chaise;
    QString nom,type;
public:
    salle();
    salle(int,int,QString,QString,int);
    QString getnom(){return nom;}
      QString gettype(){return type;}

      int getid(){return id;}

      int getnb_table(){return nb_table;}
      int getnb_chaise(){return nb_chaise;}

      void setnom(QString d){nom=d;}
          void settype(QString f){type=f;}

          void setid(int id){this->id=id;}
          void setnb_table(int p){nb_table=p;}
          void setnb_chaise(int n){nb_chaise=n;}

          bool ajouter();
              bool modifier();

              QSqlQueryModel * afficher();
              bool supprimer(int);
              QSqlQueryModel * AfficherTrieID();
              QSqlQueryModel * rechercherID(QString);
              QString  apercu_pdf();

};

#endif // SALLE_H
