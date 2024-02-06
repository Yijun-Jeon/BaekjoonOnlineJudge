#include <stdio.h>

#define MAX_N 100000

using namespace std;

int parents[MAX_N+1];
int G,P;

int Find(int x){
    if(parents[x] == x)
        return x;
    return parents[x] = Find(parents[x]);
}

void Decrease(int x){
    while(x != parents[x])
        x = parents[x];
    parents[x] -= 1;
}

int main(void)
{
    scanf("%d %d",&G,&P);
    for(int i=0;i<=G;i++)
        parents[i] = i;

    int result = 0;
    bool end = false;
    for(int i=0;i<P;i++){
        int g;
        scanf("%d",&g);

        if(end)
            continue;
        
        int remain = Find(g);
        if(remain == 0){
            end = true;
            continue;
        }

        Decrease(g);
        result++;
    }
    printf("%d\n",result);
    return 0;
}