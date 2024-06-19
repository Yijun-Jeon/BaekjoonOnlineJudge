#include <stdio.h>

#define MAX_N 500000

using namespace std;

int N;
int tops[MAX_N+1];
int parents[MAX_N+1];

int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&tops[i]);

    int maxLeft = tops[1];
    for(int i=2;i<=N;i++){
        if(tops[i] > maxLeft)
            maxLeft = tops[i];
        else if(tops[i-1] >= tops[i])
            parents[i] = i-1;
        else{
            int parent = i-1;
            while(tops[parent] < tops[i])
                parent = parents[parent];
            parents[i] = parent;
        }
    }

    for(int i=1;i<=N;i++)
        printf("%d ",parents[i]);
    printf("\n");
    return 0;
}