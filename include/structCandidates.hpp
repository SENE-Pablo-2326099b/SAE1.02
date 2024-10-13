#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CandidatesCum
{
    string Name;
    int PointCollected = 0;
    bool Winner;

    void setName(const string& name)
    {
        Name = name;
    }

    const string getName() const
    {
        return Name;
    }

    void setPointCollected(int& pointCollected)
    {
        PointCollected += pointCollected ;
    }

    int getPointCollected() const
    {
        return PointCollected;
    }

    string isWinner(vector<CandidatesCum> vectorCandidatesWin)
    {
        for (size_t res = 0; res <= vectorCandidatesWin.size(); res++) {
            if (vectorCandidatesWin[res].PointCollected > vectorCandidatesWin[res + 1].PointCollected) {
                string winner;
                winner = vectorCandidatesWin[res].Name;
            }
            // else {
            //     res += 1;
            // }
        }
        
        return Name;
    }
};