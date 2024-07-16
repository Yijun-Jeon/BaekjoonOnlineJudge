#include <stdio.h>

#define MAX_N 1000

using namespace std;

int N,M;
int parents[MAX_N+1];
bool connected[MAX_N+1];

int Find(int x){
    if(x == parents[x])
        return x;
    return parents[x] = Find(parents[x]);
}

void Union(int x, int y){
    int parentX = Find(x);
    int parentY = Find(y);

    if(parentX != parentY)
        parents[parentY] = parentX;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        parents[i] = i;

    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);

        Union(u,v);
    }

    int result = 0;
    for(int i=1;i<=N;i++){
        int parentI = Find(i);
        if(connected[parentI] == false){
            result++;
            connected[parentI] = true;
        }
    }

    printf("%d\n",result);
    return 0;
}