#include "bits/stdc++.h"
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};

class Deque
{
	int siz;
	Node *head, *tail;
public:
	Deque()
	{
		siz = 0;
		head = NULL;
		tail = NULL;
	}

	void push_back(int data){
		Node *newNode = new Node(data);
		if(tail==NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			Node *tmp = tail;
			tail->next = newNode;
			tail = newNode;
			tail->prev = tmp;
		}
		siz++;
	}

	void push_front(int data){
		Node *newNode = new Node(data);
		if(head==NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			Node *tmp = head;
			head->prev = newNode;
			head = newNode;
			head->next = tmp;
		}
		siz++;
	}
	
	void pop_back(){
		if(!siz){
			cout<<"Queue is empty\n";
			return;
		}
		else if(tail->prev == NULL){
			delete(tail);
		}
		else{
			Node *tmp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete(tmp);
		}
		siz--;
	}

	void pop_front(){
		if(!siz){
			cout<<"Queue is empty\n";
			return;
		}
		else if(head->next == NULL){
			delete(head);
		}
		else{
			Node *tmp = head;
			head = head->next;
			head->prev = NULL;
			delete(tmp);
		}
		siz--;
	}

	int back(){
		if(!siz){
			cout<<"Queue is empty\n";
			return -1;
		}
		return tail->val;
	}

	int front(){
		if(!siz){
			cout<<"Queue is empty\n";
			return -1;
		}
		return head->val;
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
	Deque dq;
	for(int i=1; i<=10; i++){
		dq.push_back(i);
		dq.push_front(i*i);
	}
	cout<<dq.size()<<endl;
	while(!dq.empty()){
		cout<<dq.front()<<":"<<dq.back()<<endl;
		dq.pop_back();
		dq.pop_front();
	}
	cout<<dq.size()<<endl;
	return 0;
}