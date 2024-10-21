// #include <algorithm>
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;   

//Fonction qui permet de créer et d'initialiser les électeurs.
vector<VotersCum> createVoters(vector<VotersCum>VectorVoters)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer.
    bool isGood = false;
    int numberVoters;
    //Condition pour verifier si l'entrée utilisateur est correct
    while (isGood == false) 
    {
        cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :" << endl << ":";
        cin >> numberVoters;
        
        if (cin.fail()) 
        {   
            cout << endl << "Error. Veuillez entrez un nombre valide" << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            isGood = true;
        }     
    }
    isGood = false;
    cout << endl; 
    //Initialsation d'un vector qui contient les électeurs
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl;
    VectorVoters.resize(numberVoters);

    //Attribution des points au électeurs
    int pointsDistributed = 0;
    while (isGood == false) 
    {
        // Condition qui verifie que l'entrée utilisateur est correct.
        cout << "Choisisez le nombre de points que chaque électeurs détient : " << endl;
        cin >> pointsDistributed;

        if (cin.fail()) 
        {
            cout << endl << "Error. Veuillez entrez un nombre valide" << endl;
            cin.clear();
            cin.ignore();
        }
        else 
        {
            isGood = true;
        }
    }

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



//Fonction qui permet de créer et d'initialiser les candidats.
vector<CandidatesCum> createCandidate(vector<CandidatesCum> VectorCandidates)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer
    bool isGood = false;
    int numberCandidate;
    while (isGood == false) {
        cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << ": ";
        cin >> numberCandidate;
        cin.ignore();
    
        if (cin.fail()) 
        {
            cout << endl << "Error. Veuillez entrez un nombre valide" << endl;
            cin.clear();
            cin.ignore();
        }
        else 
        {
            isGood = true;
        }
    }

    //Initialsation d'un vector qui contient les candidats
    cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    //Initialiser le nom des candidats.
    
    for(int i = 0; i < numberCandidate ; i++)
    {   
        bool isGood = false;
        string name;

        cout << "Quelle est le nom du " << i + 1 << " candidat ? " << endl;
        getline(cin, name);
        
        if(name.empty() || name == " " || name == "\t" || name == "\n")
        {
            cout << "Veuillez entrée un nom valide ! " << endl;
            cin.ignore();
            getline(cin , name);
        }
        else 
        {
            VectorCandidates[i].setName(name);
            cout << endl << endl;
        }

    }

    for (int i = 0; i <= numberCandidate - 1; i++)
    {
        cout << "Le candidat numéro " << i + 1 << " se nomme " << VectorCandidates[i].getName() << endl << endl;
    }
    return VectorCandidates;
}

//Fonction qui collecte les votes des électeurs et les attributs aux candidat(s) désirée !
vector<CandidatesCum> collectVotes(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates)
{
    int pointCollected;
        // On parcour vectorVoters 
    for (size_t v = 0; v < vectorVoters.size() ; v++)
    {
        // ON parcour vectorCandidates
        for(size_t c = 0; c < vectorCandidates.size() ; c++)
        {
            // On vérifie qu'il reste des points a distribuée
            if (vectorVoters[v].GetPoint() <= 0) {
                cout << "Vous n'avez plus de points a distribuer. " << endl;
                break;
            }
            
            cout << "Electeur numéro " << v + 1 << " , veuillez choisir le nombre de points que vous souhaitez distribuer à "
                 << vectorCandidates[c].getName() << endl << "Pour rappel vous avez " << vectorVoters[v].GetPoint() << " points. " << endl << endl;
            cin >> pointCollected;

            // Conditionn pour vérifier que l'entrée cin est bien un chiffre valable et             AFAIREEEEEE Pas finis pablo occupe toi en
            if (vectorVoters[v].pointsDistributed != 0 ) 
            {
                cout << "Vous ne pouvez pas donner des points négatif ! " << endl;
                
            }
            else if (vectorVoters[v].pointsDistributed < pointCollected) {
                cout << "Vous ne pouvez pas donnez plus de points que vous n'en possédez ! " << endl;
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


// PAS SUR DE L'IMPLEMENTATION : 
// void egal(vector<CandidatesCum> aComparerPourEgalite){

//     vector<CandidatesCum> equalityCandidates;
//     for (size_t i = 0 ; i < aComparerPourEgalite.size() ; i++) {
        
//         equalityCandidates.push_back(aComparerPourEgalite[0]);

//         if (aComparerPourEgalite[i].getPointCollected() == aComparerPourEgalite[i + 1].getPointCollected()) {
//             equalityCandidates.push_back(aComparerPourEgalite[i+1]);
//         }
//     }
// }


//fonction qui donne le nom du candidat qui a obtenue le plus de points 
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

int main()
{
    //Mes vecteurs électeur et candidats
    vector<VotersCum> VectorVoters;
    vector<CandidatesCum> VectorCandidates;

    //Appel des fonctions pour manipuler mes vecteurs
    vector <VotersCum> a = createVoters(VectorVoters);
    vector <CandidatesCum> b = createCandidate(VectorCandidates);
    vector<CandidatesCum> win = collectVotes(a, b);
    isWinnerName(win);
    return 0;
}
