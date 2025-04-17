#include <iostream>

#define MAX_LEN 1001
#define MAX_N 100

using namespace std;

int N;
int map[MAX_LEN][MAX_LEN];
int result[MAX_N];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i=1;i<=N;i++){
        int row,col,width,height;
        cin >> row >> col >> width >> height;

        for(int r=row;r<row+width;r++){
            for(int c=col;c<col+height;c++){
                map[r][c] = i;
            }
        }
    }

    for(int i=0;i<MAX_LEN;i++){
        for(int j=0;j<MAX_LEN;j++){
            result[map[i][j]]++;
        }
    }

    for(int i=1;i<=N;i++)
        cout << result[i] << '\n';
    return 0;
}