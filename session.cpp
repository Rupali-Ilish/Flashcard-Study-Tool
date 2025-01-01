#include "session.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace chrono;

string trim(const string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == string::npos || end == string::npos)
    {
        return ""; 
    }

    return str.substr(start, end - start + 1);
}

Session::Session() : score(0), duration(0) {}

void Session::start()
{
    startTime = high_resolution_clock::now(); // Record start time
    score = 0;                                

    cout << "\nAnswer the following questions..... \n" << endl;
    evaluation(); // Start exam
}

void Session::end()
{
    endTime = high_resolution_clock::now();                         // Record end time
    duration = duration_cast<seconds>(endTime - startTime).count(); // Duration in seconds
    cout << "\nSession ended. \nScore: " << score << endl
         << endl; 
}

void Session::evaluation()
{
    for (size_t i = 0; i < currentDeck.size(); ++i)
    {
        string given;
        cout << endl;
        currentDeck[i]->displayQuestion(); // Display the question from each flashcard
        cout << "\nEnter your answer: ";
        getline(cin,given);                                                    // Take user input as answer
        transform(given.begin(), given.end(), given.begin(), ::tolower); 

        string tmp = currentDeck[i]->getAnswer();
        tmp = trim(tmp);

        if (given == tmp)
        {
            cout << "\nCorrect Answer" << endl;
            score++; 
        }
        else
        {
            cout << "\nWrong answer! Correct answer is: " << tmp << endl;
        }
    }
    end(); // End session and display score
}

void Session::setDeck(const vector<Flashcard *> &deck)
{
    currentDeck = deck; // Set the current deck of flashcards
}

int Session::getScore() const
{
    return score; 
}

vector<Flashcard *> Session::getDeck() const
{
    return currentDeck; 
}

long long Session::getDuration() const
{
    return duration; 
}

void Session::clearScore(void)
{
    score = 0;
    duration=0;
}
