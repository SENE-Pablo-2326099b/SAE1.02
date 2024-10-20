#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;


/* ------------------------------------------- Vote Cumulatif ------------------------------------------- */

//Fonction qui permet de créer et d'initialiser les candidats.
vector<CandidatesCum> createCandidateCum(vector<CandidatesCum> VectorCandidates)
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
vector<VotersCum> createVotersCum(vector<VotersCum>VectorVoters)
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
vector<CandidatesCum> collectVotesCum(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates)
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

/*string isWinnerNameCum(vector<CandidatesCum> vectorCandidatesWin)
{
    string winnerName;
    int winnerPoints = 0;
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

    for (size_t res = 0; res < vectorCandidatesWin.size(); res++) {
        if (vectorCandidatesWin[res].getPointCollected() > winnerPoints) {
            winnerPoints = vectorCandidatesWin[res].getPointCollected();
            winnerName = vectorCandidatesWin[res].getName();
        }
    }
    cout << "Le candidat " << winnerName << " gagne avec " << winnerPoints << " points" << endl ;
    return winnerName;
}*/

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

    return 0;
}

