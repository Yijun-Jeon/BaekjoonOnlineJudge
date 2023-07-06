#include <iostream>
#define MAX_SIZE 10000
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    int count[MAX_SIZE+1] = {0};
    cin >> N;

    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        count[num]++;
    }

    int idx = 0;
    while(idx < MAX_SIZE+1){
        if(count[idx] != 0){
            cout << idx << '\n';
            count[idx]--;
        }
        else idx++;
    }
    return 0;
}