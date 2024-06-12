#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<string,int> a, pair<string,int> b){
    if(a.second == b.second){
        if(a.first.size() == b.first.size())
            return a.first < b.first;
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    unordered_map<string,int> map;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;

        if(s.size() < M)
            continue;

        if(map.find(s) == map.end())
            map[s] = 1;
        else map[s]++;
    }

    vector<pair<string,int> > result;
    for(auto iter = map.begin(); iter != map.end(); iter++)
        result.push_back(*iter);

    sort(result.begin(),result.end(),comp);

    for(int i=0;i<result.size();i++)
        cout << result[i].first << '\n';
    return 0;
}