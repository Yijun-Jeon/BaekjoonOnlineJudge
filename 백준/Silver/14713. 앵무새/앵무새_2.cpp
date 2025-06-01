#include <iostream>
#include <stdio.h>
#include <sstream>
#include <queue>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    getchar();

    queue<string> birds[N];
    for(int i=0;i<N;i++){
        string S;
        getline(cin,S);

        stringstream ss(S);
        string word;

        while(ss >> word)
            birds[i].push(word);
    }

    string L;
    getline(cin,L);

    stringstream ss(L);
    string word;

    bool valid = true;
    while(valid && ss >> word){
        bool found = false;
        for(int i=0;i<N;i++){
            if(birds[i].front() == word){
                birds[i].pop();
                found = true;
                break;
            }
        }

        valid = found;
    }

    for(int i=0;i<N;i++)
        valid &= birds[i].empty();

    if(valid) cout << "Possible" << '\n';
    else cout << "Impossible" << '\n';
    return 0;
}