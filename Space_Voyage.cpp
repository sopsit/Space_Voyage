#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli n, m;
vector<vector<int>> mapp;
vector<pair<int, int>> for4(2); // save 4's
struct logg
{
    
    string side;
    lli energy;
    lli time=0;
};
struct SpaceCraft
{
    int FirstEnergy;
    pair<int , int> coordinate;
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

void ride()
{
    pair<int , int> temp;
    temp.first=Fallcon.coordinate.first;
    temp.second=Fallcon.coordinate.second;
    string direction="";
    while(1)
    {
        if(temp.first - 1 >= 0 && mapp[temp.first - 1 ][temp.second]==2  && direction!="d")
        {
            direction="u"; temp.first=temp.first - 1;
        }
         else if(temp.first + 1 < n && mapp[temp.first + 1 ][temp.second]==2  && direction!="u")
        {
            direction="d"; temp.first=temp.first + 1;
        }
        else if(temp.second - 1 >= 0  && mapp[temp.first][temp.second - 1]==2  && direction!="r")
        {
            direction ="l"; temp.second=temp.second - 1;
        }
        else if(temp.second + 1 < m  && mapp[temp.first][temp.second + 1]==2  && direction!="l")
        {
            direction ="r"; temp.second=temp.second + 1;
        }
        else if(temp.first - 1 >= 0 && mapp[temp.first - 1 ][temp.second]==1  && direction!="d")
        {
            direction="u"; temp.first=temp.first - 1;
        }
         else if(temp.first + 1 < n && mapp[temp.first + 1 ][temp.second]==1  && direction!="u")
        {
            direction="d"; temp.first=temp.first + 1;
        }
        else if(temp.second - 1 >= 0  && mapp[temp.first][temp.second - 1]==1  && direction!="r")
        {
            direction ="l"; temp.second=temp.second - 1;
        }
        else if(temp.second + 1 < m  && mapp[temp.first][temp.second + 1]==1  && direction!="l")
        {
            direction ="r"; temp.second=temp.second + 1;
        }
        
        if(mapp[temp.first][temp.second]==1)
        {
            Fallcon.coordinate.first=temp.first;
            Fallcon.coordinate.second=temp.second;
            break;
        }
    } 
}

bool found_1()
{
    logg temp; bool flag=false;
    if(Fallcon.coordinate.first - 1 >=0 && 
    mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second]==5)
    {
        Fallcon.coordinate.first=Fallcon.coordinate.first - 1;
         temp.side="UP"; flag=true;
    }
    else if(Fallcon.coordinate.first + 1 < n && 
    mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second]==5)
    {
        Fallcon.coordinate.first=Fallcon.coordinate.first + 1;
        temp.side="DOWN"; flag=true;
    }
    else if(Fallcon.coordinate.second - 1 >=0 && 
    mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1]==5)
    {
        Fallcon.coordinate.second=Fallcon.coordinate.second - 1;
        temp.side="LEFT"; flag=true;
    }
    else if(Fallcon.coordinate.second + 1 < m && 
    mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1]==5)
    {
        Fallcon.coordinate.second=Fallcon.coordinate.second + 1;
        temp.side="RIGHT"; flag=true;
    }
    if(flag)
    {
    lli size=Fallcon.listOfMove.size();
    if(size==0)
    {
        temp.energy=Fallcon.FirstEnergy;
    }
    else
    {
        temp.energy=Fallcon.listOfMove[size-1].energy;
    }
    Fallcon.listOfMove.push_back(temp);
    }
    return flag;
}

bool found_2()
{
    pair<int , int > temp; bool flag=false; logg tmp;
    temp.first=Fallcon.coordinate.first; temp.second=Fallcon.coordinate.second;
    if((temp.first - 1)>=0 && (temp.second + 1 < m) && 
       mapp[temp.first - 1][temp.second + 1]==5)
       {
         if(mapp[temp.first-1][temp.second]!=2 && mapp[temp.first-1][temp.second]!=3)
         {
            Fallcon.coordinate.first=temp.first - 1; flag=true; tmp.side="UP";
         }
         else if(mapp[temp.first][temp.second + 1]!=2 && mapp[temp.first][temp.second + 1]!=3)
         {
            Fallcon.coordinate.second=temp.second + 1; flag=true; tmp.side="RIGHT";
         }
       }
    else if((temp.first - 1)>=0 && (temp.second -1 >=0) && 
       mapp[temp.first - 1][temp.second - 1]==5)
       {
         if(mapp[temp.first-1][temp.second]!=2 && mapp[temp.first-1][temp.second]!=3)
         {
            Fallcon.coordinate.first=temp.first - 1; flag=true; tmp.side="UP";
         }
         else if(mapp[temp.first][temp.second - 1]!=2 && mapp[temp.first][temp.second - 1]!=3)
         {
            Fallcon.coordinate.second=temp.second - 1; flag=true; tmp.side="LEFT";
         }
       }
    else if((temp.first + 1) < n && (temp.second - 1 >=0) && 
       mapp[temp.first + 1][temp.second - 1]==5)
       {
         if(mapp[temp.first + 1][temp.second]!=2 && mapp[temp.first+1][temp.second]!=3)
         {
            Fallcon.coordinate.first=temp.first + 1; flag=true; tmp.side="DOWN";
         }
         else if(mapp[temp.first][temp.second - 1]!=2 && mapp[temp.first][temp.second - 1]!=3)
         {
            Fallcon.coordinate.second=temp.second - 1; flag=true; tmp.side="LEFT";
         }
       }
    else if((temp.first + 1 < n) && (temp.second + 1 < m) && 
       mapp[temp.first + 1][temp.second + 1]==5)
       {
         if(mapp[temp.first+1][temp.second]!=2 && mapp[temp.first+1][temp.second]!=3)
         {
            Fallcon.coordinate.first=temp.first + 1; flag=true; tmp.side="DOWN";
         }
         else if(mapp[temp.first][temp.second + 1]!=2 && mapp[temp.first][temp.second + 1]!=3)
         {
            Fallcon.coordinate.second=temp.second + 1; flag=true; tmp.side="RIGHT";
         }
       }
     if(flag)
    {
    lli size=Fallcon.listOfMove.size();
    if(size==0){tmp.energy=Fallcon.FirstEnergy;}
    else{tmp.energy=Fallcon.listOfMove[size-1].energy;}
    Fallcon.listOfMove.push_back(tmp);
    }
    return flag;
}
int main()
{

    lli  t, countf = 0;
    cin >> n >> m;
    lli energ, row, column;
    cin >> row >> column >> energ;
    Fallcon.coordinate.first = row;
    Fallcon.coordinate.second = column;
    Fallcon.FirstEnergy = energ;
    for (int i = 0 ; i < n ; i++)
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
        }
    }
    
   cout<<"\n";
   //ride();
   cout<<found_2()<<"\n";
   /* for(int i=0 ; i< n  ; i++)
    {
        for (int j=0 ; j< m ; j++)
        {
            cout<<mapp[i][j]<<" ";
        }
        cout<<endl;
    }*/
   
    for(int i=0 ; i < Fallcon.listOfMove.size() ; i++)
    {
        cout<<Fallcon.listOfMove[i].energy<<" "<<Fallcon.listOfMove[i].side<<endl;
    }
   // cout<<for4[0].first<<" "<<for4[0].second<<"\n";
   // cout<<for4[1].first<<" "<<for4[1].second<<"\n";
   
    cout<<Fallcon.coordinate.first<<" "<<Fallcon.coordinate.second<<"\n";
    
   
    
    

}