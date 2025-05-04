#include <iostream>

using namespace std;

int N;
bool used[10];

bool checkIsValid(int n){
    string s = to_string(n);

    bool changed[10] = {false};
    for(int i=0;i<s.size();i++){
        if(used[s[i] - '0']){
            for(int j=0;j<10;j++){
                if(changed[j])
                    used[j] = false;
            }
            return false;
        }
        else{
            used[s[i] - '0'] = true;
            changed[s[i] - '0'] = true;    
        }
    }
    return true;
}

bool DFS(int n){
    if(n > 0 && checkIsValid(N-n)){
        cout << n << " + " << N-n << '\n';
        return true;
    }

    for(int i=0;i<10;i++){
        if(n == 0 && i == 0)
            continue;
        
        if(used[i]) 
            continue;
        
        if((n*10 + i) > N/2)
            break;

        used[i] = true;
        if(DFS(n*10 + i))
            return true;
        used[i] = false;
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    if(DFS(0) == false)
        cout << -1 << '\n';
    return 0;
}