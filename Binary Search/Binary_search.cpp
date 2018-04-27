#include "bits/stdc++.h"
using namespace std;


int main(){
	int arr[] = {2, 2, 4, 4, 6, 8, 10};
	int key;
	cin>>key;
	vector<int>v;
	int end, begin, mid;
	int size = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+size);
	begin = 0;
	end = size-1;
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int index = 0;
	bool isFound = false;
	while(begin<=end){
		mid = (end - begin )/2 + begin;
		if(key==arr[mid]){
			isFound = true;
			break;
		}else if(key<arr[mid]){
			end = mid - 1;
		}
		else{
			begin = mid+1;
		}
	}

	if(isFound)
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;

	//built-in
	if(binary_search(arr, arr+size, key))
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;
	return 0;
}
