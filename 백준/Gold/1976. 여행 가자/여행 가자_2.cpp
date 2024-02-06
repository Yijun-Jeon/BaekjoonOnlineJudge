#include <stdio.h>

#define MAX_N 200

using namespace std;

int N,M;
int parents[MAX_N+1];

int Find(int x){
    if(parents[x] == x)
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
    scanf("%d",&N);
    scanf("%d",&M);

    for(int i=1;i<=N;i++)
        parents[i] = i;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int canGo;
            scanf("%d",&canGo);

            if(canGo)
                Union(i,j);
        }
    }

    int prev,now;
    scanf("%d",&prev);

    bool result = true;
    for(int i=1;i<M;i++){
        scanf("%d",&now);
        result &= (Find(prev) == Find(now));
        prev = now;
    }

    if(result) printf("YES\n");
    else  printf("NO\n");
    return 0;
}