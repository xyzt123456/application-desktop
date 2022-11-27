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
    Client(int,int,int,QString,QString,QString,QString,QString);

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
    QString getNom();
    QString getPrenom();
    QString getDate_naisc();
    QString getType();
    QString getAdresse();



    //setters
    void setCin(int);
    void setTel(int);
    void setNbr(int);
    void setNom (QString);
    void setPrenom(QString);
    void setDate_naisc(QString);
    void setType(QString);
    void setAdresse(QString);


 private :
    int cin,tel,nbr;
    QString nom,prenom,date_naisc,type,adresse;
};

#endif // CLIENT_H
