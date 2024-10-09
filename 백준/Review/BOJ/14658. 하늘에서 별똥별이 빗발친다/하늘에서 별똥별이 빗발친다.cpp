#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{
    int N,M,L,K;
    scanf("%d %d %d %d",&N,&M,&L,&K);

    vector<pair<int,int> > stars(K);
    for(int k=0;k<K;k++)
        scanf("%d %d",&stars[k].first,&stars[k].second);

    sort(stars.begin(),stars.end());

    list<pair<int,int> > li;
    li.push_back(stars[0]);

    int result = 1, idx = 1;
    while(true){
        while(idx < K && stars[idx].first <= li.front().first + L)
            li.push_back(stars[idx++]);

        vector<pair<int,int> > temp(li.begin(),li.end());
        sort(temp.begin(),temp.end(),comp);

        int cnt = 1;
        int yStart = 0;
        for(int i=1;i<temp.size();i++){
            cnt++;
            while(temp[yStart].second + L < temp[i].second){
                yStart++;
                cnt--;
            }
            result = max(result,cnt);
        }
        li.pop_front();

        if(li.empty()){
            if(idx == K)
                break;
            else
                li.push_back(stars[idx++]);
        }
    }
    printf("%d\n",K - result);
    return 0;
}