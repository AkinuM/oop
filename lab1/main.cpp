#include "interface/mainwindow.h"
#include "database.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bank bank1("bank1");
    bank bank2("bank2");
    bank bank3("bank3");
    database *db1 = new database(bank1.getName());
    database *db2 = new database(bank2.getName());
    database *db3 = new database(bank3.getName());
    db1->load(&bank1);
    db2->load(&bank2);
    db3->load(&bank3);
//    company *company1 = new company("comp1", "comp1", 1, 1, "comp1");
//    vector<int> vec = {5};
//    company1->setSpecialists_ID(vec);
//    vector<company> comp = {*company1};
//    user *us = new user("manager", "manager", "Manager");
//    vector<user> users = {*us};
//    bank3.setUsers(users);
  //  bank2.setCompanies(comp);
    //db3->view_db("users");
 //   db2->view_db("users");
//    db1->view_db("users");
//    db1->view_db("credits");
//    db2->view_db("credits");
//    db1->view_db("deposits");
//    db2->view_db("deposits");
//    db1->view_db("bank_accounts");
//    db2->view_db("bank_accounts");
//    db1->view_db("transfers");
//    b2->view_db("transfers");
//    db1->view_db("salary_projects");
    db2->view_db("salary_projects");
//    db1->view_db("companies");
 //   db2->view_db("companies");
   // db2->view_db("salary_project_requests");
    MainWindow w(&bank1, &bank2, &bank3);
    w.show();
    a.exec();
    db1->delete_tables();
    db2->delete_tables();
    db3->delete_tables();
    db1->save(&bank1);
    db2->save(&bank2);
    db3->save(&bank3);
    return 1;
}
