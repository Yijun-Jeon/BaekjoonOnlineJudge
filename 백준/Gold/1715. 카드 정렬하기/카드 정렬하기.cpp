#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
    int N;
    scanf("%d",&N);

    priority_queue<int> pq;
    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);
        pq.push(-num);
    }

    int result = 0;
    while(pq.size() > 1){
        int first = -pq.top();
        pq.pop();
        int second = -pq.top();
        pq.pop();

        result += first + second;
        pq.push(-(first + second));
    }
    printf("%d\n",result);
    return 0;
}