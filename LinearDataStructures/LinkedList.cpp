#include "bits/stdc++.h"
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class LinkedList{
	int length;
	Node* head;
	Node *current;
public:
	LinkedList();
	void insert(int data);
	void remove();
	int size();
};

LinkedList::LinkedList(){
	length = 0;
	this->head = NULL;
	this->current = NULL;
}

void LinkedList::insert(int data){
	length++;
	Node *newNode = new Node(data);
	current->next = newNode;
	current = newNode;
}

void LinkedList::remove(){
	
}

int LinkedList::size(){
	return length;
}

int main(int argc, char const *argv[])
{
	LinkedList list;
	list.insert(1);
	return 0;
}
