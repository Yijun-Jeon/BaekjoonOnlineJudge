#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX_N 50

using namespace std;

int buildings[MAX_N+1];
int N;

int Count(int b){
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(abs(b-i) <= 1){
            cnt++;
            continue;
        }

        double slope = (double)(buildings[b]-buildings[i]) / (b-i);
        double intercept = (double)buildings[b] - slope*b;

        bool valid = true;
        for(int j=min(i,b)+1; j<max(i,b); j++){
            double contact = slope*j + intercept;
            if(contact <= (double)buildings[j]){
                valid = false;
                break;
            }
        }

        if(valid) cnt++;
    }
    return cnt-1;
}

int main(void)
{
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
        scanf("%d",&buildings[i]);

    int result = 0;
    for(int i=1;i<=N;i++)
        result = max(result,Count(i));

    printf("%d\n",result);
    return 0;
}