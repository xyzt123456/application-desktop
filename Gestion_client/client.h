#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"QMessageBox"

class Client
{
public:
    Client();
    Client(int,int,QString,QString,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel *recherche_client (QString);
    QSqlQueryModel *tri_nom();

    int getCin();
    int getTel();
    QString getNom();
    QString getPrenom();
    QString getAdresse();
    QString getDate_naisc();
    QString getType();


    void setCin(int);
    void setTel(int);
    void setNom (QString);
    void setPrenom(QString);
    void setAdresse(QString);
    void setDate_naisc(QString);
    void setType(QString);


 private :
    int cin,tel;
    QString nom,prenom,adresse,date_naisc,type;
};

#endif // CLIENT_H
