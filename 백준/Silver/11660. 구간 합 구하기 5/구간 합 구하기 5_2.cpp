#include <iostream>

#define MAX_N 1024

using namespace std;

int N,M;
int map[MAX_N+1][MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++)
            cin >> map[x][y];
    }

    for(int i=1;i<=N;i++){
        map[1][i] += map[1][i-1];
        map[i][1] += map[i-1][1];
    }

    for(int x=2;x<=N;x++){
        for(int y=2;y<=N;y++)
            map[x][y] += map[x][y-1] + map[x-1][y] - map[x-1][y-1];
    }

    while(M--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
        cout << result << '\n';
    }
    return 0;
}