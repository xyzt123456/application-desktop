#ifndef RESERVATION_H
#define RESERVATION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include"QMessageBox"
class reservation
{
public:
    reservation();
    reservation(int,QString,QString,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getnum_salle();
    QString gettype();

    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setnum_salle(QString);
    void settype(QString);

    bool ajouter();
    bool supprimer(int cin);
    QSqlQueryModel* afficher();
    bool modifier();

    private :
    int cin;
    QString nom,prenom,num_salle,type;
};

#endif // RESERVATION_H

