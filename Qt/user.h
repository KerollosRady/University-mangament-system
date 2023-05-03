#pragma once
#include<iostream>
#include <ctime>
using namespace std;

class user
{
    string email;
    string password;
public:
    string name;
    string ID;
    user();

    void setEmail(string email);
    string GenerateEmail();
    void setPassword(string password);
    string GeneratePassword();
    string GenerateID(int id, int year);

    string getEmail();
    string getPassword();

    bool validate_email(string email);
    bool validate_password(string password);

};
