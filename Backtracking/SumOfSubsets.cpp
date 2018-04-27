#include "bits/stdc++.h"
using namespace std;

class SumOfSubsets
{
	int total;
	int subsetMark[1000];
	int target;
	int n;
public:
	SumOfSubsets(int size, int t, int tar){
		n = size;
		total = t;
		target = tar;
		for(int i=0; i<n; i++)
			subsetMark[i] = 0;
	}

	void printSubset(int set[], int mark){
		for(int i=0; i<n; i++){
			if(subsetMark[i]==1)
				cout<<set[i]<<" ";
		}
		cout<<endl;
	}

	void findSubset(int set[], int row, int sum2){
		if(sum2==target){
			printSubset(set, 1);
		}
		for(int i=row; i<n; i++){
			if( sum2+set[i] <=target){
				sum2 += set[i];
				subsetMark[i] = 1;
				findSubset(set, i+1, sum2);
				sum2 -= set[i];
				subsetMark[i] = 0;
			}
		}
	}
};


int main(int argc, char const *argv[])
{
	int set[] = {2, 3, 4, 5, 8};
	int target;
	int size = sizeof(set)/sizeof(set[0]);
	int total = 0;
	cout<<size<<endl;
	for(int i=0; i<size; i++){
		total += set[i];
	}
	while(scanf("%d", &target) != EOF){
		SumOfSubsets ss(size, total, target);
		ss.findSubset(set, 0, 0);
	}
	return 0;
}