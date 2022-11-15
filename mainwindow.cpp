#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <employes.h>
#include <QIntValidator>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QtSql/QSqlQuery>
#include <QDate>

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>


#include "qrcode.h"
#include "qrwidget.h"
#include "qrgeneratorwork.h"
#include <fstream>
#include <string>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    QString noun=ui->le_nom->text();
    QString adress=ui->le_adresse->text();
    QString occupation=ui->le_occupation->text();
    QString password=ui->le_mdp->text();
    Employes E(id,cin,noun,adress,occupation,password);
        bool test=E.ajouter();
        if(test)
       {
            ui->tab_employe->setModel(E.afficher());
          QMessageBox::information(nullptr, QObject::tr("ok"),
          QObject::tr("ajout effectue.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);

       }
        else
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
         QObject::tr("ajout non effectue.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{
    int id =ui->le_id_sup->text().toInt();
       bool test=E.supprimer(id);
       if(test)
      {
           ui->tab_employe->setModel(E.afficher());
         QMessageBox::information(nullptr, QObject::tr("ok"),
         QObject::tr("suppression effectue.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_employe->setModel(E.afficher());
      }
       else
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
         QObject::tr("suppression non effectue.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->le_id_2->text().toInt();
            int cin= ui->le_cin_2->text().toInt();
             QString noun= ui->le_nom_2->text();
             QString adresse= ui->le_adresse_2->text();
             QString occupation= ui->le_occupation_2->text();
             QString password= ui->le_mdp_2->text();



           Employes E(id,cin,noun,adresse,occupation,password);
            bool test=E.modifier(id);
            if(test)
            {

                ui->tab_employe->setModel(E.afficher());//refresh
                       QMessageBox::information(nullptr, QObject::tr("effectué"),
                            QObject::tr(" Modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                       ui->le_id_2->clear();
                       ui->le_cin_2->clear();
                       ui->le_nom_2->clear();
                       ui->le_adresse_2->clear();
                       ui->le_occupation_2->clear();
                       ui->le_mdp_2->clear();

           }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                            QObject::tr("non modifié !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->le_id_2->clear();
                ui->le_cin_2->clear();
                ui->le_nom_2->clear();
                ui->le_adresse_2->clear();
                ui->le_occupation_2->clear();
                ui->le_mdp_2->clear();




            }
}


void MainWindow::on_recherche_2_clicked()
{
    Employes e;
    ui->tab_employe->setModel(e.recherche_employe(ui->recherche_2->text()));
}

void MainWindow::on_tri_id_clicked()
{
    Employes e;
    ui->tab_employe->setModel(e.triID());
}

void MainWindow::on_tri_noun_clicked()
{
    Employes e;
    ui->tab_employe->setModel(e.triNOM());
}


void MainWindow::on_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/Marwan/Desktop/Liste_Client.pdf");

   QPainter painter(&pdf);
   int i = 4100;

          QColor dateColor(0x4a5bcf);
          painter.setPen(dateColor);

          painter.setFont(QFont("Montserrat SemiBold", 11));
          QDate cd = QDate::currentDate();
          painter.drawText(8400,250,cd.toString("Tunis"));
          painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

          QColor titleColor(0x341763);
          painter.setPen(titleColor);
          painter.setFont(QFont("Montserrat SemiBold", 25));

          painter.drawText(3000,2700,"Liste des Employes");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 10));

          painter.drawText(500,3600,"cin");
          painter.drawText(2000,3600,"nom");
          painter.drawText(3300,3600,"Adresse");
          painter.drawText(4500,3600,"Occupation");
          painter.drawText(7500,3600,"Mot de passe");
          painter.setFont(QFont("Montserrat", 10));
          painter.drawRect(100,3300,9400,9000);


          QSqlQuery query;
          query.prepare("select * from employe");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=500;
              painter.drawText(500,i,query.value(1).toString());
              painter.drawText(2000,i,query.value(2).toString());
              painter.drawText(3300,i,query.value(3).toString());
              painter.drawText(4500,i,query.value(4).toString());
              painter.drawText(7500,i,query.value(5).toString());

             i = i + 500;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_statistique_clicked()
{
    Employes e;
    QBarSet *set0 = new QBarSet("Nombre des employes");

    *set0 << e.statistiquesemployes("directeur") << e.statistiquesemployes("femme de menage");


    QColor color(0x6568F3);
    set0->setColor(color);

    QBarSeries *series = new QBarSeries();
    series->append(set0);




    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre des employes");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundVisible(false);

    QColor bgColor(0xF4DCD3);
                   chart->setBackgroundBrush(QBrush(QColor(bgColor)));

                   chart->setBackgroundVisible(true);

    QStringList categories;
    categories << "directeur" << "femme de menage";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    QChartView *chartView = new QChartView(chart);

    chartView->setMinimumWidth(500);
    chartView->setMinimumHeight(300);
    chartView->setParent(ui->stat);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartView->show();

}


void MainWindow::on_qr_clicked()
{
    if(ui->tab_employe->currentIndex().row()==-1)
                                   QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                                            QObject::tr("Veuillez Choisir un employe du Tableau.\n"
                                                                        "Click Ok to exit."), QMessageBox::Ok);
                               else
                               {
                                    int  id=ui->tab_employe->model()->data(ui->tab_employe->model()->index(ui->tab_employe->currentIndex().row(),0)).toInt();
                                    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(id).c_str(), qrcodegen::QrCode::Ecc::LOW);

                                    std::ofstream myfile;
                                    myfile.open ("qrcode.svg") ;
                                       myfile << qr.toSvgString(2);
                                       myfile.close();
                                       QSvgRenderer svgRenderer(QString("qrcode.svg"));
                                       QPixmap pix( QSize(90, 90));
                                       QPainter pixPainter( &pix );
                                       svgRenderer.render(&pixPainter);
                                    ui->qrcode->setPixmap(pix);
                               }
}
