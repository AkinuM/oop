#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
using namespace std;

class user
{
private:
    string username;
    string password;
    string authority;
    string name;
    string passport;
    string phone;
    string email;
    static int count;
    int ID;
    vector<int> bank_accounts_ID;
    vector<int> deposits_ID;
    vector<int> credits_ID;

public:
    user();
    user(string username, string password, string authority);
    user(string username, string password, string authority, string name, string passport, string phone, string email);
    user(string username, string password, string authority, string name, string passport, string phone, string email, int ID, vector<int> bank_accounts_ID, vector<int> deposits_ID, vector<int> credits_ID);

    string getUsername() const;
    void setUsername(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
    string getAuthority() const;
    void setAuthority(const string &value);
    string getName() const;
    void setName(const string &value);
    string getPassport() const;
    void setPassport(const string &value);
    string getPhone() const;
    void setPhone(const string &value);
    string getEmail() const;
    void setEmail(const string &value);
    int getID() const;
    void setID(int value);
    vector<int> getBank_accounts_ID() const;
    void setBank_accounts_ID(const vector<int> &value);
    vector<int> getDeposits_ID() const;
    void setDeposits_ID(const vector<int> &value);
    vector<int> getCredits_ID() const;
    void setCredits_ID(const vector<int> &value);
};

#endif // USER_H
