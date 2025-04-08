#include <iostream>

using namespace std;

int cols[2] = {-1,1};

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ROW,COL;
    int Ac,D,Sr,Sc;

    cin >> ROW >> COL;
    cin >> Ac >> D;
    cin >> Sr >> Sc;

    int Ar = 1;
    while(true){
        if(Ar == ROW && Ac == COL)
            break;
        if(Ar == Sr && Ac == Sc){
            cout << "NO..." << '\n';
            return 0;
        }

        if((D == 0 && Ac == 1) || (D == 1 && Ac == COL)){
            Ar++;
            D ^= 1;
        }else{
            Ac += cols[D];
        }
    }
    cout << "YES!" << '\n';
    return 0;
}