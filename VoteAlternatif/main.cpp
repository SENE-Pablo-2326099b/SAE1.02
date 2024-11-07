#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "structVoters.hpp"
#include "structCandidates.hpp"
#include "CreateVotersAlt.hpp"
#include "CreateCandidatesAlt.hpp"
#include "CollectVotesAlt.hpp"
#include "CountVotesAlt.hpp"
#include "AlternativeVote.hpp"

using namespace std;


int main()
{
    vector<VotersAlt> VectorVoters;
    vector<CandidatesAlt> VectorCandidates;

    vector <VotersAlt> a = createVotersAlt(VectorVoters);
    vector <CandidatesAlt> b = createCandidateAlt(VectorCandidates);
    a = collectVotesAlt(a, b);
    b = countVotesAlt(a, b);
    CandidatesAlt winner = alternativeVote(a, b);
    cout << winner.getName() << endl;
}
