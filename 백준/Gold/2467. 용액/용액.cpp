#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 100000

using namespace std;

vector<int> minusVec, plusVec;

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int n=0;n<N;n++){
        int num;
        scanf("%d",&num);

        if(num < 0)
            minusVec.push_back(num);
        else
            plusVec.push_back(num);
    }

    int diff = 2000000000;
    int first,second;
    if(minusVec.size() > 1){
        diff = min(diff,abs(minusVec.back()+minusVec[minusVec.size()-2]));
        first = minusVec[minusVec.size()-2];
        second = minusVec.back();
    }

    if(plusVec.size() > 1){
        if(plusVec[0] + plusVec[1] < diff){
            diff = plusVec[0] + plusVec[1];
            first = plusVec[0];
            second = plusVec[1];
        }
    }

    if(minusVec.empty() || plusVec.empty()){
        printf("%d %d\n",first,second);
        return 0;
    }


    int minusIdx = minusVec.size()-1;
    int plusIdx = 0;
    while(true){
        if(abs(minusVec[minusIdx]+plusVec[plusIdx]) < diff){
            diff = abs(minusVec[minusIdx]+plusVec[plusIdx]);
            first = minusVec[minusIdx];
            second = plusVec[plusIdx];
        }   

        if(minusIdx == 0 && plusIdx == plusVec.size()-1)
            break;

        if(minusIdx == 0){
            plusIdx++;
        }else if(plusIdx == plusVec.size()-1){
            minusIdx--;
        }else if(abs(minusVec[minusIdx-1]) < plusVec[plusIdx+1]){
            minusIdx--;
        }else
            plusIdx++;
    }

    printf("%d %d\n",first,second);
    return 0;
}