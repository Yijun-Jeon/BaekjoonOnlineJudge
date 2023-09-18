#include <stdio.h>

#define MAX_N 10

using namespace std;

int coins[MAX_N];

int main(void)
{
	int N,K;
	scanf("%d %d",&N,&K);

	for(int i=0;i<N;i++)
		scanf("%d",&coins[i]);

	int cnt = 0;
	int idx = N-1;
	while(K){
		if(coins[idx] <= K){
			cnt += K / coins[idx];
			K = K % coins[idx];
		}
		idx--;
	}
	printf("%d\n",cnt);
    return 0;
}