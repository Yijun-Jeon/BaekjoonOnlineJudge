#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main(void)
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N*N;i++){
		int num;
		scanf("%d",&num);
		pq.push(-num);
		if(i >= N)
			pq.pop();

	}

	printf("%d\n",-pq.top());
    return 0;
}