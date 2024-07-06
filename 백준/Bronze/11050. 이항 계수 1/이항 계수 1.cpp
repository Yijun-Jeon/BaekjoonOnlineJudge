#include <stdio.h>

using namespace std;

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    int result = 1;
    for(int i=N;i>N-K;i--)
        result *= i;

    for(int i=1;i<=K;i++)
        result /= i;

    printf("%d\n",result);
    return 0;
}