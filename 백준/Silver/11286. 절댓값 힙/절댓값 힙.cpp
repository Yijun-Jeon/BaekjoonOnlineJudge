#include <stdio.h>
#include <queue>
#include <cmath>

using namespace std;

int main(void)
{
	int N;
	priority_queue<pair<int,int> > pq;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);

		if(x == 0){
			if(pq.empty())
				printf("%d\n",0);
			else{
				printf("%d\n",-pq.top().second);
				pq.pop();
			}
		}else pq.push(make_pair(-abs(x),-x));
	}
    return 0;
}