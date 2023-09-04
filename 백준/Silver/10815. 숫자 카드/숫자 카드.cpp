#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    int N,M;
    unordered_map<int,int> map;
    int result[500000];

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int num;
        scanf("%d", &num);
        map[num] = 1;
    }

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int num;
        scanf("%d", &num);

        result[i] = map[num];
    }

    for(int i=0;i<M;i++)
        printf("%d ",result[i]);
    printf("\n");
    return 0;
}