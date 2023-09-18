#include <stdio.h>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int times[MAX_N];

int main(void)
{
	int N;
	scanf("%d",&N);

	int sum = 0;
	for(int i=0;i<N;i++){
		scanf("%d",&times[i]);
		sum += times[i];
	}

	sort(times,times+N);

	int result = sum;
	for(int i=N-1;i>=0;i--){
		sum -= times[i];
		result += sum;
	}
	printf("%d\n",result);
    return 0;
}