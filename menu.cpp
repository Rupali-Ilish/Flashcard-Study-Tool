#include "menu.h"
#include <iostream>
using namespace std;

void showMainMenu()
{
    cout <<"\033[32m";
    cout << endl << "Welcome to the Flashcard Study Tool!\n\n";
    cout << "--- Main Menu ---\n";
    cout << "-----------------" << endl;
    cout << "1. Create Account\n";
    cout << "2. Log In\n";
    cout << "3. Exit\n";
    cout << "\nPlease select an option (1-3): ";
    cout << "\033[0m";
}

void showUserMenu()
{
    cout <<"\033[32m";
    cout << "\n--- User Dashboard ---\n";
    cout << "----------------------" << endl;
    cout << "1. Start Session\n";
    cout << "2. Display Deck\n";
    cout << "3. Add Flashcard\n";  // Option to add new cards
    cout << "4. View Statistics\n";
    cout << "5. Log Out\n";
    cout << "\nPlease select an option (1-5): ";
    cout << "\033[0m";
}
