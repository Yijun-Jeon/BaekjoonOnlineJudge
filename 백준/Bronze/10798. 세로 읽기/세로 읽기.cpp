#include <iostream>
using namespace std;

int main(void)
{
    string words[5];
    for(int i=0;i<5;i++){
        cin >> words[i];
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(words[j].length() < i+1)
                continue;
            cout << words[j][i];
        }
    }
    return 0;
}