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
		v.push_back(arr[i]);
	}
	cout<<endl;
	int index = 0;

	while(begin<=end){
		mid = (end - begin )/2 + begin;
		if(key<arr[mid]){
			end = mid - 1;
		}
		else{
			begin = mid + 1;
		}
	}

	cout<<"upper_bound = "<<begin<<endl;
	cout<<"upper_bound :"<<upper_bound(arr, arr + size, key) - arr<<endl;
	//cout<<"upper_bound :"<<upper_bound(v.begin(), v.end(), key) - v.begin()<<endl;

	return 0;
}
