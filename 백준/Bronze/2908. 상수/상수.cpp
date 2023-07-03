#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string A, B;
    cin >> A >> B;

    swap(A[0], A[2]);
    swap(B[0], B[2]);

    cout << max(stoi(A), stoi(B)) << endl;
    return 0;
}