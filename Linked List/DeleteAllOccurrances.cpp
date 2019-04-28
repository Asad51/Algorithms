#include <cstdio>

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(NULL) {}
};

Node *deleteAllOccurrances(Node *head, int val)
{
    Node *newHead = new Node(-1);
    newHead->next = head;
    Node *current = newHead;
    while (current)
    {
        if (current->next && current->next->data == val)
            current->next = current->next->next;
        else
            current = current->next;
    }
    return newHead->next;
}

void print(Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    int arr[10] = {1, 2, 3, 1, 5, 7, 2, 4, 8, 1};
    Node *current = head;
    for (int i = 0; i < 10; i++)
    {
        Node *newNode = new Node(arr[i]);
        current->next = newNode;
        current = newNode;
    }
    int val;
    scanf("%d", &val);
    head = deleteAllOccurrances(head, val);
    print(head);
    return 0;
}
