#include "bits/stdc++.h"
using namespace std;

class EgyptianFraction
{
public:
	void printEgyptianFraction(int nr, int dr){
		if(nr==0 || dr==0)
			return;
		if(nr%dr==0){
			cout<<nr/dr<<endl;
			return;
		}
		if(dr%nr==0){
			cout<<1<<"/"<<dr/nr<<endl;
			return;
		}

		if(nr>dr){
			cout<<nr/dr<<" + ";
			printEgyptianFraction(nr%dr, dr);
			return;
		}

		int n = dr/nr + 1;
    	cout<<1<<"/"<<n<<" + ";
    	printEgyptianFraction(nr*n-dr, dr*n);
	}
	
};

int main(int argc, char const *argv[])
{
	int nr, dr;
	while(cin>>nr>>dr){
		cout<<"Representation of "<<nr<<"/"<<dr<<" is : \n";
		EgyptianFraction e;
		e.printEgyptianFraction(nr, dr);
	}
	return 0;
}