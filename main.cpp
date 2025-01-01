#include "flashcard.h"
#include "menu.h"
#include "user.h"
#include "account.h"
#include "session.h"
#include "statistics.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    string username, password, filename;
    bool isLoggedIn = false;
    User *currentUser = nullptr;
    Account currentAccount;
    Deck currentDeck;
    Session currentSession;

    filename = "flashcards.txt";
    loadFlashcardsFromFile(filename, currentDeck);

    User user("defaultUser");
    user.loadAccountsFromFile();

    while (true)
    {
        // Show the main menu
        showMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Create Account
            cout << "\n--- Create Account ---\n";
            cout << "----------------------" << endl;
            cout << "Enter a username: ";
            cin >> username;
            cout << "Enter a password: ";
            cin >> password;

            // Create user and account, then check if username exists
            currentUser = new User(username);                                            // Create a new User instance
            isLoggedIn = currentUser->createAccount(currentAccount, username, password); // Create account

            // Automatically log in after account creation
            break;
        }
        case 2:
        {
            // Log In
            cout << "\n--- Log In ---\n";
            cout << "--------------" << endl;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            // Log in the user
            if (currentAccount.login(username, password))
            {
                currentUser = new User(username); // Set the current user
                isLoggedIn = true;
            }
            break;
        }
        case 3:
            // Exit
            cout << "\nExiting... Thank you for using the system!\n\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter 1-3.\n\n";
        }

        // Once logged in, show the user menu
        while (isLoggedIn)
        {
            showUserMenu(); // Show user menu
            cin >> choice;

            Statistics stats;

            switch (choice)
            {
            case 1:
            {
                // Start Session
                cout << "\n--- Start Session ---\n";
                cin.ignore();
                currentSession.setDeck(currentDeck.getCards()); // Set the deck for the session
                currentSession.start();
                break;
            }
            case 2:
            {
                // Set Up Flashcard Deck (Display all flashcards)
                cout << "\n--- Flashcard Deck ---\n";
                currentDeck.displayDeck(); // Display all flashcards in the deck
                break;
            }
            case 3:
            {
                // Add Basic Flashcard
                string question, answer;
                cout << "\n--- Add Basic Flashcard ---\n";
                cout << "---------------------------" << endl;
                cout << "Enter the question: ";
                cin.ignore(); // Clear input buffer
                getline(cin, question);
                cout << "Enter the answer: ";
                getline(cin, answer);

                Flashcard *card = new Flashcard(question, answer);
                // add to file here
                currentDeck.addCard(card); // Add card to the deck
                cout << "Flashcard added!\n\n";

                ofstream file("flashcards.txt", ios::app);
                if (file.is_open())
                {
                    file << question << "\n";
                    file << answer << "\n";
                    file.close();
                }
                else
                {
                    cerr << "Error: Could not open file flashcards.txt for writing.\n";
                }

                break;
            }
            case 4:
            {
                // View Statistics
                cout << "--- View Statistics ---\n";
                cout << "-----------------------" << endl;

                stats.displayStatistics(currentSession); // Pass the session to displayStatistics
                break;
            }
            case 5:
            {
                // Log Out
                cout << "Logging out...\n\n";
                isLoggedIn = false;

                // clear score
                currentSession.clearScore();

                break;
            }
            default:
                cout << "Invalid option. Please enter 1-6.\n\n";
            }
        }
    }

    return 0;
}
