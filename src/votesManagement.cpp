#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;

//Fonction qui collecte les votes des électeurs et les attributs aux candidat(s) désirée !
vector<CandidatesCum>collectVotes(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates)
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
                cout << "Vous n'avez plus de points a distribuer. " << endl << endl;
                break;
            }
            
            cout << vectorVoters[v].GetName() << " , veuillez choisir le nombre de points que vous souhaitez distribuer à "
                 << vectorCandidates[c].getName() << endl << "Pour rappel vous avez " << vectorVoters[v].GetPoint() << " points. " << endl << "--> ";
            cin >> pointCollected;

            // Conditionn pour vérifier que l'entrée cin est bien un chiffre valable
            if (cin.fail()) {
                cerr << "Veuilliez entrez un chiffre et non une lettre" << endl;
                cin.clear();
                cin.ignore();
                goto labelPointsAdonner;
            
            }

            else if (pointCollected < 0) 
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

            cout << endl << "Vous avez distribué " << pointCollected << " points à " << vectorCandidates[c].getName() << "." << endl;
            cout << "Il vous reste " << vectorVoters[v].GetPoint() << " points." << endl;
        }
    }

    for(size_t res = 0; res < vectorCandidates.size() ; res++)
    {
        cout << vectorCandidates[res].getName() << " à récolter " << vectorCandidates[res].getPointCollected() << " points !" << endl;
    }
    return vectorCandidates;
}

string isWinnerName(vector<CandidatesCum> vectorCandidatesWin)
{
    string winnerName;
    int winnerPoints = 0;
    vector<CandidatesCum>vectorCandidatesWinFinal;
    
    for (size_t res = 0; res < vectorCandidatesWin.size() ; res++) 
    {
        //Parcourir le tableau pour trouver le nombre de points maximum reçu
        if (vectorCandidatesWin[res].getPointCollected() > winnerPoints ) 
        {
            winnerPoints = vectorCandidatesWin[res].getPointCollected();
        }
    }

    //Gestion de l'égalité, on ajoute les candidats qui ont le meme nombre de points que le nombre de points maximum qu'un candidats a recu
    for (size_t x = 0 ; x < vectorCandidatesWin.size() ; x++) 
    {
        if (vectorCandidatesWin[x].getPointCollected() == winnerPoints) 
        {
            vectorCandidatesWinFinal.push_back(vectorCandidatesWin[x]);
        }
    }
    // Si la taille de ce vector est égale a 1 (en gros si il n'y a pas d'égalité) on donnne le nom du gagnants.
    if (vectorCandidatesWinFinal.size() == 1 ) 
    {
        winnerName = vectorCandidatesWinFinal[0].getName();
        cout << endl << "Le goût de glace gagnant est " << "\033[31m" <<winnerName << "\033[0m" << " avec " << vectorCandidatesWinFinal[0].getPointCollected() << " points" << endl;
    }
    else 
    {
        cout << vectorCandidatesWinFinal.size() << " glaces sont arrivés à égalité." << endl
             << "Il s'agit de : " << endl;
        for (size_t n = 0; n < vectorCandidatesWinFinal.size() ; n++) 
        {
            cout << vectorCandidatesWinFinal[n].getName() << endl;        
        }
    }
    return winnerName;
}




