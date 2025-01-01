#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <chrono>
#include "flashcard.h"

class Session
{
private:
    int score;
    long long duration;
    std::vector<Flashcard *> currentDeck;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;

public:
    Session();
    void start();
    void end();
    void evaluation();
    void setDeck(const std::vector<Flashcard *> &deck);
    int getScore() const; // Add this method
    std::vector<Flashcard *> getDeck() const;
    long long getDuration() const;
    void clearScore();
};

#endif // SESSION_H
