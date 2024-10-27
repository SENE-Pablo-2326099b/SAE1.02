#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;

//Fonction qui collecte les votes des électeurs et les attributs aux candidat(s) désirée !
vector<CandidatesCum> collectVotes(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates)
{
    int pointCollected;
        // On pcollectVotesarcour vectorVoters 
    for (size_t v = 0; v < vectorVoters.size() ; v++)
    {
        // ON parcour vectorCandidates
        for(size_t c = 0; c < vectorCandidates.size() ; c++)
        {
            // On vérifie qu'il reste des points a distribuée
            labelPointsAdonner:
            if (vectorVoters[v].GetPoint() <= 0) {
                cout << "Vous n'avez plus de points a distribuer. " << endl;
                break;
            }
            
            cout << "Electeur numéro " << v + 1 << " , veuillez choisir le nombre de points que vous souhaitez distribuer à "
                 << vectorCandidates[c].getName() << endl << "Pour rappel vous avez " << vectorVoters[v].GetPoint() << " points. " << endl << endl;
            cin >> pointCollected;

            // Conditionn pour vérifier que l'entrée cin est bien un chiffre valable
            if (cin.fail()) {
                cerr << "Veuilliez entrez un chiffre et non une lettre" << endl;
                cin.clear();
                cin.ignore();
                goto labelPointsAdonner;
            
            }

            else if (pointCollected <= 0) 
            {
                cerr << "Vous ne pouvez pas donner des points négatif ! " << endl;
                cin.clear();
                cin.ignore();
                goto labelPointsAdonner;
                
            }

            else if (vectorVoters[v].pointsDistributed < pointCollected) 
            {
                cerr << "Vous ne pouvez pas donnez plus de points que vous n'en possédez ! " << endl;
                cin.clear();
                cin.ignore();
                goto labelPointsAdonner;
            }
            

            vectorCandidates[c].setPointCollected(pointCollected);
            vectorVoters[v].pointsDistributed -=  pointCollected;

            cout << "Vous avez distribué " << pointCollected << " points à " << vectorCandidates[c].getName() << "." << endl << endl;
            cout << "Il vous reste " << vectorVoters[v].GetPoint() << " points." << endl;
        }
    }

    for(size_t res = 0; res < vectorCandidates.size() ; res++)
    {
        cout << vectorCandidates[res].getName() << " à récolter " << vectorCandidates[res].getPointCollected() << " points !" << endl;
    }
    return vectorCandidates;
}


// // PAS SUR DE L'IMPLEMENTATION : 
// // void egal(vector<CandidatesCum> aComparerPourEgalite){

// //     vector<CandidatesCum> equalityCandidates;
// //     for (size_t i = 0 ; i < aComparerPourEgalite.size() ; i++) {
        
// //         equalityCandidates.push_back(aComparerPourEgalite[0]);

// //         if (aComparerPourEgalite[i].getPointCollected() == aComparerPourEgalite[i + 1].getPointCollected()) {
// //             equalityCandidates.push_back(aComparerPourEgalite[i+1]);
// //         }
// //     }
// // }


string isWinnerName(vector<CandidatesCum> vectorCandidatesWin)
{
    string winnerName;
    int winnerPoints = 0;
    //Parcourir le tableau pour comparer les points des différents candidats

    //Trie le tableau en fonction du nombre de points collecter
    sort(vectorCandidatesWin.begin(), vectorCandidatesWin.end(), [](const CandidatesCum& a, const CandidatesCum& b){
        return a.PointCollected > b.PointCollected;
    });

    
    for (size_t res = 0; res < vectorCandidatesWin.size() ; res++) {

    //     cout << vectorCandidatesWin[res].getPointCollected() << endl;

    //     if (vectorCandidatesWin[res].PointCollected == vectorCandidatesWin[res + 1].PointCollected) {
    //         cout << "Le candidats" << vectorCandidatesWin[res].getName() << " et le candidat " << vectorCandidatesWin[res + 1].getName() << " sont arrivée a égalité" << endl;
    //     }
    //     else {
    //         cout << "Le candidat ayant obtenue le plus de points est " << vectorCandidatesWin[0].getName() << " avec " << vectorCandidatesWin[0].getPointCollected() << " points !" << endl;
    //     }




        if (vectorCandidatesWin[res].getPointCollected() > winnerPoints ) {
            cout << res << endl;
            winnerPoints = vectorCandidatesWin[res].getPointCollected();
            winnerName = vectorCandidatesWin[res].getName();
        }
    }

    cout << "Le candidat " << winnerName << " gagne avec " << winnerPoints << " points" << endl ;
    return winnerName;
}