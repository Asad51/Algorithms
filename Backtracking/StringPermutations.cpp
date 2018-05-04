#include "bits/stdc++.h"
using namespace std;

class StringPermutations
{
public:
	void permute(string s, int start, int end){
		if(start==end){
			cout<<s<<"\n";
			return;
		}
		for(int i=start; i<=end; i++){
			swap(s[start], s[i] );
			permute(s, start + 1, end);
			swap(s[start], s[i] );
		}
	}
};

int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s){
		StringPermutations ss;
		ss.permute(s, 0, s.size()-1);
	}

	return 0;
}
