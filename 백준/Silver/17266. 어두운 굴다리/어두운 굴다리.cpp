#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int N,M;
    scanf("%d %d",&N,&M);

    int x;
    scanf("%d",&x);

    int result = x, last = x;
    for(int i=1;i<M;i++){
        scanf("%d",&x);

        if((x - last) % 2 == 0)
            result = max(result,(x-last)/2);
        else
            result = max(result,(x-last)/2 + 1);

        last = x;
    }
    result = max(result,N-last);

    printf("%d\n",result);
    return 0;
}