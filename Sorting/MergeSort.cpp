#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
	int tmp[r-l+1];
	int i, j, k, p;
	for(i=l, j=l, k=m+1, p=0; i<=r; i++, p++){
		if(j==m+1){
			tmp[p] = arr[k++];
		}
		else if(k==r+1){
			tmp[p] = arr[j++];
		}
		else if(arr[k]<arr[j]){
			tmp[p] = arr[k++];
		}
		else
			tmp[p] = arr[j++];
	}

	for(i = l, p=0; i<=r; i++, p++){
		arr[i] = tmp[p];
	}
}

void mergeSort(int arr[], int l, int r){
	if(l==r)
		return;
	int mid =  (l + r)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, mid, r);
}

int main(int argc, char const *argv[])
{
	int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}