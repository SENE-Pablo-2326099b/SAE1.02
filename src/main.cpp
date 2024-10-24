// #include <algorithm>
#include <algorithm>
// #include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;   

//Fonction qui permet de créer et d'initialiser les électeurs.
vector<VotersCum> createVotersCum(vector<VotersCum>VectorVoters)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer.
    bool isGood = false;
    int numberVoters;
    //Condition pour verifier si l'entrée utilisateur est correct
    while (isGood == false) 
    {
        cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :" << endl << "--> ";
        cin >> numberVoters;
        
        if (cin.fail()) 
        {   
            cerr << endl << "Error. Veuillez entrez un nombre valide" << endl;
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
        cout << "Choisisez le nombre de points que chaque électeurs détient :" << endl << "--> ";
        cin >> pointsDistributed;

        if (cin.fail()) 
        {
            cerr << endl << "Error. Veuillez entrez un nombre valide" << endl;
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
    cout << endl;
    for (int i = 0; i <= numberVoters - 1; i++)
    {
        cout << "L'électeur " << i + 1 << " à " << VectorVoters[i].GetPoint() << " points" << endl;
    }
    cout << endl;
        
    return VectorVoters;
}



//Fonction qui permet de créer et d'initialiser les candidats.
vector<CandidatesCum> createCandidateCum(vector<CandidatesCum> VectorCandidates)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer
    bool isGood = false;
    int numberCandidate;
    while (isGood == false) {
        cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << "--> ";
        cin >> numberCandidate;
        cin.ignore();
    
        if (cin.fail()) 
        {
            cerr << endl << "Error. Veuillez entrez un nombre valide" << endl;
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

        cout << endl << "Quelle est le nom du " << i + 1 << " candidat ? " << endl;
        getline(cin, name);
        
        if(name.empty() || name == " " || name == "\t" || name == "\n")
        {
            cerr << "Veuillez entrée un nom valide ! " << endl;
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
vector<CandidatesCum> collectVotesCum(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates)
{
    int pointCollected;
        // On parcour vectorVoters 
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

            // Conditionn pour vérifier que l'entrée cin est bien un chiffre valable et             AFAIREEEEEE Pas finis pablo occupe toi en
            if (pointCollected <= 0 ) 
            {
                cerr << "Vous ne pouvez pas donner des points négatif ! " << endl;
                goto labelPointsAdonner;
                
            }

            else if (vectorVoters[v].pointsDistributed < pointCollected) 
            {
                cerr << "Vous ne pouvez pas donnez plus de points que vous n'en possédez ! " << endl;
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
string isWinnerNameCum(vector<CandidatesCum> vectorCandidatesWin)
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

/* ------------------------------------------- Vote Alternatif ------------------------------------------- */


vector<CandidatesAlt> createCandidateAlt(vector<CandidatesAlt> VectorCandidates)
{
    //Enregistrement du nombre de candidats que l'on souhaite créer
    cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << ": ";
    int numberCandidate;
    cin >> numberCandidate;

    //Initialisation d'un vector qui contient les candidats
    cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    //Initialiser le nom des candidats.
    for(int i = 0; i < numberCandidate; ++i)
    {
        string name;
        cout << "Quelle est le nom du " << i + 1 << " candidat ? " << endl;
        cin >> name ;
        VectorCandidates[i].setName(name);
        cout << endl << endl;
    }
    for (int i = 0; i < numberCandidate; ++i)
    {
        cout << "Le candidat numéro " << i + 1 << " se nomme " << VectorCandidates[i].getName() << endl;
    }

    return VectorCandidates;
}

vector<VotersAlt> createVotersAlt(vector<VotersAlt>VectorVoters)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer.
    cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :";
    int numberVoters;
    cin >> numberVoters;
    cout << endl;
    
    //Initialisation d'un vector qui contient les électeurs
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl;
    VectorVoters.resize(numberVoters);

    return VectorVoters;
}

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

vector<CandidatesAlt> countVotesAlt(vector<VotersAlt> vectorVoters, vector<CandidatesAlt> vectorCandidates)
{
    // vectorVoters 
    for (size_t v = 0; v < vectorVoters.size() ; ++v)
    {
        cout << "\n\n\n\n\n\n\n";
        for(size_t c = 0; c < vectorCandidates.size() ; ++c)
        {
            if (vectorVoters[v].getVote() == vectorCandidates[c].getName())
            {
                vectorCandidates[c].Vote += 1;
            }
        }
    }
    return vectorCandidates;
}

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
