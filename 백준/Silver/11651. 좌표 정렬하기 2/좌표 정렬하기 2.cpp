#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second)
        return true;
    else if(p1.second > p2.second)
        return false;
    else{
        return p1.first < p2.first;
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int,int> > points(N);
    for(int i=0;i<N;i++)
        cin >> points[i].first >> points[i].second;

    sort(points.begin(),points.end(),comp);
    for(int i=0;i<N;i++)
        cout << points[i].first << ' ' << points[i].second << '\n';
    return 0;
}