#include <string>
#include <vector>

using namespace std;

int M,N;
vector<vector<int>> prevKey;
vector<vector<int>> Key;

bool checkPosValid(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= N)
        return false;
    return true;
}

void rotateKey(){
    prevKey = Key;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            Key[i][j] = prevKey[j][M-1-i];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    M = key.size();
    N = lock.size();
    
    Key = key;
    prevKey = key;
    
    // 자물쇠 홈 수 
    int total = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(lock[i][j] == 0)
                total++;
        }
    }
    
    for(int row = 1-M; row < N && !answer; row++){
        for(int col = 1-M; col < N && !answer; col++){
            int rotate = 0;
            while(!answer && rotate < 4){
                int count = 0;
                bool valid = true;
                for(int mRow = 0; mRow < M && valid; mRow++){
                    for(int mCol = 0; mCol < M && valid; mCol++){
                        int nRow = row+mRow;
                        int nCol = col+mCol;

                        if(checkPosValid(nRow,nCol)){
                            // 둘 다 돌기 or 홈 -> pass
                            if(Key[mRow][mCol] == lock[nRow][nCol])
                                valid = false;
                            // 열쇠는 돌기, 자물쇠는 홈
                            if(Key[mRow][mCol] == 1 && lock[nRow][nCol] == 0)
                                count++;
                        }
                    }
                }
                if(valid && count == total)
                    answer = true;
                rotate++;
                rotateKey();
            }
        }
    }
    
    return answer;
}