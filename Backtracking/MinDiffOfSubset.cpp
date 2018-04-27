#include "bits/stdc++.h"
using namespace std;

class SumOfSubsets
{
	int total;
	int minDiff;
	int n;
public:
	SumOfSubsets(int size, int t){
		n = size;
		total = t;
		minDiff = t;
	}

	void printMinDiff(){
		cout<<minDiff<<endl;
	}

	void findSubset(int set[], int row, int sum){
		minDiff = min(minDiff, abs(total - 2*sum));
		if(row>=n){
			return;
		}
		for(int i=row; i<n; i++){
			sum += set[i];
			findSubset(set, i+1, sum);
			sum -= set[i];
		}
	}
};


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int size;
		cin>>size;
		int total = 0;
		int set[size];
		for(int i=0; i<size; i++){
			cin>>set[i];
			total += set[i];
		}
		SumOfSubsets ss(size, total);
		ss.findSubset(set, 0, 0);
		ss.printMinDiff();
	}
	return 0;
}