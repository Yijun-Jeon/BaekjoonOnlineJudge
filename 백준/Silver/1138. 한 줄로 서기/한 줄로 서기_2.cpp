#include <stdio.h>

#define MAX_N 10

using namespace std;

int larger[MAX_N+1];
int result[MAX_N+1];

int main(void)
{
	int N;
	scanf("%d",&N);

	for(int i=1;i<=N;i++)
		scanf("%d",&larger[i]);

	result[larger[1]] = 1;
	for(int i=2;i<=N;i++){
		
		int idx = larger[i];
		while(result[idx] != 0){
			idx = (idx+1) % N;
		}

		int empty = 0;
		for(int j=0;j<idx;j++){
			if(result[j] == 0)
				empty++;
		}

		if(empty < larger[i]){
			empty = larger[i] - empty;
			while(empty){
				idx++;
				if(result[idx] == 0)
					empty--;
			}
		}

		result[idx] = i;
	}

	for(int i=0;i<N;i++)
		printf("%d ",result[i]);
	printf("\n");
    return 0;
}