#include "bits/stdc++.h"
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};

class Stack
{
	int siz;
	Node *current;
public:
	Stack(){
		current = NULL;
		siz = 0;
	}

	void push(int data){
		Node *newNode = new Node(data);
		if(current==NULL)
			current = newNode;
		else{
			newNode->prev = current;
			current->next = newNode;
			current = newNode;
		}
		siz++;
	}

	void pop(){
		if(current==NULL){
			cout<<"Underflow\n";
			return;
		}
		Node *tmp = current->prev;
		delete(current);
		current = tmp;
		siz--;
	}

	int top(){
		if(!siz){
			cout<<"Stack is empty\n";
			return -1;
		}
		return current->val;
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
	Stack st;
    for(int i=1; i<=10; i++){
        st.push(i);
    }
    cout<<st.size()<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
	return 0;
}