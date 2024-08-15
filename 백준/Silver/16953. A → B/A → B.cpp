#include <stdio.h>
#include <string>

using namespace std;

int main(void)
{
    int A,B;
    scanf("%d %d",&A,&B);

    int result = 0;
    while(A < B){
        if(B%10 == 1)
            B /= 10;
        else if(B%2 == 0)
            B /= 2;
        else break;

        result++;
    }
    if(A != B) result = -2;
    printf("%d\n",result+1);
    return 0;
}