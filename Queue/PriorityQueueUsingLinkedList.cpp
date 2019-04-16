#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int val){
		this->val = val;
		this->next = NULL;
	}
};

class PriorityQueue{
	int siz;
	Node *front, *current;
public:
	PriorityQueue(){
		siz = 0;
		front = current = NULL;
	}

	void push(int v){
		Node *prev = NULL, *newNode = new Node(v);
		siz++;
		if(front==NULL){
			front = newNode;
			return;
		}
		current = front;
		while(current && current->val > v){
			prev = current;
			current = current->next;
		}
		if(!prev){
			newNode->next = current;
			front = newNode;
		}
		else{
			prev->next = newNode;
			newNode->next = current;
		}
	}

	void pop(){
		front = front->next;
		siz--;
	}

	int top(){
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

	void print(){
		current = front;
		while(current){
			printf("%d\n", current->val);
			current = current->next;
		}
	}

	~PriorityQueue(){
		delete (front);
		delete (current);
	}
};

int main(int argc, char const *argv[])
{
	int arr[6] = {4, 3, 5, 2, 6, 1};
	PriorityQueue pq;
	for(int i = 0; i < 6; i++)
		pq.push(arr[i]);
	//pq.print();
	printf("%d\n", pq.size());
	while(!pq.empty()){
		printf("%d\n", pq.top());
		pq.pop();
	}
	printf("%d\n", pq.size());
	return 0;
}
