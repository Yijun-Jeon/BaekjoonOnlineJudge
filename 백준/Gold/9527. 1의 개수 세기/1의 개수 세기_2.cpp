#include <stdio.h>

using namespace std;

long long count(long long num){
    num++;
    long long repeat = 1,result = 0;;
    while(repeat <= num){
        if(num/repeat % 2)
            result += num%repeat;

        result += num/repeat/2 * repeat;
        repeat *= 2;
    }
    return result;
}

int main(void)
{
    long long A,B;
    scanf("%lld %lld",&A,&B);
    
    printf("%lld\n",count(B) - count(A-1));
    return 0;
}