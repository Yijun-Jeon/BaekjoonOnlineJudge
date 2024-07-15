#include <stdio.h>

#define MAX_N 128

using namespace std;

int N;
int map[MAX_N][MAX_N];

int main(void)
{
    int white = 0, blue = 0;

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);

            if(map[i][j] == 0) white++;
            else blue++;
        }
    }

    int n = 2;
    while(n <= N){
        int curWhite = 0, curBlue = 0;
        for(int row=0; row<N; row += n){
            for(int col=0; col<N; col += n){
                int prev = map[row][col];
                bool valid = true;
                for(int i=row;i<row+n && valid;i++){
                    for(int j=col;j<col+n && valid;j++){
                        if(map[i][j] != prev)
                            valid = false;
                    }
                }

                if(valid){
                    if(prev == 0) curWhite++;
                    else curBlue++;
                }
            }
        }
        
        white = white - curWhite*4 + curWhite;
        blue = blue - curBlue*4 + curBlue;
        n *= 2;
    }

    printf("%d\n%d\n",white,blue);
    return 0;
}