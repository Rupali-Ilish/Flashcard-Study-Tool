#include "account.h"

Account::Account()
{
    userName = "";
    password = "";
}
// Constructor
Account::Account(string name, string pass)
{
    userName = name;
    password = pass;
}

// create a new account
void Account::createAccount(string name, string pass)
{
    userName = name;
    password = pass;
    // cout <<"\033[32m";
    cout << "\nAccount created successfully! You are now logged in." << endl
         << endl;
    // cout << "\033[0m";
}

// log in
bool Account::login(string name, string pass)
{
    ifstream inFile("userInfo.txt"); // Open the file for reading
    if (inFile)
    {
        string fileUsername, filePassword;
        while (getline(inFile, fileUsername)) // Read username
        {
            if (getline(inFile, filePassword)) // Read corresponding password
            {
                if (fileUsername == name && filePassword == pass)
                {
                    cout << "Login successful!\n";
                    return true; // Match found
                }
            }
        }
        inFile.close();
    }
    else
    {
        cerr << "Error: Unable to open userInfo.txt for reading.\n";
    }
    cout << "Invalid username or password.\n";
    return false; // No match found
}

// log out
void Account::logout()
{
    cout << "\nLogged out successfully!" << endl
         << endl;
}

// Get username when needed
string Account::getUserName() const
{
    return userName;
}
