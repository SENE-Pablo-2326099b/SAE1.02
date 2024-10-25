#ifndef CREATEVOTERSCUM_HPP
#define CREATEVOTERSCUM_HPP


#include <iostream>
using namespace std;

struct VotersCum
{
    int pointsDistributed = 0;
    bool hasVoted = false;

    void SetPoint(int pointsDistributedCin)
    {
        pointsDistributed = pointsDistributedCin;
    }

    const int GetPoint() const 
    {
        return pointsDistributed;

    }

};

#endif