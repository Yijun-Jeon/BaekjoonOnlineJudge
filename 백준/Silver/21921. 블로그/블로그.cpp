#include <stdio.h>

#define MAX_N 250000

using namespace std;

int N,X;
int visits[MAX_N+1];

int main(void)
{
    scanf("%d %d",&N,&X);

    int sum = 0;
    int cnt = 0;
    int maxVisit = 0;
    for(int i=1;i<=N;i++){
        scanf("%d",&visits[i]);
        sum += visits[i];

        if(i < X) continue;
        
        sum -= visits[i-X];
        if(sum == maxVisit)
            cnt++;
        else if(sum > maxVisit){
            maxVisit = sum;
            cnt = 1;
        }
    }

    if(maxVisit == 0) printf("SAD\n");
    else printf("%d\n%d\n",maxVisit,cnt);
    return 0;
}