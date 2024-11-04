#include <iostream>
#include <vector>
#include "../include/structVoters.hpp"
#include <random>
#include <string>
#include "../include/structCandidates.hpp"
using namespace std;

CandidatesAlt alternativeVote(vector<VotersAlt> vectorVoters, vector<CandidatesAlt> vectorCandidatesAfterVote)
{
    string loserName = "";

    while (true)
    {
        vector<size_t> cmin = {0};

        for (size_t c = 1; c < vectorCandidatesAfterVote.size() ; ++c)
        {

            if (vectorCandidatesAfterVote[c].Vote < vectorCandidatesAfterVote[cmin[0]].Vote)
            {
                cmin.resize(1);
                cmin[0] = c;
            }

            else if (vectorCandidatesAfterVote[c].Vote > (vectorVoters.size() / 2))
            {
                vectorCandidatesAfterVote[c].Winner = true;

                cout << "Le gagnant est : " << vectorCandidatesAfterVote[c].getName() << " avec " 
                << (vectorCandidatesAfterVote[0].getVoteCollected() * 100 ) / vectorVoters.size() * 100 << " %" << endl;

                return vectorCandidatesAfterVote[c];
            }

            else if (vectorCandidatesAfterVote[c].Vote == vectorCandidatesAfterVote[cmin[0]].Vote)
            {
                cmin.resize(cmin.size() + 1);
                cmin[cmin.size() - 1] = c;
            }

        }

        cout << "Les candidats avec le moins de votes sont : ";
        for (size_t i = 0; i < cmin.size(); ++i) {
            cout << vectorCandidatesAfterVote[cmin[i]].getName() << " ";
        }
        cout << endl;

        if (cmin.size() == 1)
        {
            loserName = vectorCandidatesAfterVote[cmin[0]].getName();
            cout << "Le candidat suivant a été éliminé : " << loserName << endl;
            vectorCandidatesAfterVote.erase(vectorCandidatesAfterVote.begin() + cmin[0]);
        }
        
        else
        {
            unsigned rd = rand() % cmin.size();
            loserName = vectorCandidatesAfterVote[cmin[rd]].getName();
            cout << "Le candidat suivant a été éliminé : " << loserName << endl;
            vectorCandidatesAfterVote.erase(vectorCandidatesAfterVote.begin() + cmin[rd]);
        }

        if (vectorCandidatesAfterVote.size() == 1)
        {
            vectorCandidatesAfterVote[0].Winner = true;

            cout << "Le gagnant est : " << vectorCandidatesAfterVote[0].getName() << " avec " 
            << (vectorCandidatesAfterVote[0].getVoteCollected() * 100 ) / vectorVoters.size() << " %" << endl;

            return vectorCandidatesAfterVote[0];
        }

        for (size_t v = 0; v < vectorVoters.size() ; ++v)
        {
            if (vectorVoters[v].getVote() == loserName)
            {
                string tempcandidate;
                cout << "Votre candidat a été éliminé" << endl;
                cout << "Voici les candidats qui sont toujours present : " << endl;
                
                for (size_t c = 0; c < vectorCandidatesAfterVote.size() ; ++c)
                {
                    cout << "- " << vectorCandidatesAfterVote[c].getName() << endl;
                }

                cout << "entrer le nom du candidat que vous souhaitez voté(e) : " ;
                cin >> tempcandidate;
                cout << "\n\n\n\n\n\n\n";

                vectorVoters[v].setVote(tempcandidate);
                
                for (size_t c = 0; c < vectorCandidatesAfterVote.size() ; ++c)
                {
                    if (tempcandidate == vectorCandidatesAfterVote[c].getName())
                    {
                        vectorCandidatesAfterVote[c].Vote += 1;
                    }
                }
            }   
        }
    }
}