#include "specialist_controller.h"
using namespace std;

void specialist_controller::open_salary_project(bank *bank, int company_ID, salary_project *new_salary_project)
{
    vector<salary_project> salary_projects = bank->getSalary_projects();
    salary_projects.push_back(*new_salary_project);
    bank->setSalary_projects(salary_projects);
    vector<company> companies = bank->getCompanies();
    for (int i = 0; i < companies.size(); i++){
        if(company_ID == companies[i].getID()){
            vector<int> salary_projects_ID = companies[i].getSalary_projects_ID();
            salary_projects_ID.push_back(salary_projects.back().getID());
            companies[i].setSalary_projects_ID(salary_projects_ID);
            break;
        }
    }
    bank->setCompanies(companies);
}
