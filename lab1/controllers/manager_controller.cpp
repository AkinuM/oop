#include "manager_controller.h"

void manager_controller::approve_sign_up(bank *bank, string passport)
{
    vector<user> users = bank->getUsers();
    vector<sign_up_request> sign_up_requests = bank->getSign_up_requests();
    for(auto iter = sign_up_requests.begin(); iter != sign_up_requests.end(); iter++){
        if(iter->getPassport() == passport){
            users.push_back(*(new user(iter->getUsername(), iter->getPassword(), "Operator", iter->getName(), passport, iter->getPhone(), iter->getEmail())));
            sign_up_requests.erase(iter);
            break;
        }
    }
    bank->setUsers(users);
    bank->setSign_up_requests(sign_up_requests);
}

void manager_controller::approve_credit(bank *bank, int row_number)
{
    vector<credit_request> credit_requests = bank->getCredit_requests();
    user_controller::take_credit(bank, credit_requests[row_number - 1].getUser_ID(), credit_requests[row_number - 1].getBank_account_ID(), new credit(credit_requests[row_number - 1].getMoney(), credit_requests[row_number - 1].getPercent(), credit_requests[row_number - 1].getPeriod()));
    auto iter = credit_requests.begin();
    for (int i = 0; i < row_number - 1; i++){
        iter++;
    }
    credit_requests.erase(iter);
    bank->setCredit_requests(credit_requests);
}

void manager_controller::approve_join_salary_project(bank *bank, int user_ID, int salary_project_ID)
{
    vector<join_salary_project_request> join_salary_project_requests = bank->getJoin_salary_project_requests();
    for(auto iter = join_salary_project_requests.begin(); iter != join_salary_project_requests.end(); iter++){
        if(user_ID == iter->getUser_ID() && salary_project_ID == iter->getSalary_project_ID()){
            user_controller::join_salary_project(bank, user_ID, salary_project_ID);
            join_salary_project_requests.erase(iter);
            break;
        }
    }
    bank->setJoin_salary_project_requests(join_salary_project_requests);
}

void manager_controller::approve_salary_project(bank *bank, int row_number)
{
    vector<salary_project_request> salary_project_requests = bank->getSalary_project_requests();
    specialist_controller::open_salary_project(bank, salary_project_requests[row_number - 1].getCompany_ID(), new salary_project(salary_project_requests[row_number - 1].getCompany_bank_account_ID(), salary_project_requests[row_number - 1].getSum()));
    auto iter = salary_project_requests.begin();
    for (int i = 0; i < row_number - 1; i++){
        iter++;
    }
    salary_project_requests.erase(iter);
    bank->setSalary_project_requests(salary_project_requests);
}
