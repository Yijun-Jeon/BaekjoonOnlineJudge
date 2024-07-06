#include <stdio.h>
#include <stack>

using namespace std;

int main(void)
{
    int K;
    scanf("%d",&K);

    stack<int> stk;
    for(int i=0;i<K;i++){
        int num;
        scanf("%d",&num);

        if(num == 0) stk.pop();
        else stk.push(num);
    }

    long long result = 0;
    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    printf("%lld\n",result);
    return 0;
}