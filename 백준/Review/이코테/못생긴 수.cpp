#include <iostream>
#include <stdio.h>

#define MAX_N 100000000

using namespace std;

bool dp[MAX_N+1];

int main(void)
{
    int n;
    scanf("%d",&n);

    dp[1] = true;
    
    int num = 2;
    while(--n){
        if(num%2 == 0 && dp[num/2])
            dp[num] = true;
        else if(num%3 == 0 && dp[num/3])
            dp[num] = true;
        else if(num%5 == 0 && dp[num/5])
            dp[num] = true;
        else
            n++;
        num++;
    }

    printf("%d\n",num-1);
    return 0;
}