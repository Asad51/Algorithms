#include <cstdio>

struct Node
{
    int val;
    Node *next;
    Node(int val) : val(val), next(NULL) {}
};

bool isCycle(Node *head)
{
    Node *fast = head, *slow = head;
    if (!head || !head->next)
        return false;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    head->next = new Node(2);
    Node *newNode = new Node(3);
    head->next->next = newNode;
    newNode->next = head;
    if (isCycle(head))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
