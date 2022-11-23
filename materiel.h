#ifndef MATERIEL_H
#define MATERIEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Materiel
{
private:
    int matricule;
    QString libelle,marque;
    int qte;
    float prix;
    int etat;
public:
    //constructeurs
    Materiel();
    Materiel(int,QString,QString,int,float,int);
    //getters
    int getMatricule(){return matricule;}
    QString getLibelle(){return libelle;}
    QString getMarque(){return marque;}
    int getQte(){return qte;}
    float getPrix(){return prix;}
    int getEtat(){return etat;}
    //setters
    void setMatricule(int val){matricule=val;}
    void setMarque(QString val){marque=val;}
    void setLibelle(QString val){libelle=val;}
    void setQte(int val){qte=val;}
    void setPrix(float val){prix=val;}
    void setEtat(int val){etat=val;}

    //fonctions CDUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * tri_libelle();
    QSqlQueryModel * tri_marque();
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel * tri_libelle_desc();
    QSqlQueryModel * tri_marque_desc();
    QSqlQueryModel * tri_matricule_desc();
    QSqlQueryModel * tri_matricule();
};

#endif // MATERIEL_H
