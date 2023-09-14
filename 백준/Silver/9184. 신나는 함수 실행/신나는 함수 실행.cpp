#include <stdio.h>

#define MAX_N 100

using namespace std;

int dp[MAX_N+1][MAX_N+1][MAX_N+1];
int A,B,C;

void makeDP(void){
	for(int a=0;a<=MAX_N;a++){
		for(int b=0;b<=MAX_N;b++){
			for(int c=0;c<=MAX_N;c++){
				if(a <= 50 || b <= 50 || c <= 50)
					dp[a][b][c] = 1;
				else if(a > 70 || b > 70 || c > 70)
					dp[a][b][c] = dp[70][70][70];
				else if(a < b && b < c)
					dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
				else
					dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
			}
		}
	}
}

int main(void)
{
	makeDP();
	while(true){
		scanf("%d %d %d",&A,&B,&C);
		if(A == -1 && B == -1 && C == -1)
			break;
		
		int a = A + MAX_N/2;
		int b = B + MAX_N/2;
		int c = C + MAX_N/2;

		if(a <= 50 || b <= 50 || c <= 50)
				dp[a][b][c] = 1;
		else if(a > 70 || b > 70 || c > 70)
			dp[a][b][c] = dp[70][70][70];
		else if(a < b && b < c)
			dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
		else
			dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];

		printf("w(%d, %d, %d) = %d\n",A,B,C,dp[A+MAX_N/2][B+MAX_N/2][C+MAX_N/2]);
	}
    return 0;
}