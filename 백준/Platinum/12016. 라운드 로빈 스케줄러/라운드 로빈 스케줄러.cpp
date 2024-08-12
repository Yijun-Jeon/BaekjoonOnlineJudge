#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N;
int segTree[MAX_N*2+2];
long long result[MAX_N];
priority_queue<pair<long long,int> > pq;

void update(int idx, bool isAdd){
    for(idx += MAX_N; idx>0; idx >>= 1){
        if(isAdd) segTree[idx]++;
        else segTree[idx]--;
    }
}

int query(int left, int right){
    int result = 0;
    for(left += MAX_N, right += MAX_N; left<=right; left >>= 1, right >>= 1){
        if(left%2 == 1) result += segTree[left++];
        if(right%2 == 0) result += segTree[right--];
    }
    return result;
}

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        long long num;
        scanf("%lld",&num);

        update(i,true);
        pq.push(make_pair(-num,-i));
    }

    int lastLeft = 0, lastRight = 0, lastIdx = -1;
    long long time = 0, rotate = 0;
    while(!pq.empty()){
        int now = -pq.top().first;
        int idx = -pq.top().second;

        int left = query(0,idx);
        int right = query(idx+1,N-1);

        time += (max(now-rotate-1,(long long)0))*pq.size();
        if(rotate == now){
            time += lastRight-right;
        }else{
            time += lastRight;
            time += left;
        }
        
        result[idx] = time;

        update(idx,false);
        pq.pop();

        rotate = now;
        lastLeft = left;
        lastRight = right;
        lastIdx = idx;
    }
    
    for(int i=0;i<N;i++)
        printf("%lld\n",result[i]);
    return 0;
}