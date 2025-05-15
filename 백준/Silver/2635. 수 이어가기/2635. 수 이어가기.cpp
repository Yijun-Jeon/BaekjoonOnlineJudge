#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

void DFS(int A, int B, vector<int> vec){
    vec.push_back(B);
    if(A < B){
        if(result.size() < vec.size())
            result = vec;
        return;
    }

    DFS(B,A-B,vec);
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> vec(1,N);
    for(int i=1;i<=N;i++)
        DFS(N,i,vec);


    cout << result.size() << '\n';
    if(result.empty())
        return 0;

    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << '\n';
    return 0;
}