#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_N 100000

using namespace std;

int N;

char swap(char c){
    return (c-'0')^1 + '0';
}

int main(void)
{
    scanf("%d",&N);
    string before,after;
    cin >> before >> after;
    
    string temp = before;
    int push = 0;
    int result = MAX_N;
    for(int i=1;i<N;i++){
        if(temp[i-1] != after[i-1]){
            push++;
            temp[i-1] = after[i-1];
            temp[i] = swap(temp[i]);
            if(i < N-1)
                temp[i+1] = swap(temp[i+1]);
        }
    }   
    if(temp == after)
        result = push;

    temp = before;
    temp[0] = swap(temp[0]);
    temp[1] = swap(temp[1]);

    push = 1;
    for(int i=1;i<N;i++){
        if(temp[i-1] != after[i-1]){
            push++;
            temp[i-1] = after[i-1];
            temp[i] = swap(temp[i]);
            if(i < N-1)
                temp[i+1] = swap(temp[i+1]);
        }
    }

    if(temp == after) result = min(result,push);

    if(result == MAX_N) result = -1;
    printf("%d\n",result);
    return 0;
}