#include "bits/stdc++.h"
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Queue
{
	int siz;
	Node *front, *back;
public:
	Queue(){
		front = NULL;
		back = NULL;
		siz = 0;
	}

	void push(int n){
		Node *newNode = new Node(n);
		if(front==NULL){
			front = newNode;
			back = newNode;
		}
		else{
			back->next = newNode;
			back = newNode;
		}
		siz++;
	}

	void pop(){
		if(front==NULL){
			cout<<"Underflow\n";
			return;
		}
		Node *tmp = front->next;
		delete(front);
		front = tmp;
		siz--;
	}

	int top(){
		if(!siz){
			cout<<"Queue is empty\n";
			return -1;
		}
		return front->val;
	}

	int size(){
		return siz;
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
	for(int i=1; i<=10; i++){
		q.push(i*i);
	}
	cout<<q.size()<<endl;
	while(!q.empty()){
		cout<<q.top()<<" " << q.size() << endl;
		q.pop();
	}
	return 0;
}