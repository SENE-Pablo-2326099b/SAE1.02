#include <iostream>
using namespace std;

class electeurs {

//Attributs
private:
    int id;
    int pointADistribuer;
    bool aVoter = false;
public:
//Constructeur
    electeurs(int id, int pointADistribuer);

//Méthodes
    void distribuerPoints();
    
    int getId() const;  

    int getPoints() const;     

};