#include "ig_materiel.h"
#include "ui_mainwindow.h"
#include"materiel.h"
#include<QString>
#include<QIntValidator>
#include<QMessageBox>
#include<QRadioButton>
#include<QPainter>
#include<QTextDocument>
#include<QTextStream>
#include<QPdfWriter>
#include <QDataStream>
#include<QDesktopServices>
#include<QFontDatabase>
#include<QtCharts/QPieSeries>
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
//#include"dialog.h"
#include<QSettings>
#include <QDebug>
#include <QTimer>
#include<QDateTime>
#include"popup.h"
#include"popupp.h"
#include"arduino.h"
#include"integration.h"
using namespace QtCharts;

Ig_Materiel::Ig_Materiel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_mat->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_materiel->setModel(m.afficher());
    ui->le_mat_supp->setValidator(new QIntValidator(0,99999999,this));


    popUp = new PopUp();
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from materiel where etat=1 ");
        int x=model->rowCount();
        QSqlQuery query;
        query.prepare("select matricule from materiel where etat=1");
        query.exec();
    if(x!=0)
    {
        QString ch="";
        /*popUp->setPopupText("   \nhello   \n"
                        "   un equipement   \n"
                        "   est tombé en panne   \n");*/
        while(query.next())
        {
        ch=ch+"{"+query.value(0).toString()+"},";
        }
        ch=ch+"\nsont tombés en panne";
        popUp->setPopupText(ch);
        popUp->show();

     }
    else
     {
        popUp->setPopupText("   \nhello   \n"
                                "   aucune   \n"
                                "    panne   \n"
                            "   dans les équipement\n");

    }
popUp->show();

popUpp = new PopUpp();
QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select * from materiel where quantite>=5 ");
    int y=model1->rowCount();
    QSqlQuery query1;
    query1.prepare("select matricule from materiel where quantite>=5");
    query1.exec();
if(y!=0)
{
    QString ch="";
    while(query1.next())
    {
    ch=ch+'['+query1.value(0).toString()+"],";
    }
    ch=ch+"\nont un stock plein";
    popUpp->setPopupText(ch);
    popUpp->show();
 }
else
 {
    popUpp->setPopupText("   \nhello   \n"
                            "   aucune   \n"
                            "    panne   \n"
                        "   dans les équipement\n");
}
popUpp->show();


int ret=A.connect_arduino(); // lancer la connexion à arduino
switch(ret)
{
case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
    break;
case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
   break;
case(-1):qDebug() << "arduino is not available";
}
 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update())); // permet de lancer
 //le slot update_label suite à la reception du signal readyRead (reception des données).

}

Ig_Materiel::~Ig_Materiel()
{
    delete ui;
}


void Ig_Materiel::on_pb_ajouter_clicked()
{
    int mat=ui->le_mat->text().toInt();
    QString lib=ui->le_lib->text();
    QString marq=ui->le_marq->text();
    int qte=ui->le_qte->text().toInt();
    float prix=ui->le_prix->text().toFloat();

    int e;

    if(ui->rb_ok->isChecked())
    {e=0;}
    if(ui->rb_no->isChecked())
    {e=1;}

    Materiel m(mat,lib,marq,qte,prix,e);
    bool test=m.ajouter();
    int reponse = QMessageBox::question(this, "Ajouter Un Equipement Informatique", "Voulez-vous Ajouter L'équipement ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("ajout avec succes.");
        ui->tab_materiel->setModel(m.afficher());
        ui->le_mat->clear();
        ui->le_lib->clear();
        ui->le_marq->clear();
        ui->le_qte->clear();
        ui->le_prix->clear();
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from materiel where etat=1 ");
            int x=model->rowCount();
            QSqlQuery query;
            query.prepare("select matricule from materiel where etat=1");
            query.exec();
        if(x!=0)
        {
            QString ch="";
            /*popUp->setPopupText("   \nhello   \n"
                            "   un equipement   \n"
                            "   est tombé en panne   \n");*/
            while(query.next())
            {
            ch=ch+"{"+query.value(0).toString()+"},";
            }
            ch=ch+"\nsont tombés en panne";
            popUp->setPopupText(ch);
            popUp->show();

         }
        else
         {
            popUp->setPopupText("   \nhello   \n"
                                    "   aucune   \n"
                                    "    panne   \n"
                                "   dans les équipement\n");

        }


    popUp->show();

    }
    else
        msgBox.setText("echec d'ajout.");
    msgBox.exec();
    }
}



