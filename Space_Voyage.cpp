#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli n, m;
vector<vector<int>> mapp;
vector<pair<int, int>> for4(2); // save 4's
struct logg
{
    logg() {}
    logg(string SIDE, lli en = 0, lli Timee = 0) : side(SIDE), energy(en), time(Timee) {}
    string side;
    lli energy = 0;
    lli time = 0;
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

void orbit(string side) // defects: calculatin  of energy and writing in logg
{
    if (side == "up")
    {
        Fallcon.coordinate.first -= 3;
        Fallcon.listOfMove.push_back(logg("UP", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 4, Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 3));
    }
    else if (side == "down")
    {
        Fallcon.coordinate.first += 3;
        Fallcon.listOfMove.push_back(logg("DOWN", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 4, Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 3));
    }
    else if (side == "right")
    {
        Fallcon.coordinate.second += 3;
        Fallcon.listOfMove.push_back(logg("RIGHT", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 4, Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 3));
    }
    else if (side == "left")
    {
        Fallcon.coordinate.second -= 3;
        Fallcon.listOfMove.push_back(logg("LEFT", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 4, Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 3));
    }
}

void ride()
{
    pair<int, int> temp;
    temp.first = Fallcon.coordinate.first;
    temp.second = Fallcon.coordinate.second;
    string direction = "";
    while (1)
    {
        if (temp.first - 1 >= 0 && mapp[temp.first - 1][temp.second] == 2 && direction != "d")
        {
            direction = "u";
            temp.first = temp.first - 1;
        }
        else if (temp.first + 1 < n && mapp[temp.first + 1][temp.second] == 2 && direction != "u")
        {
            direction = "d";
            temp.first = temp.first + 1;
        }
        else if (temp.second - 1 >= 0 && mapp[temp.first][temp.second - 1] == 2 && direction != "r")
        {
            direction = "l";
            temp.second = temp.second - 1;
        }
        else if (temp.second + 1 < m && mapp[temp.first][temp.second + 1] == 2 && direction != "l")
        {
            direction = "r";
            temp.second = temp.second + 1;
        }
        else if (temp.first - 1 >= 0 && mapp[temp.first - 1][temp.second] == 1 && direction != "d")
        {
            direction = "u";
            temp.first = temp.first - 1;
        }
        else if (temp.first + 1 < n && mapp[temp.first + 1][temp.second] == 1 && direction != "u")
        {
            direction = "d";
            temp.first = temp.first + 1;
        }
        else if (temp.second - 1 >= 0 && mapp[temp.first][temp.second - 1] == 1 && direction != "r")
        {
            direction = "l";
            temp.second = temp.second - 1;
        }
        else if (temp.second + 1 < m && mapp[temp.first][temp.second + 1] == 1 && direction != "l")
        {
            direction = "r";
            temp.second = temp.second + 1;
        }

        if (mapp[temp.first][temp.second] == 1)
        {
            Fallcon.coordinate.first = temp.first;
            Fallcon.coordinate.second = temp.second;
            break;
        }
    }
}

bool found_1()
{
    logg temp;
    bool flag = false;
    if (Fallcon.coordinate.first - 1 >= 0 &&
        mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second] == 5)
    {
        Fallcon.coordinate.first = Fallcon.coordinate.first - 1;
        temp.side = "UP";
        flag = true;
    }
    else if (Fallcon.coordinate.first + 1 < n &&
             mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second] == 5)
    {
        Fallcon.coordinate.first = Fallcon.coordinate.first + 1;
        temp.side = "DOWN";
        flag = true;
    }
    else if (Fallcon.coordinate.second - 1 >= 0 &&
             mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1] == 5)
    {
        Fallcon.coordinate.second = Fallcon.coordinate.second - 1;
        temp.side = "LEFT";
        flag = true;
    }
    else if (Fallcon.coordinate.second + 1 < m &&
             mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1] == 5)
    {
        Fallcon.coordinate.second = Fallcon.coordinate.second + 1;
        temp.side = "RIGHT";
        flag = true;
    }
    if (flag)
    {
        lli size = Fallcon.listOfMove.size();
        if (size == 0)
        {
            temp.energy = Fallcon.FirstEnergy;
        }
        else
        {
            temp.energy = Fallcon.listOfMove[size - 1].energy;
        }
        Fallcon.listOfMove.push_back(temp);
    }
    return flag;
}

