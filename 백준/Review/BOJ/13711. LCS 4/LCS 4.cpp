#include <stdio.h>

#define MAX_N 100000

using namespace std;

int N;
int A[MAX_N];
int B[MAX_N];
int dp[MAX_N];

int binarySearch(int left, int right, int num){
    while(left <= right){
        int mid = (left+right)/2;

        if(dp[mid] == num)
            return mid;

        if(dp[mid] < num)
            left = mid+1;
        else
            right = mid-1;
    }
    return left;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        A[num] = i;
    }

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        B[i] = A[num];
    }
    
    dp[0] = B[0];
    int result = 1;
    for(int i=1;i<N;i++){
        if(dp[result-1] < B[i])
            dp[result++] = B[i];
        else{
            int idx = binarySearch(0,result-1,B[i]);
            dp[idx] = B[i];
        }
    }
    printf("%d\n",result);
    return 0;
}