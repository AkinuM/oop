#ifndef JOIN_SALARY_PROJECT_REQUEST_H
#define JOIN_SALARY_PROJECT_REQUEST_H


class join_salary_project_request
{
private:
    int user_ID;
    int salary_project_ID;

public:
    join_salary_project_request(int user_ID, int salary_project_ID);
    int getUser_ID() const;
    void setUser_ID(int value);
    int getSalary_project_ID() const;
    void setSalary_project_ID(int value);
};

#endif // JOIN_SALARY_PROJECT_REQUEST_H
