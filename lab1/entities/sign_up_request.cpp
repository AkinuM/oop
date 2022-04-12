#include "sign_up_request.h"
using namespace std;

sign_up_request::sign_up_request(string username, string password, string name, string passport, string phone, string email)
{
    this->username = username;
    this->password = password;
    this->name = name;
    this->passport = passport;
    this->phone = phone;
    this->email = email;
}

string sign_up_request::getPassword() const
{
    return password;
}

void sign_up_request::setPassword(const string &value)
{
    password = value;
}

string sign_up_request::getName() const
{
    return name;
}

void sign_up_request::setName(const string &value)
{
    name = value;
}

string sign_up_request::getPassport() const
{
    return passport;
}

void sign_up_request::setPassport(const string &value)
{
    passport = value;
}

string sign_up_request::getPhone() const
{
    return phone;
}

void sign_up_request::setPhone(const string &value)
{
    phone = value;
}

string sign_up_request::getEmail() const
{
    return email;
}

void sign_up_request::setEmail(const string &value)
{
    email = value;
}

string sign_up_request::getUsername() const
{
    return username;
}

void sign_up_request::setUsername(const string &value)
{
    username = value;
}
