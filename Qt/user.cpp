#pragma once
#include "user.h"
#include<iostream>
#include <ctime>
#include<map>
#include<assert.h>
#include <algorithm>
#include<string>
using namespace std;

user::user()
{
}

string user::GenerateEmail()
{
    return ID + "@cis.asu.eg";
}

string user::GeneratePassword()
{
    string password;
    pair<char, char> ranges[3] = { {'0', '9'}, {'A', 'Z'}, {'a', 'z'} };
    int standardSize = 10;

    for (int i = 0; i < standardSize; i++)
    {
        int choosedRange = i % 3;
        int start = ranges[choosedRange].first, end = ranges[choosedRange].second;
        password += start + rand() % (end - start + 1);
    }

    return password;
}

string user::GenerateID(int id, int year)
{
    string ID = to_string(id);
    string leadingZeros = string(4 - ID.size(), '0');
    return to_string(year) + leadingZeros + ID;
}

void user::setEmail(string email)
{
    // exception if not valid format
    assert(validate_email(email));
    this->email = email;
}

void user::setPassword(string password)
{
    // exception if not valid format
    assert(validate_password(password));
    this->password = password;
}

string user::getEmail()
{
    return email;
}

string user::getPassword()
{
    return password;
}


//check whether the email in a valid format
bool user::validate_email(string email)
{
    int At = -1, Dot = -1;
    for (int i = 0; i < email.size(); i++)
        if (email[i] == '@')
            At = i;
        else if (email[i] == '.')
            Dot = i;

    if (At == -1 || Dot == -1)
        return 0;

    if (At > Dot || Dot == At + 1)
        return 0;

    return (Dot < email.size() - 1);
}

//check whether the password is valid
bool user::validate_password(string password)
{
    if (password.size() < 8 || password.size() > 16)
        return false;

    // at least 1 digit
    if (!count_if(password.begin(), password.end(), [&](auto c) {return '0' <= c && c <= '9'; }))
        return false;

    // at least 1 lower case
    if (!count_if(password.begin(), password.end(), [&](auto c) {return 'a' <= c && c <= 'z'; }))
        return false;

    // at least 1 upper case
    if (!count_if(password.begin(), password.end(), [&](auto c) {return 'A' <= c && c <= 'Z'; }))
        return false;

    return true;
}
