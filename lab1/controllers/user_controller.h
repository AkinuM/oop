#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H
#pragma once
#include "entities/bank.h"


class user_controller
{
public:
    static void open_bank_account(bank *bank, int ID, int money);
    static void top_up_bank_account(bank *bank, int bank_account_ID, int money);
    static void withdrawal_bank_account(bank *bank, int bank_account_ID, int money);
    static void transfer_bank_account(bank *bank, int payer_ID, int payee_ID, int money);
    static void open_deposit(bank *bank, int ID, int percent, int money);
    static void top_up_deposit(bank *bank, int deposit_ID, int money);
    static void withdrawal_deposit(bank *bank, int deposit_ID, int money);
    static void freeze_bank_account(bank *bank, int bank_account_ID);
    static void unfreeze_bank_account(bank *bank,int bank_account_ID);
    static void block_bank_account(bank *bank, int bank_account_ID);
    static void take_credit(bank *bank, int user_ID, int bank_account_ID, credit *new_credit);
    static void join_salary_project(bank *bank, int user_ID, int salary_project_ID);
};

#endif // USER_CONTROLLER_H
