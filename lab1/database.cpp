#include "database.h"
using namespace std;

database::database(string bank_name){
    QString database_name = QString::fromStdString("./" + bank_name + ".db");
    db = QSqlDatabase::addDatabase("QSQLITE", database_name);
    db.setDatabaseName(database_name);
    db.open();
    query = QSqlQuery(db);
    //query.exec("DROP TABLE salary_project_requests");
    //query.exec("DELETE FROM credit_requests");
    query.exec("CREATE TABLE users (username TEXT, password TEXT, authority TEXT, name TEXT, "
               "passport TEXT, phone TEXT, email TEXT, id INT, "
               "bank_accounts_id TEXT, deposits_id TEXT, credits_id TEXT);");
    query.exec("CREATE TABLE bank_accounts (id INT, money INT, isFrozen INT, isBlocked INT);");
    query.exec("CREATE TABLE credits (id INT, money INT, percent INT, period INT);");
    query.exec("CREATE TABLE deposits (id INT, money INT, percent INT);");
    query.exec("CREATE TABLE companies (type TEXT, legal_name TEXT, prn INT, bic BIGINT, "
               "legal_address TEXT, salary_projects_id TEXT, bank_accounts_id TEXT, "
               "specialists_id TEXT, id INT);");
    query.exec("CREATE TABLE salary_projects (id INT, users_id TEXT, "
               "company_bank_account_id INT, sum INT);");
    query.exec("CREATE TABLE transfers (payer_id INT, payee_id INT, sum INT);");
    query.exec("CREATE TABLE sign_up_requests (username TEXT, password TEXT, name TEXT, "
               "passport TEXT, phone TEXT, email TEXT);");
    query.exec("CREATE TABLE credit_requests (user_id INT, bank_account_id INT, money INT, "
               "percent INT, period INT);");
    query.exec("CREATE TABLE join_salary_project_requests (user_id INT, salary_project_id INT);");
    query.exec("CREATE TABLE salary_project_requests (company_id INT, company_bank_account_id INT, sum INT);");
}

