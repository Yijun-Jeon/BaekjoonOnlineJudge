#include <iostream>
#include <algorithm>

#define MAX_N 500000

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    int result = MAX_N;
    
    // R -> left
    string temp = S;
    int idx = temp[0] == 'R' ? 1 : 0;
    int move = 0;
    for(int i=1;i<N;i++){
        if(temp[i] == 'R'){
            if(temp[i-1] == 'B'){
                swap(temp[idx],temp[i]);
                move++;
            }
            idx++;
        }
    }
    result = min(result,move);
    
    // R -> right
    temp = S;
    idx = temp[N-1] == 'R' ? N-2 : N-1;
    move = 0;
    for(int i=N-2;i>=0;i--){
        if(temp[i] == 'R'){
            if(temp[i+1] == 'B'){
                swap(temp[idx],temp[i]);
                move++;
            }
            idx--;
        }
    }
    result = min(result,move);

    // B -> left
    temp = S;
    idx = temp[0] == 'B' ? 1 : 0;
    move = 0;
    for(int i=1;i<N;i++){
        if(temp[i] == 'B'){
            if(temp[i-1] == 'R'){
                swap(temp[idx],temp[i]);
                move++;
            }
            idx++;
        }
    }
    result = min(result,move);

    // B -> right
    temp = S;
    idx = temp[N-1] == 'B' ? N-2 : N-1;
    move = 0;
    for(int i=N-2;i>=0;i--){
        if(temp[i] == 'B'){
            if(temp[i+1] == 'R'){
                swap(temp[idx],temp[i]);
                move++;
            }
            idx--;
        }
    }
    result = min(result,move);

    cout << result << '\n';
    return 0;
}