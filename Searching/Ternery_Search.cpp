#include <bits/stdc++.h>
using namespace std;

class Ternery_Search
{
public:
	/**
	 * Searcching on whole array
	 * @param  arr [array]
	 * @param  n   [array size]
	 * @param  key [search key]
	 * @return     [position]
	 */
	int search(int arr[], int n, int key){
		int l = 0, r = n-1;
		while(l<=r){
			int mid1 = l + (r-l)/3;
			int mid2 = r - (r-l)/3;
			if(key==arr[mid1])
				return mid1;
			else if(key==arr[mid2])
				return mid2;
			else if(key<arr[mid1])
				r = mid1 - 1;
			else if(key>arr[mid2])
				l = mid2 + 1;
			else{
				l = mid1 + 1;
				r = mid2 - 1;
			}
		}
		return -1;
	}

	//searching on specific range of index
	int search(int arr[], int key, int l, int r){
		while(l<=r){
			int mid1 = l + (r-l)/3;
			int mid2 = r - (r-l)/3;
			if(key==arr[mid1])
				return mid1;
			else if(key==arr[mid2])
				return mid2;
			else if(key<arr[mid1])
				r = mid1 - 1;
			else if(key>arr[mid2])
				l = mid2 + 1;
			else{
				l = mid1 + 1;
				r = mid2 - 1;
			}
		}
		return -1;
	}
};

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 3, 5, 6, 8, 9};
	int key;
	int n = sizeof(arr)/sizeof(arr[0]);



	Ternery_Search ts;
	//cout<<ts.search(arr, 4, 1, 6)<<endl;
	while(cin>>key){
		int t = ts.search(arr, n, key);
		if(t != -1)
			cout<<"Found at "<< t+1 <<endl;
		else
			cout<<"Not Found\n";
	}
	return 0;
}
