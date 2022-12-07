#ifndef MARKETING_H
#define MARKETING_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class marketing
{
private:
    int num_promo,pourcentage_promo;
    QString d_promo,f_promo;
public:
    marketing();
    marketing(int,int,QString,QString);
    QString getD_promo(){return d_promo;}
      QString getF_promo(){return f_promo;}

      int getNum_promo(){return num_promo;}

      int getPourcentage_promo(){return pourcentage_promo;}
      void setD_promo(QString d){d_promo=d;}
          void setF_promo(QString f){f_promo=f;}

          void setNum_promo(int num_prom){this->num_promo=num_prom;}
          void setPourcentage_promo(int p){pourcentage_promo=p;}
          bool ajouter();
              bool modifier();

              QSqlQueryModel * afficher();
              bool supprimer(int);
              QSqlQueryModel * AfficherTrieID();
              QSqlQueryModel * rechercherID(QString);
              QString  apercu_pdf();

};

#endif // MARKETING_H
