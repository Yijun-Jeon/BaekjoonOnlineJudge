#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <sstream>

#define MAX_N 100

using namespace std;

int lengths[MAX_N];
int counts[MAX_N];

int main(void)
{
    unordered_map<string,pair<int,int> > map;

    int N;
    cin >> N;
    getchar();

    
    for(int i=0;i<N;i++){
        string S;
        getline(cin,S);

        stringstream ss(S);
        string word;

        while(ss >> word)
            map[word] = make_pair(i,lengths[i]++);
    }

    string L;
    getline(cin,L);

    stringstream ss(L);
    string word;

    bool valid = true;
    while(valid && ss >> word){
        if(map.find(word) == map.end())
            valid = false;

        pair<int,int> pos = map[word];
        if(pos.second != counts[pos.first])
            valid = false;

        counts[pos.first]++;
    }

    for(int i=0;i<N && valid;i++){
        if(counts[i] != lengths[i])
            valid = false;
    }

    if(valid) cout << "Possible" << '\n';
    else cout << "Impossible" << '\n';

    return 0;
}