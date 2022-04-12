#ifndef PARSER_H
#define PARSER_H
#include <cstring>
#include <cstdlib>
#include <QSqlQuery>
#include <QVariant>
#include "entities/bank.h"
using namespace std;


class parser
{
public:
    static string vector_to_string(vector<int> vector);
    static vector<int> string_to_vector(string str);
    static user query_to_user(QSqlQuery *query);
    static bank_account query_to_bank_account(QSqlQuery *query);
    static credit query_to_credit(QSqlQuery *query);
    static deposit query_to_deposit(QSqlQuery *query);
    static company query_to_company(QSqlQuery *query);
    static salary_project query_to_salary_project(QSqlQuery *query);
    static transfer query_to_transfer(QSqlQuery *query);
    static sign_up_request query_to_sign_up_request(QSqlQuery *query);
    static credit_request query_to_credit_request(QSqlQuery *query);
    static join_salary_project_request query_to_join_salary_project_request(QSqlQuery *query);
    static salary_project_request query_to_salary_project_request(QSqlQuery *query);
};

#endif // PARSER_H
