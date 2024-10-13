#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;   





//Fonction qui permet de créer et d'initialiser les candidats.
vector<CandidatesCum> createCandidate(vector<CandidatesCum> VectorCandidates)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer
    cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << ": ";
    int numberCandidate;
    cin >> numberCandidate;

    //Initialsation d'un vector qui contient les candidats
    cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    //Initialiser le nom des candidats.
    for(int i = 0; i <= numberCandidate - 1; i++)
    {   
        string name;
        cout << "Quelle est le nom du " << i + 1 << " candidat ? " << endl;
        cin >> name ;
        VectorCandidates[i].setName(name);
        cout << endl << endl;
    }
    for (int i = 0; i <= numberCandidate - 1; i++)
    {
        cout << "Le candidat numéro " << i + 1 << " se nomme " << VectorCandidates[i].getName() << endl;
    }

    return VectorCandidates;
}


//Fonction qui permet de créer et d'initialiser les électeurs.
vector<VotersCum> createVoters(vector<VotersCum>VectorVoters)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer.
    cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :" << endl;
    cout << ": " ; 
    int numberVoters;
    cin >> numberVoters;
    cout << endl;
    
    //Initialsation d'un vector qui contient les électeurs
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl;
    VectorVoters.resize(numberVoters);

    //Attribution des points au électeurs
    cout << "Choisisez le nombre de points que chaque électeurs détient : " << endl;
    int pointsDistributed = 0;
    cin >> pointsDistributed;
    for(int i = 0; i <= numberVoters - 1; i++)
    {
        VectorVoters[i].SetPoint(pointsDistributed);
    }
    for (int i = 0; i <= numberVoters - 1; i++)
    {
        cout << "L'électeur " << i + 1 << " à " << VectorVoters[i].GetPoint() << " points" << endl;
    }

    return VectorVoters;
}





//A finir car trop mal a la tete la mdr
//Mais en gros faut juste que je trouve le moyen de faire voter chaque electeur pour chaque candidat 
vector<CandidatesCum> collectVotes(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates)
{
    int pointCollected;
        // vectorVoters 
    for (size_t v = 0; v < vectorVoters.size() ; v++)
    {
        //vectorCandidates
        for(size_t c = 0; c < vectorCandidates.size() ; c++)
        {
            if (vectorVoters[v].GetPoint() <= 0) {
                cout << "Vous n'avez plus de points a distribuer. " << endl;
                break;
            }
            
            cout << "Electeur numéro " << v + 1 << " , veuillez choisir le nombre de points que vous souhaitez distribuer à "
                 << vectorCandidates[c].getName() << endl << "Pour rappel vous avez " << vectorVoters[v].GetPoint() << " points. " << endl;
            cin >> pointCollected;

            // Conditionn pour vérifier que l'entrée cin est bien un chiffre valable            AFAIREEEEEE
            // if (pointCollected < 0 || ) {
            // }


            vectorCandidates[c].setPointCollected(pointCollected);
            vectorVoters[v].pointsDistributed -=  pointCollected;

            cout << "Vous avez distribué " << pointCollected << " points à " << vectorCandidates[c].getName() << "." << endl;
            cout << "Il vous reste " << vectorVoters[v].GetPoint() << " points." << endl;

            // cout << "Voici le candidat " << endl << vectorCandidates[c].getName() << endl;
            // cout << "Electeurs numéro " << v << " , veuilliez choisir combien de points vous lui mettez" << endl;
            
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

    for (size_t res = 0; res < vectorCandidatesWin.size(); res++) {
        if (vectorCandidatesWin[res].getPointCollected() > winnerPoints) {
            winnerPoints = vectorCandidatesWin[res].getPointCollected();
            winnerName = vectorCandidatesWin[res].getName();
        }
    }
    cout << "Le candidat " << winnerName << " gagne avec " << winnerPoints << " points" << endl ;
    return winnerName;
}

int main()
{
    vector<VotersCum> VectorVoters;
    vector<CandidatesCum> VectorCandidates;

    vector <VotersCum> a = createVoters(VectorVoters);
    vector <CandidatesCum> b = createCandidate(VectorCandidates);
    vector<CandidatesCum> win = collectVotes(a, b);
    isWinnerName(win);

    return 0;
}

