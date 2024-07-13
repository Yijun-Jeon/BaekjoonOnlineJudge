#include <stdio.h>
#include <algorithm>

#define MAX_N 100

using namespace std;

int N;
int map[MAX_N][MAX_N];

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%d",&map[i][j]);
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                map[i][j] |= map[i][k] && map[k][j];
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
    return 0;
}