#include <bits/stdc++.h>
using namespace std;

class Queue
{
	int siz, front, back, mx_size;
	int arr[10];
public:
	Queue(){
		siz = 0;
		front = -1;
		back = -1;
		mx_size = 10;
	}

	void push(int data){
		if(siz>=mx_size){
			cout<<"Overflow\n";
			return;
		}
		if(back==-1){
			arr[++back] = data;
			front++;
		}
		else if(back>=mx_size-1){
			back = 0;
			arr[back] = data;
		}
		else
			arr[++back] = data;
		siz++;
	}

	void pop(){
		if(!siz){
			cout<<"Underflow\n";
			return;
		}
		else if(front>=mx_size-1){
			front = 0;
		}
		else
			front++;
		siz--;
	}

	int size(){
		return siz;
	}

	int top(){
		if(!siz){
			cout<<"Queue is empty\n";
			return arr[-1];
		}
		return arr[front];
	}

	bool empty(){
		if(!siz)
			return true;
		return false;
	}
};

int main(int argc, char const *argv[])
{
	Queue q;
	for(int i=1; i<=30; i++){
		int t = rand()%10;
		if(i%2==1){
			q.push(t*t);
		}
		else{
			cout<<q.top()<<" ";
			q.pop();
		}
	}
	return 0;
}
