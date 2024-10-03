#include <stdio.h>

#define MAX_N 1000000

using namespace std;

int parents[MAX_N+1];

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
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)
        parents[i] = i;

    for(int i=0;i<m;i++){
        int op,a,b;
        scanf("%d %d %d",&op,&a,&b);

        if(op == 1){
            if(Find(a) == Find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }else
            Union(a,b);
    }
    return 0;
}