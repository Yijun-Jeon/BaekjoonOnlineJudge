#include <stdio.h>
#include <algorithm>

#define MAX_N 200000

using namespace std;

int homes[MAX_N];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
        scanf("%d",&homes[i]);

    sort(homes,homes+N);

    int result = N % 2 == 0 ? homes[N/2-1] : homes[N/2];
    printf("%d\n",result);
    return 0;
}