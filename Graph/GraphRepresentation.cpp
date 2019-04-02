#include <iostream>
#include <cstdio>
using namespace std;

struct node{
	int val;
	struct node *next;
	node(int val){
		this->val = val;
		this->next = NULL;
	}
};

node* insert_node(node* head, int val){
	node *newNode = new node(val);

	if(head == NULL){
		head = newNode;
		return head;
	}
	node *current = head;
	while(current->next){
		current = current->next;
	}
	current->next = newNode;
	return head;
}

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	int adj_matrix[n + 1][n + 1] = { { 0 } };
	node* adj_list[n + 1] = { NULL };
	int x, y;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		adj_matrix[x][y] = 1;
		adj_matrix[y][x] = 1;
		adj_list[x] = insert_node(adj_list[x], y);
		adj_list[y] = insert_node(adj_list[y], x);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", adj_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(int i = 1; i <= n; i++){
		node* current = adj_list[i];
		while(current){
			printf("%d ", current->val);
			current = current->next;
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
