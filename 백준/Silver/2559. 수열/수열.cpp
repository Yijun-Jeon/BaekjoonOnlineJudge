#include <stdio.h>
#include <queue>

#define MAX_N 100000

using namespace std;

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    int sum = 0, result = -100 * MAX_N;
    queue<int> q;
    for(int i=1;i<=N;i++){
        int num;
        scanf("%d",&num);

        q.push(num);
        sum += num;

        if(i < K)
            continue;

        if(i > K){
            sum -= q.front();
            q.pop();        
        }
        
        if(result < sum)
            result = sum;    
    }
    printf("%d\n",result);
    return 0;
}