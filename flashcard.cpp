#include "flashcard.h"
#include <bits/stdc++.h>

using namespace std;

string toLowercase(const string &input)
{
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Flashcard class implementations
Flashcard::Flashcard(const string &q, const string &a)
    : question(toLowercase(q)), answer(toLowercase(a)) {}

Flashcard::~Flashcard() {}

void Flashcard::displayQuestion() const
{
    cout << "\033[36m" << "Question: " << "\033[0m" << question << endl;
}

void Flashcard::displayAnswer() const
{
    cout << "\033[36m" << "Answer: " << "\033[0m" << answer << endl;
}

string Flashcard::getAnswer() const
{
    return answer;
}

// Deck class implementations
Deck::Deck()
{
    srand(time(nullptr)); //random number
}

Deck::~Deck()
{
    for (auto card : cards)
    {
        delete card; 
    }
}

void Deck::addCard(Flashcard *card)
{
    cards.push_back(card);
}

void Deck::displayDeck() const
{
    for (size_t i = 0; i < cards.size(); ++i)
    {
        cout << "Card " << i + 1 << ":" << endl;
        cards[i]->displayQuestion();
        cards[i]->displayAnswer();
        cout << "-------------" << endl
             << endl;
    }
}

vector<Flashcard *> &Deck::getCards()
{
    return cards;
}

// Function to load flashcards from a file
void loadFlashcardsFromFile(const string &filename, Deck &deck)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string type, question, answer, category;

    while (getline(file, question))
    {
        getline(file, answer);
        deck.addCard(new Flashcard(question, answer));
    }

    file.close();
}