void database::save(bank *bank){
    for (auto user : bank->getUsers()){
        query.prepare("INSERT INTO users VALUES (:username, :password, :authority, :name, :passport, :phone, "
                      ":email, :id, :bank_accounts_id, :deposits_id, :credits_id);");
        query.bindValue(":username", QString::fromStdString(user.getUsername()));
        query.bindValue(":password", QString::fromStdString(user.getPassword()));
        query.bindValue(":authority", QString::fromStdString(user.getAuthority()));
        query.bindValue(":name", QString::fromStdString(user.getName()));
        query.bindValue(":passport", QString::fromStdString(user.getPassport()));
        query.bindValue(":phone", QString::fromStdString(user.getPhone()));
        query.bindValue(":email", QString::fromStdString(user.getEmail()));
        query.bindValue(":id", QString::number(user.getID()));
        query.bindValue(":bank_accounts_id", QString::fromStdString(parser::vector_to_string(user.getBank_accounts_ID())));
        query.bindValue(":deposits_id", QString::fromStdString(parser::vector_to_string(user.getDeposits_ID())));
        query.bindValue(":credits_id", QString::fromStdString(parser::vector_to_string(user.getCredits_ID())));
        query.exec();
    }

    for (auto bank_account : bank->getBank_accounts()){
        query.prepare("INSERT INTO bank_accounts VALUES (:id, :money, :isFrozen, :isBlocked);");
        query.bindValue(":id", QString::number(bank_account.getID()));
        query.bindValue(":money", QString::number(bank_account.getMoney()));
        query.bindValue(":isFrozen", QString::number(bank_account.getIsFrozen()));
        query.bindValue(":isBlocked", QString::number(bank_account.getIsBlocked()));
        query.exec();
    }

    for (auto credit : bank->getCredits()){
        query.prepare("INSERT INTO credits VALUES (:id, :money, :percent, :period);");
        query.bindValue(":id", QString::number(credit.getID()));
        query.bindValue(":money", QString::number(credit.getMoney()));
        query.bindValue(":percent", QString::number(credit.getPercent()));
        query.bindValue(":period", QString::number(credit.getPeriod()));
        query.exec();
    }

    for (auto deposit : bank->getDeposits()){
        query.prepare("INSERT INTO deposits VALUES (:id, :money, :percent);");
        query.bindValue(":id", QString::number(deposit.getID()));
        query.bindValue(":money", QString::number(deposit.getMoney()));
        query.bindValue(":percent", QString::number(deposit.getPercent()));
        query.exec();
    }

    for (auto company : bank->getCompanies()){
        query.prepare("INSERT INTO companies VALUES (:type, :legal_name, :prn, :bic, :legal_address, "
                      ":salary_projects_id, :bank_accounts_id, :specialists_id, :id);");
        query.bindValue(":type", QString::fromStdString(company.getType()));
        query.bindValue(":legal_name", QString::fromStdString(company.getLegal_name()));
        query.bindValue(":prn", QString::number(company.getPRN()));
        query.bindValue(":bic", QString::number(company.getBIC()));
        query.bindValue(":legal_address", QString::fromStdString(company.getLegal_address()));
        query.bindValue(":bank_accounts_id", QString::fromStdString(parser::vector_to_string(company.getBank_accounts_ID())));
        query.bindValue(":salary_projects_id", QString::fromStdString(parser::vector_to_string(company.getSalary_projects_ID())));
        query.bindValue(":specialists_id", QString::fromStdString(parser::vector_to_string(company.getSpecialists_ID())));
        query.bindValue(":id", QString::number(company.getID()));
        query.exec();
    }

    for (auto salary_project : bank->getSalary_projects()){
        query.prepare("INSERT INTO salary_projects VALUES (:id, :users_id, :company_bank_account_id, :sum);");
        query.bindValue(":id", QString::number(salary_project.getID()));
        query.bindValue(":users_id", QString::fromStdString(parser::vector_to_string(salary_project.getUsers_ID())));
        query.bindValue(":company_bank_account_id", QString::number(salary_project.getCompany_bank_account_ID()));
        query.bindValue(":sum", QString::number(salary_project.getSum()));
        query.exec();
    }

    for (auto transfer : bank->getTransfers()){
        query.prepare("INSERT INTO transfers VALUES (:payer_id, :payee_id, :sum);");
        query.bindValue(":payer_id", QString::number(transfer.getPayer_ID()));
        query.bindValue(":payee_id", QString::number(transfer.getPayee_ID()));
        query.bindValue(":sum", QString::number(transfer.getSum()));
        query.exec();
    }

    for (auto request : bank->getSign_up_requests()){
        query.prepare("INSERT INTO sign_up_requests VALUES (:username, :password, :name, :passport, :phone, "
                      ":email);");
        query.bindValue(":username", QString::fromStdString(request.getUsername()));
        query.bindValue(":password", QString::fromStdString(request.getPassword()));
        query.bindValue(":name", QString::fromStdString(request.getName()));
        query.bindValue(":passport", QString::fromStdString(request.getPassport()));
        query.bindValue(":phone", QString::fromStdString(request.getPhone()));
        query.bindValue(":email", QString::fromStdString(request.getEmail()));
        query.exec();
    }

    for (auto request : bank->getCredit_requests()){
        query.prepare("INSERT INTO credit_requests VALUES (:user_id, :bank_account_id, :money, :percent, :period);");
        query.bindValue(":user_id", QString::number(request.getUser_ID()));
        query.bindValue(":bank_account_id", QString::number(request.getBank_account_ID()));
        query.bindValue(":money", QString::number(request.getMoney()));
        query.bindValue(":percent", QString::number(request.getPercent()));
        query.bindValue(":period", QString::number(request.getPeriod()));
        query.exec();
    }

    for (auto request : bank->getJoin_salary_project_requests()){
        query.prepare("INSERT INTO join_salary_project_requests VALUES (:user_id, :salary_project_id);");
        query.bindValue(":user_id", QString::number(request.getUser_ID()));
        query.bindValue(":salary_project_id", QString::number(request.getSalary_project_ID()));
        query.exec();
    }

    for (auto request : bank->getSalary_project_requests()){
        query.prepare("INSERT INTO salary_project_requests VALUES (:company_id, :company_bank_account_id, :sum);");
        query.bindValue(":company_id", QString::number(request.getCompany_ID()));
        query.bindValue(":company_bank_account_id", QString::number(request.getCompany_bank_account_ID()));
        query.bindValue(":sum", QString::number(request.getSum()));
        query.exec();
    }
}

