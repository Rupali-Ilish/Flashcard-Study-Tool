#pragma once
#include <bits/stdc++.h>
#include "account.h"
#include "session.h"
using namespace std;

// class Session;
// class Account;

class User
{
private: // encapsulated as we used private access modifier
    string name;
    int score;
    static set<string> allaccounts; //to store all accounts by username
    // so that duplicate username can't exist

public:
    User(string user_nam); // Constructor

    void startSession(Session &session);                            // Start session
    void endSession(Session &session);                              // end session
    bool createAccount(Account &account, string name, string pass); // create account

    string getName() const;         // get name
    int getScore() const;           // get score
    void updateScore(int newScore); // updating score
    void loadAccountsFromFile();
};