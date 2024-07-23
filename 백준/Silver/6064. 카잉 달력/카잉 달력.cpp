#include <stdio.h>
#include <algorithm>

using namespace std;

int M,N,X,Y;

int GCD(int a, int b){
    if(b == 0)
        return a;
    return GCD(b,a%b);
}

int LCM(int a, int b){
    return a*b / GCD(a,b);
}

int calc(){
    int cnt = X;
    int gcd = LCM(M,N);
    while(cnt <= gcd){
        if((cnt-1) % N+1 == Y)
            return cnt;
        cnt += M;
    }
    return -1;
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case=0;test_case<T;test_case++){
        scanf("%d %d %d %d",&M,&N,&X,&Y);
        printf("%d\n",calc());
    }
    return 0;
}