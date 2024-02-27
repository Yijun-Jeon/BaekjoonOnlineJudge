#include <stdio.h>

#define MAX_N 100

using namespace std;

int light[MAX_N+1];
int N;

void Func(int gender,int num){
    light[num] ^= 1;
    
    if(gender == 1){
        for(int i=num*2; i<=N; i+=num)
            light[i] ^= 1;
    }else{
        int left = num-1;
        int right = num+1;
        while(left > 0 && right <= N && light[left] == light[right]){
            light[left] ^= 1;
            light[right] ^= 1;
            left--;
            right++;
        }
    }
}

int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&light[i]);

    int studentNum;
    scanf("%d",&studentNum);

    for(int student=0; student<studentNum; student++){
        int gender, num;
        scanf("%d %d",&gender,&num);

        Func(gender,num);
    }

    for(int i=1;i<=N;i++){
        printf("%d ",light[i]);
        if(i%20 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}