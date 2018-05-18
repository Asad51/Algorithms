/**
 *In this problem, one number appears one time and all other numbers appears two times
**/

#include<bits/stdc++.h>
using namespace std;

/*Using XOR*/
/* Other methods are are available in another file*/
int method1(int arr[], int n){
    int ones = 0;
    for(int i=0; i<n; i++){
        ones = ones ^ arr[i];
    }
    return ones;
}

int main(){
    int arr[] = {1, 2, 2, 1, 4, 3, 3};
    int sz = sizeof(arr)/sizeof(arr[0]);
    cout<<"Method1: "<<method1(arr, sz)<<endl;
    return 0;
}
