#ifndef SPECIALIST_CONTROLLER_H
#define SPECIALIST_CONTROLLER_H
#include "database.h"
using namespace std;

class specialist_controller
{
public:
    static void open_salary_project(bank *bank, int company_ID, salary_project *new_salary_project);
};

#endif // SPECIALIST_CONTROLLER_H
