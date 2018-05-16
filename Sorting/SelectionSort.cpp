#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[] = {2, 5, 3, 10, 3, 4, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sm;
	for(int i=0; i<n; i++){
		sm = i;
		int j;
		for(j=i+1; j<n; j++){
			if(arr[j]<arr[sm])
				sm = j;
		}
		int tmp = arr[i];
		arr[i] = arr[sm];
		arr[sm] = tmp;
		cout<<arr[i]<<" ";
	}
 	cout<<endl;
	return 0;
}
