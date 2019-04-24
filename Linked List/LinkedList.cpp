#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
struct Node
{
    T val;
    Node *next;
    Node(T v)
    {
        this->val = v;
        this->next = NULL;
    }
};

template <class T>
class List
{
    int sz;
    Node<T> *head, *current, *nextNode;

public:
    List();
    List(T v);
    void insert(T v);
    void insert(T v, int index);
    void remove(T key);
    void removeAt(int pos);
    int size();
    bool find(T key);
    T next();
    void print();
    ~List();
};

/** Constructor without arguments**/
template <class T>
List<T>::List()
{
    sz = 0;
    current = head = nextNode = NULL;
}
/**
 * Constructor function
 * @params v : value of head node
 */
template <class T>
List<T>::List(T v)
{
    sz = 0;
    head = new Node<T>(v);
    current = NULL;
}

/**
 * insert a node into list
 * @params v : Value of new node
 */
template <class T>
void List<T>::insert(T v)
{
    sz++;
    Node<T> *node = new Node<T>(v);
    if (!head)
    {
        head = node;
        nextNode = head;
        return;
    }
    current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = node;
}

/**
 * insert a node into list in a specific position
 * @params[    
 *     v : Value of new node
 *     index : at which position, new node will be inserted, 
 *     0 for start position
 * ]
 */
template <class T>
void List<T>::insert(T v, int index)
{
    if (index > sz || sz < 0)
    {
        cout << "Invalid Index\n";
        printf("Enter index between 0 and %d\n", sz);
        return;
    }
    int tmp = 0;
    Node<T> *node = new Node<T>(v);
    current = head;
    if (!index)
    {
        node->next = head;
        head = node;
        sz++;
        return;
    }
    if (sz == index)
    {
        insert(v);
        return;
    }
    while (tmp < index - 1)
    {
        current = current->next;
        tmp++;
    }
    node->next = current->next;
    current->next = node;
    sz++;
}

/**
 * Delete node with the key
 * @params [ key: the value of the node which to be deleted]
 */
template <class T>
void List<T>::remove(T key)
{
    current = head;
    Node<T> *prev = NULL;
    while (current)
    {
        if (current->val == key)
        {
            if (!prev)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            sz--;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Node not found\n");
}

/**
 * Delete node with the key
 * @params [ pos: position of node ]
 */
template <class T>
void List<T>::removeAt(int pos)
{
    if (pos > sz || pos <= 0)
    {
        printf("Invalid position.\nPosition should 1 to %d\n", sz);
        return;
    }
    current = head;
    Node<T> *prev = NULL;
    int tmp = 0;
    while (tmp < pos - 1)
    {
        prev = current;
        current = current->next;
        tmp++;
    }

    if (!prev)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    sz--;
}

/**
 * Find a node with a value into the list
 * @params [ key: value of the node]
 * @return [ true if found node with the value or false]
 */
template <class T>
bool List<T>::find(T key)
{
    current = head;
    while (current)
    {
        if (current->val == key)
            return true;
        current = current->next;
    }
    return false;
}

template< class T>
T List<T>::next()
{
    if (!nextNode)
        nextNode = head;
    int v = nextNode->val;
    if (nextNode->next)
        nextNode = nextNode->next;
    else
        nextNode = NULL;
    return v;
}

/** Return the size of the list**/
template <class T>
int List<T>::size()
{
    return sz;
}

/** Display value of each node in a line**/
template <class T>
void List<T>::print()
{
    current = head;
    while (current)
    {
        cout << current->val << endl;
        current = current->next;
    }
}

/**Destructor Function**/
template <class T>
List<T>::~List()
{
    delete (head);
    delete (current);
}

int main(int argc, char const *argv[])
{
    List<int> list;
    for (int i = 1; i <= 5; i++)
        list.insert(i);
    list.insert(10, 0);
    list.print();
    //cout << list.size() << " " << list.find(8) << endl;
    return 0;
}
