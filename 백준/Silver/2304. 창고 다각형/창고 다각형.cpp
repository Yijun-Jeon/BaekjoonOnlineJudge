#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    vector<pair<int,int> > vec(N);
    for(int i=0;i<N;i++){
        int L,H;
        scanf("%d %d",&L,&H);

        vec[i] = make_pair(L,H);
    }

    sort(vec.begin(),vec.end());

    int result = 0;
    int maxLeft = vec[0].second;
    int last = vec[0].first;
    for(int i=1;i<N;i++){
        int maxRight = 0;
        for(int j=i+1;j<N;j++)
            maxRight = max(maxRight,vec[j].second);

        if(maxLeft <= vec[i].second){
            result += (vec[i].first - last) * maxLeft;
            maxLeft = vec[i].second;
            last = vec[i].first;
        }

        if(maxLeft > maxRight){
            result += maxLeft - maxRight;
            maxLeft = maxRight;
        }
    }

    if(N == 1) result += vec[0].second;

    printf("%d\n",result);
    return 0;
}