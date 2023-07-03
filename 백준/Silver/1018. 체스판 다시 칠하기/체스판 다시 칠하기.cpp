#include <iostream>
#include <vector>
#define MIN(A,B) (((A) < (B)) ? (A) : (B))
using namespace std;

int check(vector<vector<int> > board, int y, int x){
	int sumB = 0, sumW = 0, color = 0;
	for(int i=y;i<y+8;i++){
		for(int j=x;j<x+8;j++){
			if(board[i][j] != color)
				sumB++;
			color ^= 1;
		}
		color ^= 1;
	}
	color ^= 1;
	for(int i=y;i<y+8;i++){
		for(int j=x;j<x+8;j++){
			if(board[i][j] != color)
				sumW++;
			color ^= 1;
		}
		color ^= 1;
	}
	
	return MIN(sumW,sumB);
}

int main(void)
{
	int N,M;
	int min = 32;
	cin >> N >> M;

	vector<vector<int> > board(N);
	for(int i=0;i<N;i++){
		string temp;
		cin >> temp;
		for(int j=0;j<M;j++){
			board[i].push_back(temp[j] == 'B'); 
		}	
	}
	
	for(int i=0;i<=N-8;i++){
		for(int j=0;j<=M-8;j++)
			min = MIN(min,check(board,i,j));
	}
	
	cout << min << endl;
    return 0;
}