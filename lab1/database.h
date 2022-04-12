#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlError>
#include "entities/bank.h"
#include "parser.h"
using namespace std;

class database
{
public:
    QSqlDatabase db;
    QSqlQuery query;
    QTableView view;

    database(string bank_name);
    void create_tables();
    void save(bank *bank);
    void load(bank *bank);
    void view_db(string table);
    void delete_tables();
};

#endif // DATABASE_H
