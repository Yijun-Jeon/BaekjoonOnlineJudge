#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int test_case=0; test_case<T; test_case++){
        int N,M;
        scanf("%d %d",&N,&M);

        queue<pair<int,int> > q;
        priority_queue<int> pq;

        for(int i=0;i<N;i++){
            int priority;
            scanf("%d",&priority);

            q.push(make_pair(priority,i));
            pq.push(priority);    
        }

        int result = 1;
        while(!q.empty()){
            int priority = q.front().first;
            int cur = q.front().second;
            q.pop();

            if(priority == pq.top()){
                pq.pop();
                if(cur == M)
                    break;
                
                result++;
            }else q.push(make_pair(priority,cur));
            
        }
        printf("%d\n",result);
    }
    return 0;
}