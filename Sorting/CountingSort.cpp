#include "iostream"
using namespace std;

//only for positive vauled array
class CountingSort
{
public:
	void sort(int n, int arr[]){
		int mx = -1, sortedArray[n];
		for(int i=0; i<n; i++){
			mx = max(mx, arr[i]);
		}
		int count[mx+1] = {0};
		for(int i=0; i<n; i++){
			count[arr[i]]++;
		}
		for(int i=1; i<=mx; i++){
			count[i] += count[i-1];
		}
		for(int i=0; i<n; i++){
			int tmp = count[arr[i]];
			sortedArray[tmp-1] = arr[i];
			count[arr[i]]--;
		}

		printSortedArray(n, sortedArray);
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
	int nums[] = {10, 4, 3, 2, 7, 5, 9};
	int n = sizeof(nums)/sizeof(nums[0]);
	CountingSort cs;
	cs.sort(n, nums);
	return 0;
}