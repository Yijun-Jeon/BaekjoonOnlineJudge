#include <stdio.h>
#include <cmath>

#define MAX_SIZE 54

using namespace std;

long long cnt(long long num){
    num++;
    long long result = 0;
    for(int i=MAX_SIZE-1; i >= 0; i--){
        long long denomi = pow(2,i);
        if(num < denomi)
            continue;
        result += num/denomi/2 * denomi;
        if(num/denomi % 2 == 1)
            result += num % denomi;
    }
    return result;
}

int main(void)
{
    long long A,B;
    scanf("%lld %lld",&A,&B);
    
    printf("%lld\n",cnt(B) - cnt(A-1));
    return 0;
}