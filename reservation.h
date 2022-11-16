#ifndef RESERVATION_H
#define RESERVATION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QDataStream>
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
    QSqlQueryModel* trierreservation();
    QSqlQueryModel* recherche_reservation(QString search);
    int statistiquesreservation(QString num_salle);


    private :
    int cin;
    QString nom,prenom,num_salle,type;
};



#endif // RESERVATION_H

