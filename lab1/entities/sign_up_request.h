#ifndef SIGN_UP_REQUEST_H
#define SIGN_UP_REQUEST_H
#include "user.h"
using namespace std;

class sign_up_request
{
private:
    string username;
    string password;
    string name;
    string passport;
    string phone;
    string email;

public:
    sign_up_request(string username, string password, string name, string passport, string phone, string email);

    string getUsername() const;
    void setUsername(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
    string getName() const;
    void setName(const string &value);
    string getPassport() const;
    void setPassport(const string &value);
    string getPhone() const;
    void setPhone(const string &value);
    string getEmail() const;
    void setEmail(const string &value);
};

#endif // SIGN_UP_REQUEST_H