void database::load(bank *bank){
    query.exec("SELECT * FROM sign_up_requests");
    vector<sign_up_request> sign_up_requests;
    while(query.next()){
        sign_up_requests.push_back(parser::query_to_sign_up_request(&query));
    }
    bank->setSign_up_requests(sign_up_requests);

    query.exec("SELECT * FROM credit_requests");
    vector<credit_request> credit_requests;
    while(query.next()){
        credit_requests.push_back(parser::query_to_credit_request(&query));
    }
    bank->setCredit_requests(credit_requests);

    query.exec("SELECT * FROM join_salary_project_requests");
    vector<join_salary_project_request> join_salary_project_requests;
    while(query.next()){
        join_salary_project_requests.push_back(parser::query_to_join_salary_project_request(&query));
    }
    bank->setJoin_salary_project_requests(join_salary_project_requests);

    query.exec("SELECT * FROM salary_project_requests");
    vector<salary_project_request> salary_project_requests;
    while(query.next()){
        salary_project_requests.push_back(parser::query_to_salary_project_request(&query));
    }
    bank->setSalary_project_requests(salary_project_requests);

    query.exec("SELECT * FROM users");
    vector<user> users;
    while(query.next()){
        users.push_back(parser::query_to_user(&query));
    }
    bank->setUsers(users);

    query.exec("SELECT * FROM bank_accounts");
    vector<bank_account> bank_accounts;
    while(query.next()){
        bank_accounts.push_back(parser::query_to_bank_account(&query));
    }
    bank->setBank_accounts(bank_accounts);

    query.exec("SELECT * FROM credits");
    vector<credit> credits;
    while(query.next()){
        credits.push_back(parser::query_to_credit(&query));
    }
    bank->setCredits(credits);

    query.exec("SELECT * FROM deposits");
    vector<deposit> deposits;
    while(query.next()){
        deposits.push_back(parser::query_to_deposit(&query));
    }
    bank->setDeposits(deposits);

    query.exec("SELECT * FROM companies");
    vector<company> companies;
    while(query.next()){
        companies.push_back(parser::query_to_company(&query));
    }
    bank->setCompanies(companies);

    query.exec("SELECT * FROM salary_projects");
    vector<salary_project> salary_projects;
    while(query.next()){
        salary_projects.push_back(parser::query_to_salary_project(&query));
    }
    bank->setSalary_projects(salary_projects);

    query.exec("SELECT * FROM transfers");
    vector<transfer> transfers;
    while(query.next()){
        transfers.push_back(parser::query_to_transfer(&query));
    }
    bank->setTransfers(transfers);
}

void database::view_db(string table){
    QSqlTableModel *model = new QSqlTableModel(nullptr, db);
    model->setTable(QString::fromStdString(table));
    model->select();
    view.setModel(model);
    view.show();
}

void database::delete_tables(){
    query.exec("DELETE FROM users");
    query.exec("DELETE FROM credits");
    query.exec("DELETE FROM deposits");
    query.exec("DELETE FROM bank_accounts");
    query.exec("DELETE FROM transfers");
    query.exec("DELETE FROM companies");
    query.exec("DELETE FROM salary_projects");
    query.exec("DELETE FROM sign_up_requests");
    query.exec("DELETE FROM credit_requests");
    query.exec("DELETE FROM join_salary_project_requests");
    query.exec("DELETE FROM salary_project_requests");
}
