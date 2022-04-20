#include "company.h"

int company::count = 0;

int company::getID() const
{
    return ID;
}

void company::setID(int value)
{
    ID = value;
}

string company::getType() const
{
    return type;
}

void company::setType(const string &value)
{
    type = value;
}

string company::getLegal_name() const
{
    return legal_name;
}

void company::setLegal_name(const string &value)
{
    legal_name = value;
}

int company::getPRN() const
{
    return PRN;
}

void company::setPRN(int value)
{
    PRN = value;
}

long company::getBIC() const
{
    return BIC;
}

void company::setBIC(long value)
{
    BIC = value;
}

string company::getLegal_address() const
{
    return legal_address;
}

void company::setLegal_address(const string &value)
{
    legal_address = value;
}

vector<int> company::getSalary_projects_ID() const
{
    return salary_projects_ID;
}

void company::setSalary_projects_ID(const vector<int> &value)
{
    salary_projects_ID = value;
}

vector<int> company::getBank_accounts_ID() const
{
    return bank_accounts_ID;
}

void company::setBank_accounts_ID(const vector<int> &value)
{
    bank_accounts_ID = value;
}

vector<int> company::getSpecialists_ID() const
{
    return specialists_ID;
}

void company::setSpecialists_ID(const vector<int> &value)
{
    specialists_ID = value;
}

company::company(string type, string legal_name, int PRN, long BIC, string legal_address) {
    this->type = type;
    this->legal_name = legal_name;
    this->PRN = PRN;
    this->BIC = BIC;
    this->legal_address = legal_address;
    ID = ++count;
}

company::company(string type, string legal_name, int PRN, long BIC, string legal_address, vector<int> salary_projects_ID, vector<int> bank_accounts_ID, vector<int> specialists_ID, int ID) {
    this->type = type;
    this->legal_name = legal_name;
    this->PRN = PRN;
    this->BIC = BIC;
    this->legal_address = legal_address;
    this->ID = ID;
    this->specialists_ID = specialists_ID;
    this->bank_accounts_ID = bank_accounts_ID;
    this->salary_projects_ID = salary_projects_ID;
    if(count < ID){
        this->count = ID;
    }
}
