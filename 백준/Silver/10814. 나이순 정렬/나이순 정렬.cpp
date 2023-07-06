#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int,string> p1, pair<int,string> p2){
    return p1.first < p2.first;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<pair<int,string> > members(N);
    for(int i=0;i<N;i++)
        cin >> members[i].first >> members[i].second;

    stable_sort(members.begin(),members.end(),comp);
    for(int i=0;i<N;i++)
        cout << members[i].first << ' ' << members[i].second << '\n';
    return 0;
}