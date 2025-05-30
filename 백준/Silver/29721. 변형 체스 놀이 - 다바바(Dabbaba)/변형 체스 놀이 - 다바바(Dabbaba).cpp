#include <iostream>
#include <unordered_map>
#include <vector>

#define MAX_N 100000

using namespace std;

int N,K;

unordered_map<string,bool> chessmen;
unordered_map<string,bool> map;

int rows[4] = {2,-2,0,0};
int cols[4] = {0,0,2,-2};

bool checkPosValid(int row, int col){
    if(row <= 0 || row > N || col <= 0 || col > N)
        return false;
    string pos = to_string(row) + " " + to_string(col);

    if(chessmen.find(pos) != chessmen.end())
        return false;
    if(map.find(pos) != map.end())
        return false;
    return true;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    vector<pair<int,int> > vec(K);
    for(int i=0;i<K;i++){
        cin >> vec[i].first >> vec[i].second;

        chessmen[to_string(vec[i].first) + " " + to_string(vec[i].second)] = true;
    }

    for(int i=0;i<K;i++){
        for(int j=0;j<4;j++){
            int row = vec[i].first + rows[j];
            int col = vec[i].second + cols[j];
            if(checkPosValid(row,col)){
                map[to_string(row) + " " + to_string(col)] = true;
            }
        }
    }

    cout << map.size() << '\n';
    return 0;
}