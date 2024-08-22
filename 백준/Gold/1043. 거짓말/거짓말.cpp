#include <stdio.h>
#include <vector>

#define MAX_N 50

using namespace std;

int N,M;
bool truth[MAX_N+1];
int parents[MAX_N+1];

int Find(int x){
    if(x == parents[x])
        return x;
    return parents[x] = Find(parents[x]);
}

void Union(int x, int y){
    int parentX = Find(x);
    int parentY = Find(y);

    if(parentX != parentY){
        if(truth[parentY])
            parents[parentX] = parentY;
        else
            parents[parentY] = parentX;
    }
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        parents[i] = i;

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);

        truth[t] = true;
    }

    vector<vector<int> > parties;
    for(int m=0;m<M;m++){
        int people;
        scanf("%d",&people);

        vector<int> party(people);
        bool isTruth = false;
        for(int i=0;i<people;i++){
            scanf("%d",&party[i]);

            if(i==0) continue;

            Union(party[i-1],party[i]);
        }

        parties.push_back(party);
    }

    int result = 0;
    for(int i=0;i<M;i++){
        result++;
        for(int j=0;j<parties[i].size();j++){
            if(truth[Find(parties[i][j])]){
                result--;
                break;
            }
        }
    }
    printf("%d\n",result);
    return 0;
}