#include <stdio.h>
#include <algorithm>

#define MAX_N 500

using namespace std;

int N,M;
bool map[MAX_N+1][MAX_N+1];

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);

        map[a][b] = true;
    }

    for(int i=1;i<=N;i++)
        map[i][i] = true;

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(map[i][j])
                    continue;
                if(map[i][k] && map[k][j])
                    map[i][j] = true;
            }
        }
    }

    int result = 0;
    for(int i=1;i<=N;i++){
        int cnt = 0;
        for(int j=1;j<=N;j++){
            if(map[i][j] || map[j][i])
                cnt++;
        }
        if(cnt == N)
            result++;
    }
    printf("%d\n",result);
    return 0;
}