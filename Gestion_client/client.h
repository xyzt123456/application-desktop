#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"QMessageBox"
#include <QFrame>
#include<QFileDialog>

/*#include<QtCharts/QPieSeries>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSlice>
#include<QtCharts/QChart>
#include<QtCharts/QChartView>
#include<QtCharts/QPieSlice>
#include <Charts>
*/
class Client
{
public:
    Client();
    Client(int,int,int,int,QString,QString,QString,QString,QString,QString);

    //CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer(int);

    //métiers
    QSqlQueryModel *recherche_client (QString);
    QSqlQueryModel *tri_nom();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    QSqlQueryModel * exporterpdf();
    QSqlQueryModel *client_fidele();


    //getters
    int getCin();
    int getTel();
    int getNbr();
    int getCode();
    QString getNom();
    QString getPrenom();
    QString getDate_naisc();
    QString getType();
    QString getAdresse();
    QString getDate_de_res();



    //setters
    void setCin(int);
    void setTel(int);
    void setNbr(int);
    void setCode(int);
    void setNom (QString);
    void setPrenom(QString);
    void setDate_naisc(QString);
    void setType(QString);
    void setAdresse(QString);
    void setDate_de_res(QString);

 private :
    int cin,tel,nbr,code;
    QString nom,prenom,date_naisc,type,adresse,date_de_res;
};

#endif // CLIENT_H
