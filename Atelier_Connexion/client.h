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
    Client(int,int,QString,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer(int);

    int getCin();
    int getTel();
    QString getNom();
    QString getPrenom();
    QString getAdresse();
    QString getDate_naisc();

    void setCin(int);
    void setTel(int);
    void setNom (QString);
    void setPrenom(QString);
    void setAdresse(QString);
    void setDate_naisc(QString);

 private :
    int cin,tel;
    QString nom,prenom,adresse,date_naisc;
};

#endif // CLIENT_H
