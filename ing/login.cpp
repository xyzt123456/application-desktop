#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include "employes.h"
#include "connection.h"


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_login_2_clicked()
{


    QString id = ui->nom->text();
        QString mdp = ui->mdp->text();
        QSqlQuery qry;
        if(qry.exec("select * from employe where ID='"+id+"' and password='"+mdp+"'"))
        {
            int count=0;
            while(qry.next())
            {
                count++;
            }
            if(count==1)
            {
              QMessageBox::information(this, "Login", "Username and password is correct");
                //hide();
                 ma = new integration(this);
                 ma->show();
            }

             else{
                         QMessageBox::warning(this,"Login", "Username and password is not correct");
            }

         }

}

