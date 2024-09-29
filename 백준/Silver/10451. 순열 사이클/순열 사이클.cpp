#include <stdio.h>
#include <cstring>

using namespace std;

int main(void)
{
    int T;
    scanf("%d",&T);


    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);

        int nums[N+1];
        for(int i=1;i<=N;i++)
            scanf("%d",&nums[i]);

        bool visited[N+1];
        memset(visited,false,sizeof(visited));

        int result = 0;
        for(int i=1;i<=N;i++){
            if(visited[i] == false){
                int next = i;
                while(visited[next] == false){
                    visited[next] = true;
                    next = nums[next];                    
                }
                result++;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}