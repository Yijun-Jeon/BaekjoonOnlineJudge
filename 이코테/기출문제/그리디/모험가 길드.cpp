#include <stdio.h>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int arr[MAX_N+1];

int main(void)
{
	int N;
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		arr[num]++;
	}

	int result = 0;
	int remain = 0;
	for(int i=1;i<=N;i++){
		result += (arr[i]+remain) / i;
		remain = (arr[i]+remain) % i;
	}

	printf("%d\n",result);
    return 0;
}