#include "bits/stdc++.h"
using namespace std;

#define MAX_VAL 6

class nQueens{
	vector<pair<int, int> >pos;
	int s;
public:
	nQueens(int n){
		pos.resize(n);
		s = 0;
	}

	bool isSafe(int grid[MAX_VAL][MAX_VAL], int row, int col, int n){
		//checking left side of same row
		for(int i=col-1; i>=0; i--){
			if(grid[row][i])
				return false;
		}

		//checking left side upper diagonal
		for(int i = row - 1, j = col -1 ; i>=0 && j>=0; i--, j--){
			if(grid[i][j])
				return false;
		}

		//checking left side lower diagonal
		for(int i = row + 1, j = col -1 ; i<n && j>=0; i++, j--){
			if(grid[i][j])
				return false;
		}

		return true;
	}

	int printNoSolution(){
		return s;
	}

	void printSolution(){
		cout<<"Solution #"<<++s<<"\n";
		for(int i=0; i<pos.size(); i++){
			cout<<pos[i].first<<","<<pos[i].second<<"\n";
		}
	}

	void solveQueens(int grid[MAX_VAL][MAX_VAL], int col, int n){
		if(col>=n){
			printSolution();
			return;
		}
		for(int i=0; i<n; i++){
			if(isSafe(grid, i, col, n)){
				pos[i] = make_pair(i, col);
				grid[i][col] = 1;
				solveQueens(grid, col + 1, n);
				grid[i][col] = 0;
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    nQueens nq(MAX_VAL);
    int grid[MAX_VAL][MAX_VAL] = {
    	{0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0}
    };
    /*int grid[MAX_VAL][MAX_VAL] = {{0, 0}, {0, 0}};*/
    nq.solveQueens(grid, 0, MAX_VAL);
    if(!nq.printNoSolution())
    	cout<<"No Solution"<<endl;
	return 0;
}