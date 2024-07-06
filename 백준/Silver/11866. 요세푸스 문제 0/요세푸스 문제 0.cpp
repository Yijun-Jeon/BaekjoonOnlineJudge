#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    queue<int> q;
    for(int i=1;i<=N;i++)
        q.push(i);

    printf("<");
    int k = K;
    while(!q.empty()){
        if(q.size() == 1){
            printf("%d>\n",q.front());
            break;
        }

        int front = q.front();
        q.pop();

        if(--k) q.push(front);
        else{
            printf("%d, ",front);
            k = K;
        }
    }
    return 0;
}