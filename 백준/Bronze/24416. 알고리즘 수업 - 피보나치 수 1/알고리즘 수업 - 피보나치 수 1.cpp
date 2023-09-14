#include <iostream>
#include <stdio.h>

#define MAX_N 40

using namespace std;

int recursizeCnt = 0;
int dpCnt = 0;

int dp[MAX_N+1];

int fib1(int n){
	if(n==1 or n==2){
		recursizeCnt++;
		return 1;
	}
	return fib1(n-1) + fib1(n-2);
}

int fib2(int n){
	dp[1] = dp[2] = 1;
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
		dpCnt++;
	}
	return dp[n];
}

int main(void)
{
	int n;
	scanf("%d",&n);

	fib1(n);
	fib2(n);

	printf("%d %d\n",recursizeCnt,dpCnt);
    return 0;
}