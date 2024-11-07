#ifndef CREATEVOTERSCUM_HPP
#define CREATEVOTERSCUM_HPP

#include <iostream>
using namespace std;

struct VotersCum
{
    int pointsDistributed = 0;
    bool hasVoted = false;
    string name;

    void SetName(string nameCin)
    {
        name = nameCin;
    }

    const string GetName() const
    {
        return name;
    }

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