#include <stdio.h>
#include <algorithm>

using namespace std;

int M,N,X,Y;

int GCD(int a, int b){
    if(a < b) swap(a,b);

    while(b){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        scanf("%d %d %d %d",&M,&N,&X,&Y);
        int result = X;
        int LCM = M*N/GCD(M,N);
        while(result <= LCM){
            if((result-1)%N+1 == Y)
                break;
            result += M;
        }

        if(result > LCM) result = -1;
        printf("%d\n",result);
    }
    return 0;
}