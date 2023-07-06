#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    pair<int,int> points[N];
    for(int i=0;i<N;i++){
        cin >> points[i].first;
        points[i].second = i;
    }
    sort(points,points+N);
    
    int idx = 1;
    int last = points[0].first;
    for(int i=0;i<N;i++){
        if(points[i].first == last)
            idx--;
        last = points[i].first;
        points[i].first = idx++;
    }
    
    sort(points,points+N,comp);
    for(int i=0;i<N;i++)
        cout << points[i].first << ' ';
    cout << '\n';
    return 0;
}