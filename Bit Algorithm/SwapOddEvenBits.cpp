#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	unsigned int n;
	while(cin>>n){
		unsigned int even = n & 0xAAAAAAAA;
		unsigned int odd = n & 0x55555555;
		even >>= 1;
		odd <<= 1;
		cout << (even|odd) <<endl;
	}
	return 0;
}
