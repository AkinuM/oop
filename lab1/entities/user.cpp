#include "user.h"

int user::count = 0;

string user::getUsername() const
{
    return username;
}

void user::setUsername(const string &value)
{
    username = value;
}

string user::getPassword() const
{
    return password;
}

void user::setPassword(const string &value)
{
    password = value;
}

string user::getAuthority() const
{
    return authority;
}

void user::setAuthority(const string &value)
{
    authority = value;
}

string user::getName() const
{
    return name;
}

void user::setName(const string &value)
{
    name = value;
}

string user::getPassport() const
{
    return passport;
}

void user::setPassport(const string &value)
{
    passport = value;
}

string user::getPhone() const
{
    return phone;
}

void user::setPhone(const string &value)
{
    phone = value;
}

string user::getEmail() const
{
    return email;
}

void user::setEmail(const string &value)
{
    email = value;
}

int user::getID() const
{
    return ID;
}

void user::setID(int value)
{
    ID = value;
}

vector<int> user::getBank_accounts_ID() const
{
    return bank_accounts_ID;
}

void user::setBank_accounts_ID(const vector<int> &value)
{
    bank_accounts_ID = value;
}

vector<int> user::getDeposits_ID() const
{
    return deposits_ID;
}

void user::setDeposits_ID(const vector<int> &value)
{
    deposits_ID = value;
}

vector<int> user::getCredits_ID() const
{
    return credits_ID;
}

void user::setCredits_ID(const vector<int> &value)
{
    credits_ID = value;
}

user::user(string username, string password, string authority) {
    this->username = username;
    this->password = password;
    this->authority = authority;
    ID = ++count;
}

user::user(string username, string password, string authority, string name, string passport, string phone, string email) {
    this->username = username;
    this->password = password;
    this->authority = authority;
    this->name = name;
    this->passport = passport;
    this->phone = phone;
    this->email = email;
    ID = ++count;

}

user::user(string username, string password, string authority, string name, string passport, string phone, string email, int ID, vector<int> bank_accounts_ID, vector<int> deposits_ID, vector<int> credits_ID) {
    this->username = username;
    this->password = password;
    this->authority = authority;
    this->name = name;
    this->passport = passport;
    this->phone = phone;
    this->email = email;
    this->ID = ID;
    this->bank_accounts_ID = bank_accounts_ID;
    this->credits_ID = credits_ID;
    this->deposits_ID = deposits_ID;
    if(count < ID){
        this->count = ID;
    }
}
