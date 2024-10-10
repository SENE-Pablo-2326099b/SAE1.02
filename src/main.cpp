#include <iostream>
#include <vector>
#include "../include/classElecteur.hpp"
#include "../include/classCandidats.hpp"
using namespace std;   



electeurs::electeurs(int id, int pointADistribuer){
    this->id = id;
    this->pointADistribuer = pointADistribuer;
}

electeurs elecX(0, 100);
vector<electeurs> electeursListeTableau;

void creerElecteurs(){
    
    int nbElecteurs = 0;
    int id = 0;
    while (nbElecteurs < 5) {
        electeursListeTableau.push_back(electeurs(0,100));
        nbElecteurs++;
        // https://openclassrooms.com/forum/sujet/creer-plusieurs-constructeurs-avec-une-boucle-for
    }




}


int main(){
    int i = 0;
    while (i < 5) {
    creerElecteurs();
    cout << "Id de l'électeur : "<< elecX.getId() << endl;
    cout << "Nombre de points de l'électeur : "<< elecX.getPoints() << endl;
    }
}

