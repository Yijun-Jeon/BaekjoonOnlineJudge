#include <iostream>
#include <algorithm>

#define MAX_N 500000

using namespace std;

string S;
int N,result = MAX_N;

void makeGroup(char c){
    // c -> left
    int move = 0;
    bool jump = false;
    for(int i=0;i<N;i++){
        if(S[i] == c){
            if(jump)
                move++;
        }else jump = true;
    }
    result = min(result,move);
    
    // c -> right
    move = 0;
    jump = false;
    for(int i=N-1;i>=0;i--){
        if(S[i] == c){
            if(jump)
                move++;
        }else jump = true;
    }
    result = min(result,move);
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N >> S;

    makeGroup('R');
    makeGroup('B');

    cout << result << '\n';
    return 0;
}