void come_back()
{
    for (lli i=Fallcon.listOfMove.size()-1 ; i > 0 ; i--)
    {
        if (Fallcon.listOfMove[i].side == "DOWN")
        {
            if (mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second] == 3)
            {
                orbit("up");
            }
            else
            {
                Fallcon.coordinate.first = Fallcon.coordinate.first - 1;
                Fallcon.listOfMove.push_back(logg("UP"));
            }
        }
      else if (Fallcon.listOfMove[i].side == "UP")
        {
            if (mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second] == 3)
            {
                orbit("down");
            }
            else
            {
                Fallcon.coordinate.first = Fallcon.coordinate.first + 1;
                Fallcon.listOfMove.push_back(logg("DOWN"));
            }
        }
    else if (Fallcon.listOfMove[i].side == "RIGHT")
        {
            if (mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1] == 3)
            {
                orbit("left");
            }
            else
            {
                Fallcon.coordinate.second = Fallcon.coordinate.second - 1;
                Fallcon.listOfMove.push_back(logg("LEFT"));
            }
        }
    else if (Fallcon.listOfMove[i].side == "LEFT")
        {
            if (mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1] == 3)
            {
                orbit("right");
            }
            else
            {
                Fallcon.coordinate.second= Fallcon.coordinate.second + 1;
                Fallcon.listOfMove.push_back(logg("RIGHT"));
            }
        }
    }
    cout<<"com back \n";

}

