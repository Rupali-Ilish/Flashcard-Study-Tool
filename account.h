#pragma once
#include <bits/stdc++.h>
using namespace std;

class Account
{
private: // encapsulated as we used private access modifier
    string userName;
    string password;

public:

    //function overloadding
    Account();

    Account(string name, string pass); // Constructor
    //till here

    void createAccount(string name, string pass); // create new account

    bool login(string name, string pass); // log in

    void logout(); // log out

    // Get username as we can't directly access the username
    string getUserName() const;
};