#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ncr(int n, int r){
	if(r>n)
		return 0;
	ll arr[n+1][r+1] = {{0}};
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=i && j<=r; j++){
    		if(j==1)
    			arr[i][j] = i;
    		else if(i==j)
    			arr[i][j] = 1;
    		else
    			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
    		//cout<<i<<j<<":"<<arr[i][j]<<" ";
    	}
    }
    return arr[n][r];
}

int main(int argc, char const *argv[])
{
	int n, r;
	while(cin>>n>>r){
		cout<<ncr(n, r)<<endl;
	}
	return 0;
}