void Ig_Materiel::on_pb_supp_clicked()
{
    Materiel m1;
    m1.setMatricule(ui->le_mat_supp->text().toInt());
    bool test=m1.supprimer(m1.getMatricule());
    int reponse = QMessageBox::question(this, "Supprimer Un Equipement Informatique", "Voulez-vous Supprimer L'équipement ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("suppression avec succes.");
        ui->tab_materiel->setModel(m.afficher());
        ui->le_mat_supp->clear();
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from materiel where etat=1 ");
            int x=model->rowCount();
            QSqlQuery query;
            query.prepare("select matricule from materiel where etat=1");
            query.exec();
        if(x!=0)
        {
            QString ch="";
            /*popUp->setPopupText("   \nhello   \n"
                            "   un equipement   \n"
                            "   est tombé en panne   \n");*/
            while(query.next())
            {
            ch=ch+"{"+query.value(0).toString()+"},";
            }
            ch=ch+"\nsont tombés en panne";
            popUp->setPopupText(ch);
            popUp->show();

         }
        else
         {
            popUp->setPopupText("   \nhello   \n"
                                    "   aucune   \n"
                                    "    panne   \n"
                                "   dans les équipement\n");

        }


    popUp->show();

    }
    else
        msgBox.setText("echec de suppresion.");
    msgBox.exec();
    }
}

void Ig_Materiel::on_pb_modifier_clicked()
{
    int mat=ui->le_mat->text().toInt();
    QString lib=ui->le_lib->text();
    QString marq=ui->le_marq->text();
    int qte=ui->le_qte->text().toInt();
    float prix=ui->le_prix->text().toFloat();
    int e;

    if(ui->rb_ok->isChecked())
    {e=0;}
    if(ui->rb_no->isChecked())
    {e=1;}

    Materiel m(mat,lib,marq,qte,prix,e);

    bool test=m.modifier(mat);
    int reponse = QMessageBox::question(this, "Modifier Un Equipement Informatique", "Voulez-vous Modifier L'équipement ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("modification avec succes.");
        ui->tab_materiel->setModel(m.afficher());
        ui->le_mat->clear();
        ui->le_lib->clear();
        ui->le_marq->clear();
        ui->le_qte->clear();
        ui->le_prix->clear();
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from materiel where etat=1 ");
            int x=model->rowCount();
            QSqlQuery query;
            query.prepare("select matricule from materiel where etat=1");
            query.exec();
        if(x!=0)
        {
            QString ch="";
            /*popUp->setPopupText("   \nhello   \n"
                            "   un equipement   \n"
                            "   est tombé en panne   \n");*/
            while(query.next())
            {
            ch=ch+"{"+query.value(0).toString()+"},";
            }
            ch=ch+"\nsont tombés en panne";
            popUp->setPopupText(ch);
            popUp->show();

         }
        else
         {
            popUp->setPopupText("   \nhello   \n"
                                    "   aucune   \n"
                                    "    panne   \n"
                                "   dans les équipement\n");

        }


    popUp->show();

    }

    else
        msgBox.setText("echec de modification.");
    msgBox.exec();
    }
}





void Ig_Materiel::on_recherche_clicked()
{
    QString rech=ui->le_rech->text();
    ui->tab_materiel->setModel(m.recherche(rech));
}

void Ig_Materiel::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/user/OneDrive/Bureau/projet 2/gestion materiaux/file.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::red);
    QFontDatabase::addApplicationFont(":/../../Sangrita.ttf");
    painter.setFont(QFont("Sangrita", 30));
    painter.drawText(2500,1600,"Liste Des Matériaux");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(2000,900,5500,1000);
    painter.drawPixmap(QRect(70,70,1500,1500),QPixmap("C:/Users/user/OneDrive/Bureau/projet 2/logo app/1 (2).png"));
    painter.drawRect(10,3000,9000,550);
    painter.setFont(QFont("Arial", 12));
    painter.drawText(900,3300,"Matricule");
    painter.drawText(2233,3300,"Libéllé");
    painter.drawText(3566,3300,"Marque");
    painter.drawText(4899,3300,"Quantité");
    painter.drawText(6232,3300,"Prix");
    painter.drawText(7565,3300,"Etat");


    QSqlQuery query;
    query.prepare("select * from materiel");
    query.exec();
    int j=3700;
    while (query.next())
    {
        painter.drawRect(10,j,9000,4000);
        painter.drawText(900,i,query.value(0).toString());
        painter.drawText(2233,i,query.value(1).toString());
        painter.drawText(3566,i,query.value(2).toString());
        painter.drawText(5299,i,query.value(3).toString());
        painter.drawText(6232,i,query.value(4).toString());
        if(query.value(5).toString()=="0")
            painter.drawText(7565,i,"fonctionne");
        else
            painter.drawText(7565,i,"en panne");


        i = i +500;
        j+=500;
    }

    int reponse = QMessageBox::question(this, "PDF Enregistrer", "Voulez-vous Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/OneDrive/Bureau/projet 2/gestion materiaux/file.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}



void Ig_Materiel::on_pb_map_clicked()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/@36.8256448,9.9811924,9.92z/data=!4m2!11m1!3e4");

}

