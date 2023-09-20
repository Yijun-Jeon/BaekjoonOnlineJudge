#include <stdio.h>
#include <algorithm>

#define MAX_N 100000
#define LL long long

using namespace std;

int city[MAX_N];
int station[MAX_N];
int N;

LL greedy(){
	int idx = 0;
	LL sum = 0;
	while(idx < N-1){
		LL cost = station[idx];
		LL dist = 0;
		while(idx < N-1 && cost <= station[idx]){
			dist += city[idx++];
		}

		sum += cost * dist;
	}

	return sum;
}

int main(void)
{
	scanf("%d",&N);

	for(int i=0;i<N-1;i++)
		scanf("%d",&city[i]);

	for(int i=0;i<N;i++)
		scanf("%d",&station[i]);

	printf("%lld\n",greedy());

    return 0;
}