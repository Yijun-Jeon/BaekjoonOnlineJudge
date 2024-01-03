#include <stdio.h>
#include <utility>

#define MAX_N 1000

using namespace std;

int map[MAX_N+1][MAX_N+1];
int N;

int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        char temp[N+1];
        scanf("%s",temp);
        for(int j=1;j<=N;j++){
            map[i][j] = temp[j-1] == '*' ? 1 : 0;
        }
    }

    pair<int,int> heart;
    for(int i=2;i<=N-2;i++){
        for(int j=2;j<=N-1;j++){
            if(map[i][j] && map[i-1][j] && map[i][j-1] && map[i][j+1] && map[i+1][j]){
                heart.first = i;
                heart.second = j;
                break;
            }
        }
    }


    // 왼쪽 팔
    int leftArm = 0;
    int row = heart.first, col = heart.second-1;
    while(map[row][col]){
        leftArm++;
        col--;
    }

    // 오른쪽 팔
    int rightArm = 0;
    col = heart.second+1;
    while(map[row][col]){
        rightArm++;
        col++;
    }

    // 허리
    int waist = 0;
    row = heart.first+1, col = heart.second;
    while(map[row][col]){
        waist++;
        row++;
    }
    pair<int,int> lPos = make_pair(row,col);

    // 왼쪽 다리
    int leftLeg = 0;
    row = lPos.first, col = lPos.second-1;
    while(map[row][col]){
        leftLeg++;
        row++;
    }

    // 오른쪽 다리
    int rightLeg = 0;
    row = lPos.first, col = lPos.second+1;
    while(map[row][col]){
        rightLeg++;
        row++;
    }

    printf("%d %d\n",heart.first, heart.second);
    printf("%d %d %d %d %d\n",leftArm,rightArm,waist,leftLeg,rightLeg);
    return 0;
}