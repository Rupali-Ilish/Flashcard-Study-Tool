#include "statistics.h"
#include <iostream>
#include <iomanip> 

using namespace std;

Statistics::Statistics() : accuracy(0.0f) {}

void Statistics::calculateStats(const Session& session) 
{
    int totalQuestions = session.getDeck().size(); 
    if (totalQuestions > 0) {
        accuracy = (static_cast<float>(session.getScore()) / totalQuestions) * 100; // Calculate accuracy
    } else {
        accuracy = 0.0f; // No question means 0% accuracy
    }
}

void Statistics::displayStatistics(const Session& session) 
{
    calculateStats(session); // Calculate accuracy and others before displaying

    int totalQuestions = session.getDeck().size();
    long long duration = session.getDuration();

    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    int seconds = duration % 60;

    // Displaying the statistics
    cout << "\n--- Statistics ---" << endl << endl;
    cout << "Total Questions: " << totalQuestions << endl;
    cout << "Correct Answers: " << session.getScore() << endl; //change
    cout << "Your Accuracy: " << fixed << setprecision(2) << accuracy << " %" << endl;
    cout << "Time: " << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)." << endl << endl;
}


