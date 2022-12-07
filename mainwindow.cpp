#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salle.h"
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QMouseEvent>
//#include "camera.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
                switch(ret){
                case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id=ui->a1->text().toInt();
    int nb_table=ui->a2->text().toInt();
    QString type=ui->a3->currentText();
    QString nom=ui->a4->text();
    int nb_chaise=ui->a5->text().toInt();

    salle m (id,nb_table,type,nom,nb_chaise);
    bool test= m.ajouter();


         if(test)//si requête executée ==>QMessageBox::information
         {


             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
             A.write_to_arduino("1");

         }

         else { //si requête non exécutée ==>QMessageBox::critical
             QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                   QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
     ui->tableView->setModel(m.afficher());
     A.write_to_arduino("0");
}
}

void MainWindow::on_pushButton_2_clicked()
{
    int idaa =ui->a1->text().toInt();
                bool test = s.supprimer(idaa);
                if(test)
                {
                    //refresh affichage
                    ui->tableView->setModel(s.afficher());
                    //update_id();
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);
                    A.write_to_arduino("3");

                }
                else {
                    QMessageBox::critical(nullptr,QObject::tr("not ok"),

         QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
                A.write_to_arduino("0");
                }

}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
             QSqlQuery qry;
             qry.prepare("select * from salle where"
                         " id='"+val+"' or nb_table='"+val+"' or type='"+val+"' or nom='"+val+"' or nb_chaise='"+val+"' ");
             if(qry.exec())
               {while (qry.next())
              { ui->a1->setText(qry.value(0).toString());
                     ui->a2->setText(qry.value(1).toString());
                     ui->a4->setText(qry.value(2).toString());
                     ui->a3->setCurrentText(qry.value(2).toString());
                     ui->a5->setText(qry.value(4).toString());


               }
           }
}

void MainWindow::on_pushButton_3_clicked()
{
    //Récuprération des informations saisies dans les 3 champs
    int id=ui->a1->text().toInt();
    int nb_table=ui->a2->text().toInt();
    QString type=ui->a3->currentText();
    QString nom=ui->a4->text();
    int nb_chaise=ui->a5->text().toInt();





    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    salle k (id,nb_table,type,nom,nb_chaise);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =k.modifier();


      if(test)//si requête executée ==>QMessageBox::information
      {


          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView->setModel(s.afficher());
          A.write_to_arduino("2");

      }

      else {//si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
      A.write_to_arduino("0");

    }}



void MainWindow::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT id FROM salle");
       querry->exec();
       m->setQuery(*querry);

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(s.rechercherID(arg1));

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(s.AfficherTrieID());

}



void MainWindow::on_tabWidget_2_tabBarClicked(int index)
{
    qDeleteAll(ui->tabWidget_2->widget(0)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_4->setLayout(layout1);
}

void MainWindow::on_pushButton_5_clicked()
{
    salle c;

             QString text=c.apercu_pdf();
             ui->imp->setText(text);

             QPrinter printer ;
             printer.setPrinterName("imprim");
             QPrintDialog dialog (&printer,this);
             if(dialog.exec()==QDialog::Rejected) return ;
             ui->imp->print(&printer);

}

/*void MainWindow::on_camera_clicked()
{
    c= new camera();
    c->show();
}*/
