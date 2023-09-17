#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
	int N;
	priority_queue<int> pq;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);

		if(x == 0){
			int top;
			if(pq.empty()){
				printf("%d\n",0);
			}else{
				top = pq.top();
				printf("%d\n",top);
				pq.pop();
			}
		}else pq.push(x);
	}
    return 0;
}