bool found_2()
{
    pair<int, int> temp;
    bool flag = false;
    logg tmp;
    temp.first = Fallcon.coordinate.first;
    temp.second = Fallcon.coordinate.second;
    if ((temp.first - 1) >= 0 && (temp.second + 1 < m) &&
        mapp[temp.first - 1][temp.second + 1] == 5)
    {
        if (mapp[temp.first - 1][temp.second] != 2 && mapp[temp.first - 1][temp.second] != 3)
        {
            Fallcon.coordinate.first = temp.first - 1;
            flag = true;
            tmp.side = "UP";
        }
        else if (mapp[temp.first][temp.second + 1] != 2 && mapp[temp.first][temp.second + 1] != 3)
        {
            Fallcon.coordinate.second = temp.second + 1;
            flag = true;
            tmp.side = "RIGHT";
        }
    }
    else if ((temp.first - 1) >= 0 && (temp.second - 1 >= 0) &&
             mapp[temp.first - 1][temp.second - 1] == 5)
    {
        if (mapp[temp.first - 1][temp.second] != 2 && mapp[temp.first - 1][temp.second] != 3)
        {
            Fallcon.coordinate.first = temp.first - 1;
            flag = true;
            tmp.side = "UP";
        }
        else if (mapp[temp.first][temp.second - 1] != 2 && mapp[temp.first][temp.second - 1] != 3)
        {
            Fallcon.coordinate.second = temp.second - 1;
            flag = true;
            tmp.side = "LEFT";
        }
    }
    else if ((temp.first + 1) < n && (temp.second - 1 >= 0) &&
             mapp[temp.first + 1][temp.second - 1] == 5)
    {
        if (mapp[temp.first + 1][temp.second] != 2 && mapp[temp.first + 1][temp.second] != 3)
        {
            Fallcon.coordinate.first = temp.first + 1;
            flag = true;
            tmp.side = "DOWN";
        }
        else if (mapp[temp.first][temp.second - 1] != 2 && mapp[temp.first][temp.second - 1] != 3)
        {
            Fallcon.coordinate.second = temp.second - 1;
            flag = true;
            tmp.side = "LEFT";
        }
    }
    else if ((temp.first + 1 < n) && (temp.second + 1 < m) &&
             mapp[temp.first + 1][temp.second + 1] == 5)
    {
        if (mapp[temp.first + 1][temp.second] != 2 && mapp[temp.first + 1][temp.second] != 3)
        {
            Fallcon.coordinate.first = temp.first + 1;
            flag = true;
            tmp.side = "DOWN";
        }
        else if (mapp[temp.first][temp.second + 1] != 2 && mapp[temp.first][temp.second + 1] != 3)
        {
            Fallcon.coordinate.second = temp.second + 1;
            flag = true;
            tmp.side = "RIGHT";
        }
    }
    if (flag)
    {
        lli size = Fallcon.listOfMove.size();
        if (size == 0)
        {
            tmp.energy = Fallcon.FirstEnergy;
        }
        else
        {
            tmp.energy = Fallcon.listOfMove[size - 1].energy;
        }
        Fallcon.listOfMove.push_back(tmp);
    }
    return flag;
}
void go_one_unit(char s)
{
    if (s == 'u' && Fallcon.coordinate.first > 0)
    {
        Fallcon.coordinate.first = Fallcon.coordinate.first - 1;
        Fallcon.listOfMove.push_back(logg("UP", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
         Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
    }
    if (s == 'd' && Fallcon.coordinate.first < n)
    {
        Fallcon.coordinate.first = Fallcon.coordinate.first + 1;
        Fallcon.listOfMove.push_back(logg("DOWN", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
         Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
    }
    if (s == 'r')
    {
        Fallcon.coordinate.second = Fallcon.coordinate.second + 1;
        Fallcon.listOfMove.push_back(logg("RIGHT", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
         Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
    }
    if (s == 'l' )
    {
        Fallcon.coordinate.second = Fallcon.coordinate.second - 1;
        Fallcon.listOfMove.push_back(logg("LEFT", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
         Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
    }
}
void print()
{
    for (lli i = 1 ; i < Fallcon.listOfMove.size(); i++)
    {
        cout << Fallcon.listOfMove[i].side << " " << Fallcon.listOfMove[i].energy << " " << Fallcon.listOfMove[i].time << "\n";
    }
    cout << Fallcon.coordinate.first << " " << Fallcon.coordinate.second << "\n";
}

void com_back_to_up()
{
     for (int i = Fallcon.listOfMove.size() - 1; i > 0; i--)
    {
        if (Fallcon.listOfMove[i].side == "DOWN")
        {
            if (mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second] == 3)
            {
                orbit("up");
            }
            else
            {
                Fallcon.coordinate.first = Fallcon.coordinate.first - 1;
                Fallcon.listOfMove.push_back(logg("UP"));
            }
        }
        else
        {
            break;
        }
    }
}
void com_back_to_down()
{
      for (int i = Fallcon.listOfMove.size() - 1; i > 0; i--)
    {
        if (Fallcon.listOfMove[i].side == "UP")
        {
            if (mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second] == 3)
            {
                orbit("down");
            }
            else
            {
                Fallcon.coordinate.first = Fallcon.coordinate.first + 1;
                Fallcon.listOfMove.push_back(logg("DOWN"));
            }
        }
        else
        {
            break;
        }
    }
  
}
bool go_one_right_1()
{
    bool flag=false;
    if(Fallcon.coordinate.second + 1 < m )
    {
        while((mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1 ]==2 || 
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1]==3 ) && Fallcon.coordinate.first + 1 < n 
        && mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second]!=2)
        {
            if( mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second]==3)
            {
                orbit("down");
            }
            else
            {
               Fallcon.coordinate.first=Fallcon.coordinate.first + 1;
               Fallcon.listOfMove.push_back(logg("DOWN"));
            }
        }

        if(mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1 ]!=2 &&
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1]!=3 )
        {
           go_one_unit('r'); flag=true;

         if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
        }
    }

      return flag; 
}
bool go_one_right_2()
{
    bool flag=false;
    if(Fallcon.coordinate.second + 1 < m )
    {
        while((mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1 ]==2 || 
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1]==3 ) && Fallcon.coordinate.first - 1 >=0 
        && mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second]!=2)
        {
            if( mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second]==3)
            {
                orbit("up");
            }
            else
            {
               Fallcon.coordinate.first=Fallcon.coordinate.first - 1;
               Fallcon.listOfMove.push_back(logg("UP"));
            }
        }

        if(mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1 ]!=2 &&
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1]!=3 )
        {
           go_one_unit('r'); flag=true;

         if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
        }
    }

      return flag; 
}
bool go_one_left_1()
{
    bool flag=false;
    if(Fallcon.coordinate.second - 1 >=0 )
    {
        while((mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1 ]==2 || 
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1]==3 ) && Fallcon.coordinate.first + 1 < n 
        && mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second]!=2)
        {
            if( mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second]==3)
            {
                orbit("down");
            }
            else
            {
               Fallcon.coordinate.first=Fallcon.coordinate.first + 1;
               Fallcon.listOfMove.push_back(logg("DOWN"));
            }
        }

        if(mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1 ]!=2 &&
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1]!=3 )
        {
           go_one_unit('l'); flag=true;

         if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
        }
    }

      return flag; 
}
bool go_one_left_2()
{
    bool flag=false;
    if(Fallcon.coordinate.second - 1 >=0 )
    {
        while((mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1 ]==2 || 
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1]==3 ) && Fallcon.coordinate.first - 1 >=0 
        && mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second]!=2)
        {
            if( mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second]==3)
            {
                orbit("up");
            }
            else
            {
               Fallcon.coordinate.first=Fallcon.coordinate.first - 1;
               Fallcon.listOfMove.push_back(logg("UP"));
            }
        }

        if(mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1 ]!=2 &&
        mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1]!=3 )
        {
           go_one_unit('l'); flag=true;

         if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
        }
    }

      return flag; 
}
void go_down()
{

    while (Fallcon.coordinate.first + 1 < n &&
           mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second] != 2)
    {
        if (mapp[Fallcon.coordinate.first + 1][Fallcon.coordinate.second] == 3)
        {
            orbit("down");
        }
        else
        {
            Fallcon.coordinate.first = Fallcon.coordinate.first + 1;
            Fallcon.listOfMove.push_back(logg("DOWN", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
             Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
        }
        if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
    }
}

void go_up()
{
    while (Fallcon.coordinate.first - 1 >= 0 &&
           mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second] != 2)
    {
        
        if (mapp[Fallcon.coordinate.first - 1][Fallcon.coordinate.second] == 3)
        {
            orbit("up");
        }
        else
        {
            Fallcon.coordinate.first = Fallcon.coordinate.first - 1;
            Fallcon.listOfMove.push_back(logg("UP", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
             Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
        }
        
         if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
    }
}



void go_right()
{

    while (Fallcon.coordinate.second < m && mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1] != 2)
    {
        if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
        if (mapp[Fallcon.coordinate.first][Fallcon.coordinate.second + 1] == 3)
        {
            orbit("right");
        }
        else
        {
            Fallcon.coordinate.second += 1;
            Fallcon.listOfMove.push_back(logg("RIGHT", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
             Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
        }
    }
}
void go_left()
{

    while (Fallcon.coordinate.second > 0 && mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1] != 2)
    {
        if (found_2())
        {
            found_1();
            print();
            exit(0);
        }
        else if (found_1())
        {
            print();
            exit(0);
        }
        if (mapp[Fallcon.coordinate.first][Fallcon.coordinate.second - 1] == 3)
        {
            orbit("left");
        }
        else
        {
            Fallcon.coordinate.second -= 1;
            Fallcon.listOfMove.push_back(logg("LEFT", Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].energy - 1,
             Fallcon.listOfMove[Fallcon.listOfMove.size() - 1].time + 5));
        }
    }
}
void up_right()
{
    while(1)
    {
       go_down();
       com_back_to_up();
       go_up();
       if(!go_one_right_1())
       break;
    }
}

void up_left()
{
    come_back();
    while(1)
    {
       go_down();
       com_back_to_up();
       go_up();
       if(!go_one_left_1())
       break;
    }
}

void down_right()
{
    come_back();
    while(1)
    {
       go_up();
       com_back_to_down();
       go_down();
       if(!go_one_right_2())
       break;
    }
}

void down_left()
{
    come_back();
    while(1)
    {
       go_up();
       com_back_to_down();
       go_down();
       if(!go_one_left_2())
       break;
    }
}
int main()
{

    lli t, countf = 0;
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
        }
    }
    Fallcon.listOfMove.push_back(logg("" , energ , 0));
    cout << "\n";
    // ride();
    // cout<<found_2()<<"\n";
   /* for(int i=0 ; i< n  ; i++)
     {
         for (int j=0 ; j< m ; j++)
         {
             cout<<mapp[i][j]<<" ";
         }
         cout<<endl;
     }*/
    
    up_right();
    up_left();
    down_right();
    down_left();
     print();

    // cout<<for4[0].first<<" "<<for4[0].second<<"\n";
    // cout<<for4[1].first<<" "<<for4[1].second<<"\n";

   // cout << Fallcon.coordinate.first << " " << Fallcon.coordinate.second << "\n";
}
