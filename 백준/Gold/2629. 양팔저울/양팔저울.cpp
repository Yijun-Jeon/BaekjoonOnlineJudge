#include <stdio.h>

#define MAX_N 30
#define MAX_K 40000

using namespace std;

int N,K;
int weights[MAX_N];
bool dp[MAX_N][MAX_K+1];
char answer[7];

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&weights[i]);

	dp[0][0] = dp[0][weights[0]] = true;
	
	int sum = weights[0];
	for(int i=1;i<N;i++){
		sum += weights[i];
		for(int j=0;j<sum;j++){
			if(dp[i-1][j] == true){
				
				if(j - weights[i] > 0)
					dp[i][j-weights[i]] = true;

				dp[i][j] = true;
				dp[i][j+weights[i]] = true;
			}else if(weights[i] - j >= 0){
				dp[i][j] = dp[i-1][weights[i]-j];
			}
		}
	}

	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int num;
		scanf("%d",&num);
		answer[i] = dp[N-1][num] ? 'Y' : 'N';
	}

	for(int i=0;i<K;i++)
		printf("%c ",answer[i]);
	printf("\n");
	
    return 0;
}