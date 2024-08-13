#include <stdio.h>
#include <algorithm>

#define MAX_N 100000
#define MAX_NUM 1e9

using namespace std;

int N,M;
int minTree[MAX_N*2+2];
int maxTree[MAX_N*2+2];

void query(int left, int right){
    int maxResult = 0, minResult = MAX_NUM;
    for(left+=N, right+=N; left<=right; left>>=1,right>>=1){
        if(left%2 == 1){
            maxResult = max(maxResult,maxTree[left]);
            minResult = min(minResult,minTree[left++]);
        }

        if(right%2 == 0){
            maxResult = max(maxResult,maxTree[right]);
            minResult = min(minResult,minTree[right--]);
        }
    }
    
    printf("%d %d\n",minResult,maxResult);
}

int main(void)
{
    scanf("%d %d",&N,&M);
    fill(&minTree[0],&minTree[MAX_N*2+2],MAX_NUM);

    for(int i=1;i<=N;i++){
        int num;
        scanf("%d",&num);

        minTree[i+N] = maxTree[i+N] = num;
    }

    for(int i=N;i>0;i--){
        minTree[i] = min(minTree[i<<1],minTree[(i<<1)+1]);
        maxTree[i] = max(maxTree[i<<1],maxTree[(i<<1)+1]);
    }

    for(int i=0;i<M;i++){
        int left,right;
        scanf("%d %d",&left,&right);

        query(left,right);
    }
    return 0;
}