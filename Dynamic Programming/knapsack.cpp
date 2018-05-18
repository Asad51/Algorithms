#include "bits/stdc++.h"
using namespace std;

class knapsack{
	
public:
	int max(int a, int b){
		return (a > b) ? a : b;
	}

	int solution(int n, int w, int value[], int weight[]){
		int i, j;
		int x[n+1][w+1] = {{0}};
		for(i=0; i<=n; ++i){
			for(j=0; j<=w; ++j){
				if(i==0 || j==0)
					x[i][j] = 0;
				else if(weight[i-1]<=j)
					x[i][j] = max(value[i-1] + x[i-1][j - weight[i-1]], x[i-1][j]);
				else
					x[i][j] = x[i-1][j];
			}
		}
		return x[n][w];
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(0);

    int value[] = {72, 44, 31};
    int weight[] = {17, 23, 24};
    int n = sizeof(value)/sizeof(value[0]);
    int w = 26;
    knapsack kn;
    cout<<kn.solution(n, w, value, weight)<<"\n";
	return 0;
}