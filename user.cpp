#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "user.h"
#include "session.h"
#include "account.h"

// Initialize static member
set<string> User::allaccounts;

User::User(string user_nam) // Constructor
{
    name = user_nam;
    score = 0;
}

void User::startSession(Session &session) // start session
{
    session.start();
}
void User::endSession(Session &session) // end session
{
    session.end();
}

bool User::createAccount(Account &account, string name, string pass) // create account
{
    if (allaccounts.count(name))
    {
        cout << "\nAccount already exists with username: " << name << ". Please choose a different username." << endl;
        return false;
    }
    else
    {
        account.createAccount(name, pass);
        allaccounts.insert(name);

                    ofstream file("userInfo.txt", ios::app); //saving user info here
                    if (file.is_open()) 
                    { 
                        file << name << "\n"; 
                        file << pass << "\n"; 
                        file.close(); 
                    } 
                    else { cerr << "Error: Unable to open userInfo.txt for writing.\n"; }
                    
        return true;
    }

}

void User::loadAccountsFromFile()
{
    ifstream inFile("userInfo.txt");
    if (inFile)
    {
        string username, password;
        while (inFile >> username >> password)
        {
            allaccounts.insert(username);
        }
        inFile.close();
    }
    else
    {
        cerr << "Error: Unable to open userInfo.txt for reading.\n";
    }
}

string User::getName() const 
{
    return name;
}

int User::getScore() const 
{
    return score;
}

void User::updateScore(int newScore) 
{
    score = newScore;
}
