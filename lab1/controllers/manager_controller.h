#ifndef MANAGER_CONTROLLER_H
#define MANAGER_CONTROLLER_H
#include "entities/bank.h"
#include "user_controller.h"
#include "specialist_controller.h"


class manager_controller
{
public:
    static void approve_sign_up(bank *bank, string passport);
    static void approve_credit(bank *bank, int row_number);
    static void approve_join_salary_project(bank *bank, int user_ID, int salary_project_ID);
    static void approve_salary_project(bank *bank, int row_number);
};

#endif // MANAGER_CONTROLLER_H
