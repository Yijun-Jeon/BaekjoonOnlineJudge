#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int getDistance(int x1,int y1,int x2, int y2){
	return (int)sqrt(pow(x1-x2,2) + pow(y2-y1,2));
}

int main(void)
{
	int T;
	scanf("%d",&T);

	for(int test_case=0; test_case < T; test_case++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

		int n;
		scanf("%d",&n);

		int result = 0;
		for(int i=0;i<n;i++){
			int x,y,r;
			scanf("%d %d %d",&x,&y,&r);

			// 출발지와 행성의 거리
			int d1 = getDistance(x,y,x1,y1);
			// 도착지와 행성의 거리
			int d2 = getDistance(x,y,x2,y2);

			// 행성 안에 출발지, 도착지 모두 존재 -> pass
			if(d1 < r && d2 < r)
				continue;
			// 행성 안에 출발지 혹은 도착지 존재 -> count
			else if(d1 < r || d2 < r)
				result++;
		}

		printf("%d\n",result);
	}
    return 0;
}