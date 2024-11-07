#ifndef CREATECANDIDATESALT_HPP
#define CREATECANDIDATESALT_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

#endif
