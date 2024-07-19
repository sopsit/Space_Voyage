#include <bits/stdc++.h>
#define lli long long int

using namespace std;

vector<vector<int>> mapp;
vector<pair<int, int>> for4(2); // save 4's
pair<int, int> for5;
struct logg
{
    string side;
    lli energy;
    lli time;
};
struct SpaceCraft
{
    int FirstEnergy;
    pair<int, int> coordinate;
    vector<logg> listOfMove;
};

SpaceCraft Fallcon;

void Teleport() // defects: calculatin  of energy and writing in logg
{
    if (Fallcon.coordinate.first == for4[0].first)
    {
        Fallcon.coordinate.first = for4[1].first;
        Fallcon.coordinate.second = for4[1].second;
    }
    else if (Fallcon.coordinate.first == for4[1].first)
    {
        Fallcon.coordinate.first = for4[0].first;
        Fallcon.coordinate.second = for4[0].second;
    }
}

void orbit(string side)// defects: calculatin  of energy and writing in logg
{
    if (side == "up")
    {
        Fallcon.coordinate.first -= 3;
    }
    else if (side == "down")
    {
        Fallcon.coordinate.first += 3;
    }
    else if (side == "right")
    {
        Fallcon.coordinate.second += 3;
    }
    else if (side == "left")
    {
        Fallcon.coordinate.second -= 3;
    }
}

int main()
{

    lli n, m, t, countf = 0;
    cin >> n >> m;
    lli energ, row, column;
    cin >> row >> column >> energ;
    Fallcon.coordinate.first = row;
    Fallcon.coordinate.second = column;
    Fallcon.FirstEnergy = energ;
    for (int i = 0; i < n; i++)
    {
        mapp.push_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            mapp[i].push_back(t);
            if (t == 4)
            {
                for4[countf].first = i;
                for4[countf].second = j;
                countf++;
            }
            else if (t == 5)
            {
                for5.first = i;
                for5.second = j;
            }
        }
    }
}