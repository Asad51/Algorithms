#include "iostream"
using namespace std;

class InsertionSort
{
public:
	void sort(int n, int arr[]){
		for(int i=0; i<n; i++){
			int x=arr[i];
			int j=i-1;
			for(; j>=0; j--){
				if(arr[j]>x){
					arr[j+1] = arr[j];
				}
				else
					break;
			}
			arr[j+1] = x;
		}
		printSortedArray(n, arr);
	}

	void printSortedArray(int n, int arr[]){
		for(int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	int nums[] = {30, 4, 3, 2, 12, 23, 10};
	int n = sizeof(nums)/sizeof(nums[0]);
	InsertionSort is;
	is.sort(n, nums);
	return 0;
}