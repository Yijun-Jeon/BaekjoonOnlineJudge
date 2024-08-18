#include <stdio.h>

using namespace std;

long long A,B,C;

long long fastPower(long long b){
    if(b == 1)
        return A%C;

    if(b%2 == 0){
        long long half = fastPower(b/2) % C;
        return (half * half) % C;
    }
    else{
        long long half = fastPower((b-1)/2) % C;
        return (((half*half)%C)*A)%C;
    }
}

int main(void)
{
    scanf("%lld %lld %lld",&A,&B,&C);

    printf("%lld\n",fastPower(B));
    return 0;
}