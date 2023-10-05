#include <stdio.h>

#define MAX_N 100

using namespace std;

long long P[MAX_N+1] = {0,1,1,1,2,2,3,4,5,7,9};

int main(void)
{
	for(int i=11;i<=MAX_N;i++)
		P[i] = P[i-1] + P[i-5];

	int T;
	scanf("%d",&T);

	for(int test_case=0; test_case<T; test_case++){
		int N;
		scanf("%d",&N);
		printf("%lld\n",P[N]);
	}
    return 0;
}