#include <iostream>
#include <vector>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;


vector<VotersAlt> collectVotesAlt(vector<VotersAlt> vectorVoters, vector<CandidatesAlt> vectorCandidates)
{
    string nameCandidate;
    // vectorVoters 
    for (size_t v = 0; v < vectorVoters.size() ; ++v)
    {
        cout << "Voici les candidats qui se presente : " << endl;
        for (size_t c = 0; c < vectorCandidates.size() ; ++c)
        {
            cout << "- " << vectorCandidates[c].getName() << endl;
        }

        cout << "entrer le nom du candidat que vous souhaitez voté(e) : " ;
        cin >> nameCandidate;
        vectorVoters[v].setVote(nameCandidate);
        
        for(size_t c = 0; c < vectorCandidates.size() ; ++c)
        {
            if (nameCandidate == vectorCandidates[c].getName())
            {
                vectorCandidates[c].Vote += 1;
                cout << "Vous avez voté pour " << vectorCandidates[c].getName() << endl;
                cout << "\n\n\n\n\n\n\n";
            }
        }
    }
    return vectorVoters;
}