#include <iostream>
#include <stdio.h>

using namespace std;

char map[3][3];

bool checkValid(int cntX, int cntO){
    int bingoX = 0;
    int bingoO = 0;
    // 가로 빙고 검사
    for(int i=0;i<3;i++){
        if(map[i][0] == '.')
            continue;
        if(map[i][0] == map[i][1] && map[i][1] == map[i][2]){
            if(map[i][0] == 'X') bingoX++;
            else bingoO++;
        }        
    }

    // 세로 빙고 검사
    for(int i=0;i<3;i++){
        if(map[0][i] == '.')
            continue;
        if(map[0][i] == map[1][i] && map[1][i] == map[2][i]){
            if(map[0][i] == 'X') bingoX++;
            else bingoO++;
        }        
    }

    // 대각선 빙고 검사
    if(map[0][0] != '.' && map[0][0] == map[1][1] && map[1][1] == map[2][2]){
        if(map[0][0] == 'X') bingoX++;
        else bingoO++;
    }

    // 대각선 빙고 검사
    if(map[0][2] != '.' && map[2][0] == map[1][1] && map[1][1] == map[0][2]){
        if(map[2][0] == 'X') bingoX++;
        else bingoO++;
    }

    // X가 이김
    if(bingoX && !bingoO && cntX == cntO+1)
        return true;

    // O가 이김
    if(!bingoX && bingoO && cntX == cntO)
        return true;

    // 승부 X
    if(!bingoX && !bingoO && cntX == 5 && cntO == 4)
        return true;

    return false;

}

int main(void)
{
    while(true){
        char S[10];
        scanf("%s",S);

        if(S[0] == 'e')
            return 0;

        int cntX = 0;
        int cntO = 0;
        for(int i=0;i<9;i++){
            map[i/3][i%3] = S[i];

            if(S[i] == 'X') cntX++;
            if(S[i] == 'O') cntO++;
        }

        if(checkValid(cntX,cntO))
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}