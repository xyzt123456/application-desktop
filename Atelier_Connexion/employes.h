#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>


class Employes
{
public:
    Employes();
    Employes(int,int,QString,QString,QString,QString);
    int getid();
    int getcin();
    QString getnoun();
    QString getadress();
    QString getoccupation();
    QString getpassword();
    void setid(int);
    void setcin(int);
    void setnoun(QString);
    void setadress(QString);
    void setoccupation(QString);
    void setpassword(QString);
    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel* afficher();


private:
    int id;
    int cin;
    QString noun;
    QString adress;
    QString occupation;
    QString password;

};

#endif // EMPLOYES_H
