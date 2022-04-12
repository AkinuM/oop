#include "join_salary_project_request.h"

int join_salary_project_request::getUser_ID() const
{
    return user_ID;
}

void join_salary_project_request::setUser_ID(int value)
{
    user_ID = value;
}

int join_salary_project_request::getSalary_project_ID() const
{
    return salary_project_ID;
}

void join_salary_project_request::setSalary_project_ID(int value)
{
    salary_project_ID = value;
}

join_salary_project_request::join_salary_project_request(int user_ID, int salary_project_ID)
{
    this->user_ID = user_ID;
    this->salary_project_ID = salary_project_ID;
}
