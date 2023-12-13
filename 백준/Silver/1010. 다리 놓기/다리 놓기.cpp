#include <stdio.h>
#include <algorithm>

#define MAX_N 30

using namespace std;

int combs[MAX_N][MAX_N];

void combination(){
	for(int i=1;i<MAX_N;i++){
		for(int j=1;j<=i;j++){
			if(i == j) combs[i][j] = 1;
			else if(j == 1) combs[i][j] = i;
			else combs[i][j] = combs[i-1][j] + combs[i-1][j-1];
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);

	combination();

	for(int test_case=0; test_case<T; test_case++){
		int N,M;
		scanf("%d %d",&N,&M);

		printf("%d\n",combs[M][N]);
	}
    return 0;
}