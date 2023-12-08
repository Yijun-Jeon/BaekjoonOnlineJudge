#include <stdio.h>

using namespace std;

int main(void)
{
	int N;
	scanf("%d",&N);

	bool skWin;
	if(N%6 == 0 || N%2 == 0)
		skWin = false;
	else
		skWin = true;

	if(skWin)
		printf("SK\n");
	else
		printf("CY\n");
    return 0;
}