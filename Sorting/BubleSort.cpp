#include "iostream"
using namespace std;

class BubleSort
{
public:
	void sort(int n, int arr[]){
		int i, j;
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				if(arr[i]>arr[j])
				{
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
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
	BubleSort bs;
	bs.sort(n, nums);
	return 0;
}
