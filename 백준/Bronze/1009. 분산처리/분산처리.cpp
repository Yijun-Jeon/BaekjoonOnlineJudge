#include <stdio.h>

using namespace std;

int main(void)
{	
	int T;
	scanf("%d",&T);

	for(int test_case = 0; test_case<T; test_case++){
		int a,b;
		scanf("%d %d",&a,&b);

		int num = 1;
		while(b--)
			num = (num*a) % 10;

		if(num == 0) num = 10;
		printf("%d\n",num);
	}
    return 0;
}