#include <stdio.h>
#include <cmath>

#define MAX_N 15

using namespace std;

int N,R,C;

int main(void)
{
    scanf("%d %d %d",&N,&R,&C);

    int result = 0;
    while(N){
        int half = pow(2,N-1);
        int quadrant = pow(2,2*N-2);
        int acc;

        if(R >= half && C >= half){
            acc = 3*quadrant;
        }else if(R >= half && C < half){
            acc = 2*quadrant;
        }else if(R < half && C >= half){
            acc = quadrant;
        }else if(R < half && C < half){
            acc = 0;
        }

        R -= R/half * half;
        C -= C/half * half;

        result += acc;
        N--;
    }
    printf("%d\n",result);
    return 0;
}