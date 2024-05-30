#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

vector<pair<int,pair<int,pair<int,string> > > > vec;

bool comp(pair<int,pair<int,pair<int,string> > > a, pair<int,pair<int,pair<int,string> > > b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            if(a.second.second.first == b.second.second.first)
                return a.second.second.second < b.second.second.second;
            return a.second.second.first > b.second.second.first;
        }
        return a.second.first < b.second.first;
    }
    return a.first > b.first;
}

int main(void)
{
    cin.tie(NULL);

    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        string name;
        int korean, english, math;

        cin >> name >> korean >> english >> math;
        vec.push_back(make_pair(korean,make_pair(english,make_pair(math,name))));
    }

    sort(vec.begin(),vec.end(),comp);

    for(int i=0;i<N;i++)
        cout << vec[i].second.second.second << "\n";
    return 0;
}