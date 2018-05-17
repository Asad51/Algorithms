#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[] = {2, 1, 3, 5, 3, 5, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x;
	while(cin>>x){
		bool isFound = false;
		int index = 0;
		for(int i=0; i<n; i++){
			if(arr[i]==x){
				isFound = true;
				index = i;
				break;
			}
		}
		if(isFound)
			cout<<"Found at " << index+1<<endl;
		else
			cout<<"Not Found\n";
	}
	return 0;
}
