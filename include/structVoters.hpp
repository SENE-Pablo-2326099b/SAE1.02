#include <iostream>
using namespace std;

struct Voters
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



    // void setVotes();
};