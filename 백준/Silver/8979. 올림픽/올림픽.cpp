#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    vector<pair<int,pair<int,pair<int,int> > > > vec(N);

    for(int i=0;i<N;i++){
        int num,g,s,b;
        scanf("%d %d %d %d",&num,&g,&s,&b);

        vec.push_back(make_pair(g,make_pair(s,make_pair(b,num))));
    }

    sort(vec.begin(),vec.end(), greater<pair<int,pair<int,pair<int,int> > > >());

    int result = 0;
    int lastG = -1, lastS = -1, lastB = -1;
    for(int i=0;i<N;i++){
        auto now = vec[i];
        
        if(lastG != now.first || lastS != now.second.first || lastB != now.second.second.first)
            result = i+1;

        if(now.second.second.second == K)
            break;

        lastG = now.first;
        lastS = now.second.first;
        lastB = now.second.second.first;
    }
    printf("%d\n",result);
    return 0;
}