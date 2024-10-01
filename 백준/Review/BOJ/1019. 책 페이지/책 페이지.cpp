#include <stdio.h>

typedef long long ll;

using namespace std;

int counts[10];

int main(void)
{
    ll N;
    scanf("%lld",&N);

    ll denomi = 1,remain = 0, n = N;
    while(n){
        ll quotient = n/10;
        int remainder = n%10;

        for(int i=1;i<remainder;i++)
            counts[i] += (quotient+1) * denomi;
        if(remainder == 0){
            counts[remainder] += (quotient-1) * denomi + (remain+1);
            for(int i=remainder+1;i<10;i++)
                counts[i%10] += quotient * denomi;
        }else{
            counts[remainder] += quotient * denomi + (remain+1);
            for(int i=remainder+1;i<=10;i++)
                counts[i%10] += quotient * denomi;
        }

        denomi *= 10;
        n /= 10;
        remain = N%denomi;
    }
    for(int i=0;i<10;i++)
        printf("%d ",counts[i]);
    printf("\n");    
    return 0;
}