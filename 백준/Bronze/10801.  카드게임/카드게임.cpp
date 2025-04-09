#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A[10], B[10];
    
    for(int i=0;i<10;i++)
        cin >> A[i];
    
    for(int i=0;i<10;i++)
        cin >> B[i];

    int result = 0;
    for(int i=0;i<10;i++){
        if(A[i] > B[i])
            result++;
        else if(A[i] < B[i])
            result--;
    }

    if(result > 0) cout << "A";
    else if(result == 0) cout << "D";
    else cout << "B";

    cout << '\n';
    return 0;
}