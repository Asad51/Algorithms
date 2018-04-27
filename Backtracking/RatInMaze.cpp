#include "bits/stdc++.h"
using namespace std;

#define MAX_VAL 6

class backtrack{
	vector<pair<int, int> >pos;
	int s;
	int n;
	int x, y;
public:
	backtrack(int dx,int dy){
		n = MAX_VAL;
		pos.resize(n);
		s = 0;
		x = dx;
		y = dy;
	}

	bool canRun(int maze[MAX_VAL][MAX_VAL], int row, int col){
		if(maze[row][col]==0 && row<=x && col<=y)
			return true;
		return false;
	}

	int printNoSolution(){
		return s;
	}

	void printSolution(int maze[MAX_VAL][MAX_VAL]){
		cout<<"Solution #"<<++s<<endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<setw(2)<<maze[i][j];
			}
			cout<<endl;
		}
	}

	void solveMaze(int maze[MAX_VAL][MAX_VAL], int row, int col){
		if(canRun(maze, row, col)){
			maze[row][col] = -1;
			if(row==x && col==y){
				printSolution(maze);
				maze[row][col] = 0;
				return;
			}
			solveMaze(maze, row, col + 1);
			solveMaze(maze, row + 1, col);
			maze[row][col] = 0;
		}
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int maze[MAX_VAL][MAX_VAL] = {
    	{0, 1, 0, 0, 0, 0}, 
    	{0, 0, 0, 1, 0, 0}, 
    	{0, 1, 0, 0, 1, 0}, 
    	{1, 0, 0, 0, 1, 0}, 
    	{0, 0, 0, 0, 0, 0}, 
    	{0, 1, 0, 1, 1, 0}
    };

    int sx, sy; //source point
    cin>>sx>>sy;
    int dx, dy;  //destination point
    cin>>dx>>dy;
    backtrack b(dx, dy);
    b.solveMaze(maze, sx, sy);
    if(!b.printNoSolution())
    	cout<<"No Solution"<<endl;
	return 0;
}