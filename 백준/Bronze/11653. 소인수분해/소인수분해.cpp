#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    int n_sqrt = sqrt(n)+1;
    if(n % 2 == 0)
        return n == 2;
    for(int i=3;i<n_sqrt; i+=2){
        if(n%i == 0)
            return false;
    }
    return true && n != 1;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    if(isPrime(N)){
        cout << N << '\n';
        return 0;
    }
    int prime = 2;
    while(N > 1){
        if(isPrime(prime) && N % prime == 0){
            cout << prime << '\n';
            N /= prime;
        }else {
            prime = prime == 2 ? prime + 1 : prime + 2;
        }
    }
    return 0;
}