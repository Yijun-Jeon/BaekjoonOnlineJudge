#include <iostream>
#include <stdio.h>

#define MAX_T 100

using namespace std;

int cars[MAX_T+1];
int times[3];

int main(void)
{
    scanf("%d %d %d",&times[0],&times[1],&times[2]);

    for(int i=0;i<3;i++){
        int arrive, leave;
        scanf("%d %d",&arrive,&leave);

        for(int i=arrive;i<leave;i++)
            cars[i]++;
    }

    int result = 0;
    for(int i=1;i<=MAX_T;i++)
        result += cars[i] * times[cars[i]-1];
    printf("%d\n",result);
    return 0;
}