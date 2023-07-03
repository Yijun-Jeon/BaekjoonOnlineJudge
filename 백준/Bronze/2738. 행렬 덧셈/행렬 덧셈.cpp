#include <iostream>
using namespace std;

int main(void)
{
    int A[100][100] = {};
    int B[100][100] = {};

    int N,M;
    cin >> N >> M;

    for(int j=0;j<N;j++){
        for(int k=0;k<M;k++){
            cin >> A[j][k];       
        }
    }
    for(int j=0;j<N;j++){
        for(int k=0;k<M;k++){
            cin >> B[j][k];       
        }
    }
    for(int j=0;j<N;j++){
        for(int k=0;k<M;k++){
            cout << A[j][k] + B[j][k] << " ";    
        }
        cout << endl;
    }
    return 0;
}