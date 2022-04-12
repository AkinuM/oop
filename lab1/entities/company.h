#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <vector>
using namespace std;

class company
{
private:
    int ID;
    static int count;
    string type;
    string legal_name;
    int PRN;
    long BIC;
    string legal_address;
    vector<int> salary_projects_ID;
    vector<int> bank_accounts_ID;
    vector<int> specialists_ID;

public:
    company(string type, string legal_name, int PRN, long BIC, string legal_address);
    company(string type, string legal_name, int PRN, long BIC, string legal_address, vector<int> salary_projects_ID, vector<int> bank_accounts_ID, vector<int> specialists_ID, int ID);

    int getID() const;
    void setID(int value);
    string getType() const;
    void setType(const string &value);
    string getLegal_name() const;
    void setLegal_name(const string &value);
    int getPRN() const;
    void setPRN(int value);
    long getBIC() const;
    void setBIC(long value);
    string getLegal_address() const;
    void setLegal_address(const string &value);
    vector<int> getSalary_projects_ID() const;
    void setSalary_projects_ID(const vector<int> &value);
    vector<int> getBank_accounts_ID() const;
    void setBank_accounts_ID(const vector<int> &value);
    vector<int> getSpecialists_ID() const;
    void setSpecialists_ID(const vector<int> &value);
};



#endif // COMPANY_H
