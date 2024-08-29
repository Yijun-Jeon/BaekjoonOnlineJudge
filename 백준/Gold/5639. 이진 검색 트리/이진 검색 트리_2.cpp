#include <iostream>

#define MAX_N 10000

using namespace std;

int cnt;
int tree[MAX_N];

void PostOrder(int start, int end){
    if(start > end)
        return;

    int idx = start+1;
    while(idx <= end && tree[idx] < tree[start])
        idx++;

    PostOrder(start+1,idx-1);
    PostOrder(idx,end);
    printf("%d\n",tree[start]);
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int key;
    while(cin >> key)
        tree[cnt++] = key;

    PostOrder(0,cnt-1);
    return 0;
}