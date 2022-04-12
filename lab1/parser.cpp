#include "parser.h"
using namespace std;

string parser::vector_to_string(vector<int> vector){
    string str;
    for (auto item : vector){
        str += to_string(item) + " ";
    }
    return str;
}

vector<int> parser::string_to_vector(string str){
    vector<int> vect;
    char *char_str = new char [str.length()+1];
    strcpy(char_str, str.c_str());
    char *id = strtok(char_str, " ");
    while(id != NULL){
        vect.push_back(atoi(id));
        id = strtok(NULL, " ");
    }
    delete[] char_str;
    return vect;
}

user parser::query_to_user(QSqlQuery *query){
    string username = query->value(0).toString().toStdString();
    string password = query->value(1).toString().toStdString();
    string authority = query->value(2).toString().toStdString();
    string name = query->value(3).toString().toStdString();
    string passport = query->value(4).toString().toStdString();
    string phone = query->value(5).toString().toStdString();
    string email = query->value(6).toString().toStdString();
    int ID = query->value(7).toInt();
    string bank_accounts_id = query->value(8).toString().toStdString();
    vector<int> bank_accounts_ID = string_to_vector(bank_accounts_id);
    string deposits_id = query->value(9).toString().toStdString();
    vector<int> deposits_ID = string_to_vector(deposits_id);
    string credits_id = query->value(10).toString().toStdString();
    vector<int> credits_ID = string_to_vector(credits_id);
    user *us = new user(username, password, authority, name, passport, phone, email, ID, bank_accounts_ID, deposits_ID, credits_ID);
    return *us;
}

bank_account parser::query_to_bank_account(QSqlQuery *query){
    int money = query->value(1).toInt();
    int ID = query->value(0).toInt();
    int isFrozen = query->value(2).toInt();
    int isBlocked = query->value(3).toInt();
    bank_account *acc = new bank_account(money, ID, isFrozen, isBlocked);
    return *acc;
}

credit parser::query_to_credit(QSqlQuery *query){
    int money = query->value(1).toInt();
    int ID = query->value(0).toInt();
    int percent = query->value(2).toInt();
    int period = query->value(3).toInt();
    credit *cred = new credit(ID, money, percent, period);
    return *cred;
}

deposit parser::query_to_deposit(QSqlQuery *query){
    int money = query->value(1).toInt();
    int ID = query->value(0).toInt();
    int percent = query->value(2).toInt();
    deposit *dep = new deposit(ID, money, percent);
    return *dep;
}

company parser::query_to_company(QSqlQuery *query){
    string type = query->value(0).toString().toStdString();
    string legal_name = query->value(1).toString().toStdString();
    int PRN = query->value(2).toInt();
    long BIC = query->value(3).toLongLong();
    string legal_address = query->value(4).toString().toStdString();
    int ID = query->value(8).toInt();
    string bank_accounts_id = query->value(6).toString().toStdString();
    vector<int> bank_accounts_ID = string_to_vector(bank_accounts_id);
    string salary_projects_id = query->value(5).toString().toStdString();
    vector<int> salary_projects_ID = string_to_vector(salary_projects_id);
    string specialists_id = query->value(7).toString().toStdString();
    vector<int> specialists_ID = string_to_vector(specialists_id);
    company *com = new company(type, legal_name, PRN, BIC, legal_address, salary_projects_ID, bank_accounts_ID, specialists_ID, ID);
    return *com;
}

salary_project parser::query_to_salary_project(QSqlQuery *query){
    string users_id = query->value(1).toString().toStdString();
    vector<int> users_ID = string_to_vector(users_id);
    int ID = query->value(0).toInt();
    int company_bank_account_ID = query->value(2).toInt();
    int sum = query->value(3).toInt();
    salary_project *sp = new salary_project(company_bank_account_ID, sum, users_ID, ID);
    return *sp;
}

transfer parser::query_to_transfer(QSqlQuery *query){
    int payee_ID = query->value(1).toInt();
    int payer_ID = query->value(0).toInt();
    int sum = query->value(2).toInt();
    transfer *tr = new transfer(payer_ID, payee_ID, sum);
    return *tr;
}

sign_up_request parser::query_to_sign_up_request(QSqlQuery *query)
{
    string username = query->value(0).toString().toStdString();
    string password = query->value(1).toString().toStdString();
    string name = query->value(2).toString().toStdString();
    string passport = query->value(3).toString().toStdString();
    string phone = query->value(4).toString().toStdString();
    string email = query->value(5).toString().toStdString();
    sign_up_request *req = new sign_up_request(username, password, name, passport, phone, email);
    return *req;
}

credit_request parser::query_to_credit_request(QSqlQuery *query)
{
    int money = query->value(2).toInt();
    int user_ID = query->value(0).toInt();
    int bank_account_ID = query->value(1).toInt();
    int percent = query->value(3).toInt();
    int period = query->value(4).toInt();
    credit_request *req = new credit_request(user_ID, bank_account_ID, money, percent, period);
    return *req;
}

join_salary_project_request parser::query_to_join_salary_project_request(QSqlQuery *query)
{
    int user_ID = query->value(0).toInt();
    int salary_project_ID = query->value(1).toInt();
    join_salary_project_request *req = new join_salary_project_request(user_ID, salary_project_ID);
    return *req;
}

salary_project_request parser::query_to_salary_project_request(QSqlQuery *query)
{
    int company_ID = query->value(0).toInt();
    int company_bank_account_ID = query->value(1).toInt();
    int sum = query->value(2).toInt();
    salary_project_request *req = new salary_project_request(company_ID, company_bank_account_ID, sum);
    return *req;
}
