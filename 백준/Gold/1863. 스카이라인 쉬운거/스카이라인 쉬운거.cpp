#include <stdio.h>
#include <algorithm>
#include <stack>

#define MAX_N 50000

using namespace std;

int skyline[MAX_N];

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int n=0;n<N;n++){
        int x;
        scanf("%d %d",&x,&skyline[n]);
    }

    stack<int> stk;

    int result = 0;
    for(int n=0;n<N;n++){
        while(!stk.empty() && stk.top() > skyline[n]){
            result++;
            stk.pop();
        }
        if(skyline[n] && (stk.empty() || stk.top() < skyline[n]))
            stk.push(skyline[n]);
    }
    while(!stk.empty()){
        result++;
        stk.pop();
    }
    printf("%d\n",result);
    return 0;
}