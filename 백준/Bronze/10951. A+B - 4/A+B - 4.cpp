#include <iostream>
using namespace std;

int main(void)
{
    int A, B;
    while (true)
    {
        cin >> A >> B;
        if (cin.eof())
            break;
        cout << A + B << endl;
    }

    return 0;
}
