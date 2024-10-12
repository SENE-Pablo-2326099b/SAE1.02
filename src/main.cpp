#include <iostream>
#include <vector>
#include "../include/classElecteur.hpp"
#include "../include/classCandidats.hpp"
using namespace std;   



// electeurs::electeurs(int id, int pointADistribuer){
//     this->id = id;
//     this->pointADistribuer = pointADistribuer;
// }

// electeurs elecX(0, 100);
// vector<electeurs> electeursListeTableau;

// void creerElecteurs(){
    
//     int nbElecteurs = 0;
//     int id = 0;
//     while (nbElecteurs < 5) {
//         electeursListeTableau.push_back(electeurs(0,100));
//         nbElecteurs++;
//         // https://openclassrooms.com/forum/sujet/creer-plusieurs-constructeurs-avec-une-boucle-for
//     }

// }


// void voteCumulatif(){

//     int point = 100;
//     int nombreDePointADistribuer;

//     int candidat1 = 0;
//     int candidat2= 0;
//     int candidat3= 0;
    
//     string choixElecteur ;
//     bool gagnantVote = false;
    
//     bool aVoter = false;
    
//     cout << "Veuillez choisir comment vous repartiser vos points en selectionnant entre " << endl
//          << "Candidat 1" << '\t' << "Candidat 2" << '\t' << "Candidat 3" << endl;

//     while (point > 0) {
        
//         cin >> choixElecteur; cout << "choix electeur" << endl;
        
//         if (choixElecteur == "candidat 1" || choixElecteur == "candidat1" || choixElecteur == "Candidat 1" || choixElecteur == "Candidat1") {
//             cout << "Veuillez choisir le nombre de points a donner au candidat numéro 1" << endl;
//             cin >> nombreDePointADistribuer;
//             candidat1 += nombreDePointADistribuer;
//             point = point - nombreDePointADistribuer;
//         }
        
//         else if (choixElecteur == "candidat 2" || choixElecteur == "candidat2" || choixElecteur == "Candidat 2" || choixElecteur == "Candidat2") {
//             cout << "Veuillez choisir le nombre de points a donner au candidat numéro 2" << endl;
//             cin >> nombreDePointADistribuer;
//             candidat2 += nombreDePointADistribuer;
//             point = point - nombreDePointADistribuer;
//         }
        
//         else if (choixElecteur == "candidat 3" || choixElecteur == "candidat3" || choixElecteur == "Candidat 3" || choixElecteur == "Candidat3") {
//             cout << "Veuillez choisir le nombre de points a donner au candidat numéro 3" << endl;
//             cin >> nombreDePointADistribuer;
//             candidat3 += nombreDePointADistribuer;
//             point = point - nombreDePointADistribuer;
//         }
//     }   

//     aVoter = true;

//     if (candidat3 > candidat2 && candidat3 > candidat1) {
//         gagnantVote = true;
//         cout << "Le gagnant est candidat 3" << endl;
//     }

//     else if (candidat2 > candidat1 && candidat2 > candidat3) {
//         gagnantVote = true;
//         cout << "Le gagnant est candidat 2" << endl;

//     }
    
//     else if (candidat1 > candidat3 && candidat1 > candidat2) {
//         gagnantVote = true;
//         cout << "Le gagnant est candidat 1" << endl;

//     }
//     // cout << "Le candidat ayant obtenue le plus de votes est le candidat " << gagnantVote << endl;
// }
    




// int main(){
//     // int i = 0;
//     // while (i < 5) {
//     // // creerElecteurs();
//     // cout << "Id de l'électeur : "<< elecX.getId() << endl;
//     // cout << "Nombre de points de l'électeur : "<< elecX.getPoints() << endl;
//     // }
//     voteCumulatif();
// }


int numberCandidate;


void createCandidate()
{
    cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl;
    cin >> numberCandidate;
    cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    Candidat tabCandidat[numberCandidate];

    for(int i = 0; i <= numberCandidate; i++)
    {
        tabCandidat[i].setName();
        cout << endl << endl << endl << endl << endl << endl;
        tabCandidat[i].getName();
    }
}

void createVoters()
{
    cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :" << endl;
    int numberVoters;
    cin >> numberVoters;
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl;
    Electeurs tabVotersPoint[numberVoters];

    cout << "Choisisez le nombre de points que chaque électeurs détient : " << endl;
    int pointToDistribute = 0;
    cin >> pointToDistribute;
    for(int i = 0; i <= numberVoters; i++)
    {
        tabVotersPoint[i].SetPoint(pointToDistribute) ;
    }
    
    cout << "Les electeurs ont " << pointToDistribute << " points a distribuer entre " << numberCandidate << " candidats" << endl;
    
}


// https://electionbuddy.com/blog/2022/02/18/understanding-the-cumulative-voting-formula/
// https://electionbuddy.com/features/voting-systems/cumulative-voting/

int main()
{

    createCandidate();
    createVoters();

}



// A FAIRE : Utiliser des verteurs au lieu des tableau pour changer la taille sans tout casser 

