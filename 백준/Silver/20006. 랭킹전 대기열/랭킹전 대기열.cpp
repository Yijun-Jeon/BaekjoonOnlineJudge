#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int P,M;
vector<vector<pair<string,int> > > rooms;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> P >> M;
    for(int i=0;i<P;i++){
        int l;
        string n;

        cin >> l >> n;

        bool entered = false;
        for(int j=0;j<rooms.size();j++){
            if(abs(rooms[j][0].second-l) <= 10 && rooms[j].size() < M){
                rooms[j].push_back(make_pair(n,l));
                entered = true;
                break;
            }
        }

        if(!entered){
            vector<pair<string,int> > room;
            room.push_back(make_pair(n,l));
            rooms.push_back(room);
        }

    }

    for(int i=0;i<rooms.size();i++){
        sort(rooms[i].begin(),rooms[i].end());
        if(rooms[i].size() == M)
            cout << "Started!" << '\n';
        else
            cout << "Waiting!" << '\n';

        for(int j=0;j<rooms[i].size();j++)
            cout << rooms[i][j].second << " " << rooms[i][j].first << '\n';
    }
    return 0;
}