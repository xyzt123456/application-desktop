#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"QMessageBox"
#include <QFrame>
#include<QFileDialog>



class Client
{
public:
    Client();
    Client(int,QString,QString,QString,int,QString,int,QString,QString,int);

    //CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer(int);

    //métiers
    QSqlQueryModel *recherche_client (QString);
    QSqlQueryModel *tri_nom();
    QSqlQueryModel * exporterpdf();
    QSqlQueryModel *client_fidele();


    //getters
    int getCin();
    QString getNom();
    QString getPrenom();
    QString getDate_naisc();
    int getTel();
    QString getType();
    int getNbr();
    QString getAdresse();
    QString getDate_de_res();
    int getCode();



    //setters
    void setCin(int);
    void setNom (QString);
    void setPrenom(QString);
    void setDate_naisc(QString);
    void setTel(int);
    void setType(QString);
    void setNbr(int);
    void setAdresse(QString);
    void setDate_de_res(QString);
    void setCode(int);


 private :
    int cin,tel,nbr,code;
    QString nom,prenom,date_naisc,type,adresse,date_de_res;
};

#endif // CLIENT_H
