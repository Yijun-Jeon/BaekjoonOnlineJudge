#include <iostream>
using namespace std;

int main(void)
{
    string S;
    while (!cin.eof())
    {
        getline(cin, S);
        cout << S << endl;
    }
    return 0;
}