#pragma once
#include <bits/stdc++.h>
using namespace std;

// Helper function to convert a string to lowercase
string toLowercase(const string &input);

// Base class Flashcard
class Flashcard
{
protected:
    string question; // The flashcard question
    string answer;   // The flashcard answer

public:
    Flashcard(const string &q, const string &a); // Constructor
    virtual ~Flashcard();                        // Virtual destructor

    virtual void displayQuestion() const; // Displays the question
    virtual void displayAnswer() const;   // Displays the answer
    string getAnswer() const;             // Getter for the answer
};

// Deck class to manage a collection of flashcards
class Deck
{
private:
    vector<Flashcard *> cards; // A vector to store pointers to flashcards

public:
    Deck();  // Constructor
    ~Deck(); // Destructor

    void addCard(Flashcard *card);   // Adds a new flashcard to the deck
    // void shuffleDeck();              // Shuffles the order of flashcards
    void displayDeck() const;        // Displays all the flashcards in the deck
    vector<Flashcard *> &getCards(); // Getter for the deck
};

// Function to load flashcards from a file
void loadFlashcardsFromFile(const string &filename, Deck &deck);