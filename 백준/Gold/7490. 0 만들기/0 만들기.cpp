#include <stdio.h>
#include <queue>

using namespace std;

int N;
vector<int> op;

bool calc(){
    queue<int> q;

    int acc = 1;
    for(int i=0;i<op.size();i++){
        if(op[i] == 0){
            acc *= 10;
            acc += i+2;
        }else{
            q.push(acc);
            acc = i+2;
        }
    }
    q.push(acc);

    int result = q.front();
    q.pop();
    for(int i=0;i<op.size();i++){
        if(q.empty())
            break;
        if(op[i] == 0)
            continue;

        int front = q.front();
        q.pop();
        if(op[i] == 1)
            result += front;
        else if(op[i] == 2)
            result -= front;
    }

    return result == 0;
}

void DFS(int idx){
    if(idx == N){
        if(calc()){
            for(int i=1;i<=N;i++){
                printf("%d",i);
                if(i < N){
                    if(op[i-1] == 0)
                        printf(" ");
                    else if(op[i-1] == 1)
                        printf("+");
                    else if(op[i-1] == 2)
                        printf("-");
                }
            }
            printf("\n");
        }
        return;
    }

    for(int i=0;i<3;i++){
        op.push_back(i);
        DFS(idx+1);
        op.pop_back();
    }
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case=0; test_case<T; test_case++){
        op.clear();
        scanf("%d",&N);

        DFS(1);
        printf("\n");
    }
    return 0;
}