void Ig_Materiel::on_pb_stat_clicked()
{
 /*   QBarSet *set0=new QBarSet("En Panne");
    QBarSet *set1=new QBarSet("Fonctionnel");

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from materiel where etat=0 ");
        int etat0=model->rowCount();
        model->setQuery("select * from materiel where etat=1 ");
        int etat1=model->rowCount();
        int total=etat0+etat1;
        etat0=(etat0*100)/total;
        etat1=(etat1*100)/total;



    *set0<<etat0;
    *set1<<etat1;

    QBarSeries *series= new QBarSeries();

    series->append(set0);
    series->append(set1);


    QChart *chart= new QChart();
    chart->addSeries(series);
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitle("Pourcentage des états des équipements informatiques");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList cat_etats;
    cat_etats<<"En panne"<<"Fonctionnel";

    QBarCategoryAxis *axis= new QBarCategoryAxis();
    //axis->append(cat_etats);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QPalette pal=qApp->palette();
    pal.setColor(QPalette::Window,QRgb(0x601700));
    pal.setColor(QPalette::WindowText,QRgb(0x601700));
    qApp->setPalette(pal);

    QChartView *chartView= new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();


*/



    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from materiel where etat=0 ");
        float etat0=model->rowCount();
        model->setQuery("select * from materiel where etat=1 ");
        float etat1=model->rowCount();
        float total=etat0+etat1;
        QString a=QString("équipements fonctionnels "+QString::number((etat0*100)/total,'f',2)+"%" );
        QString b=QString("équipements en panne "+QString::number((etat1*100)/total,'f',2)+"%" );
        QPieSeries *series = new QPieSeries();
        series->append(a,etat0);
        series->append(b,etat1);
        if (etat0!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( etat1!=0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();
        chart->addSeries(series);

        QFont font;
        font.setPixelSize(20);
        chart->setTitleFont(font);
        chart->setTitle("Pourcentage Par Etat :Nombre des équipements "+ QString::number(total));
        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->hide();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();



}

void Ig_Materiel::on_pb_decr_clicked()
{
    if(ui->rb_mat->isChecked())
        ui->tab_materiel->setModel(m.tri_matricule_desc());
    if(ui->rb_lib->isChecked())
        ui->tab_materiel->setModel(m.tri_libelle_desc());
    if(ui->rb_marq->isChecked())
        ui->tab_materiel->setModel(m.tri_marque_desc());
}

void Ig_Materiel::on_pb_cr_clicked()
{
    if(ui->rb_mat->isChecked())
        ui->tab_materiel->setModel(m.tri_matricule());
    if(ui->rb_lib->isChecked())
        ui->tab_materiel->setModel(m.tri_libelle());
    if(ui->rb_marq->isChecked())
        ui->tab_materiel->setModel(m.tri_marque());

}

void Ig_Materiel::on_pb_notification_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from materiel where etat=1 ");
        int x=model->rowCount();
        QSqlQuery query;
        query.prepare("select matricule from materiel where etat=1");
        query.exec();
    if(x!=0)
    {
        QString ch="";
        /*popUp->setPopupText("   \nhello   \n"
                        "   un equipement   \n"
                        "   est tombé en panne   \n");*/
        while(query.next())
        {
        ch=ch+"{"+query.value(0).toString()+"},";
        }
        ch=ch+"\nsont tombés en panne";
        popUp->setPopupText(ch);
        popUp->show();

     }
    else
     {
        popUp->setPopupText("   \nhello   \n"
                                "   aucune   \n"
                                "    panne   \n"
                            "   dans les équipement\n");

    }


popUp->show();


popUp->show();

popUpp = new PopUpp();
QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select * from materiel where quantite>=10 ");
    int y=model1->rowCount();
    QSqlQuery query1;
    query1.prepare("select matricule from materiel where quantite>=5");
    query1.exec();
if(y!=0)
{
    QString ch="";
    while(query1.next())
    {
    ch=ch+'['+query1.value(0).toString()+"],";
    }
    ch=ch+"\nont un stock plein";
    popUpp->setPopupText(ch);
    popUpp->show();

 }
else
 {
    popUpp->setPopupText("   \nhello   \n"
                            "   aucune   \n"
                            "    panne   \n"
                        "   dans les équipement\n");

}


popUpp->show();


}


void Ig_Materiel::on_pb_refrech_clicked()
{
    ui->tab_materiel->setModel(m.afficher());
}


void Ig_Materiel::update()
{
    data=A.read_from_arduino();
    QMessageBox msgBox;
    QString ch=QString(data);


    QSqlQuery query;
            query.prepare("select * from materiel where matricule='"+ch+"'");

            QSqlQueryModel * model2= new QSqlQueryModel();
                model2->setQuery("select * from materiel where matricule    ='"+ch+"'");
                int z=0;
                        z=model2->rowCount();

             if(query.exec() and z>0)
             {
                 msgBox.setText("Accès au parking avec succès.");
                 A.write_to_arduino("1");
             }
             else if (z==0)
             {
                 msgBox.setText("Accès au parking impossible.");
                 A.write_to_arduino("0");
             }

    /*QSqlQueryModel * model2= new QSqlQueryModel();
        model2->setQuery("select * from materiel where etat='"+ch+"'");
        int z=model2->rowCount();

        if(z>0)
        {

            msgBox.setText("Accès au parking avec succès.");
            A.write_to_arduino("1");
        }
        else if (z==0)
        {
            msgBox.setText("Accès au parking impossible.");
            A.write_to_arduino("0");
        }*/

msgBox.exec();

}
