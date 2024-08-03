#include <iostream>
#include <string>

#define MAX_N 100

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    int starIdx;
    for(starIdx=0;starIdx<pattern.size();starIdx++){
        if(pattern[starIdx] == '*')
            break;
    }

    for(int n=0;n<N;n++){
        string file;
        cin >> file;

        if(pattern.size() > file.size()+1){
            cout << "NE" << '\n';
            continue;
        }

        bool valid = true;
        int i,j;
        for(i=0,j=0;i<starIdx && j < file.size();i++,j++){
            if(pattern[i] != file[j]){
                valid = false;
                break;
            }
        }

        if(i < starIdx) valid = false;

        for(i=pattern.size()-1,j=file.size()-1; i>starIdx && j >= 0; i--,j--){
            if(pattern[i] != file[j])
                valid = false;
        }

        if(i > starIdx) valid = false;

        if(valid) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }

    return 0;
}