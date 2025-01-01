#ifndef STATISTICS_H
#define STATISTICS_H

#include "session.h"

class Statistics: public Session
{
private:
    float accuracy;

public:
    Statistics();
    void calculateStats(const Session &session);    // Modify this method to accept a Session instance
    void displayStatistics(const Session &session); // Modify this method to accept a Session instance
};

#endif // STATISTICS_H
