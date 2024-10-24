#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CandidatesCum
{
    string Name;
    int PointCollected = 0;
    // bool Winner;

    void setName(const string& name)
    {
        Name = name;
    }

    const string getName() const
    {
        return Name;
    }

    void setPointCollected(int& pointCollected)
    {
        PointCollected += pointCollected ;
    }

    int getPointCollected() const
    {
        return PointCollected;
    }
};

struct CandidatesAlt
{
    string Name;
    unsigned Vote = 0;
    bool Winner = false;

    void setName(const string& name)
    {
        Name = name;
    }

    const string getName() const
    {
        return Name;
    }

    void setVoteCollected(unsigned& voteCollected)
    {
        Vote += voteCollected;
    }

    unsigned getVoteCollected() const
    {
        return Vote;
    }
};