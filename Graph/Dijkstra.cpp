#include <cstdio>
#define INF 2147483647

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Queue
{
    int siz;
    Node *front, *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
        siz = 0;
    }

    void push(int n)
    {
        Node *newNode = new Node(n);
        if (front == NULL)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
        siz++;
    }

    void pop()
    {
        Node *tmp = front->next;
        delete (front);
        front = tmp;
        siz--;
    }

    int top()
    {
        return front->val;
    }

    int size()
    {
        return siz;
    }

    bool empty()
    {
        if (!siz)
            return true;
        return false;
    }
};

class Dijkstra
{
    int n, m, adj[101][101], visited[101], cost[101];

public:
    Dijkstra(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
            visited[i] = 0;
            cost[i] = INF;
        }
    }

    void getInput()
    {
        int u, v, c;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            adj[u][v] = adj[v][u] = c;
        }
    }

    void solve()
    {
        Queue q;
        q.push(0);
        cost[0] = 0;
        while (!q.empty())
        {
            int u = q.top();
            q.pop();
            visited[u] = 1;
            int node = 0, maxValue = INF;
            for (int v = 0; v < n; v++)
            {
                if (adj[u][v] && !visited[v] && adj[u][v] + cost[u] < cost[v])
                {
                    cost[v] = adj[u][v] + cost[u];
                }
                if (!visited[v] && cost[v] < maxValue)
                {
                    node = v;
                    maxValue = cost[v];
                }
            }
            if (node)
                q.push(node);
        }

        for (int u = 0; u < n; u++)
            printf("%d %d\n", u, cost[u]);
    }
};

int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        Dijkstra ds(n, m);
        ds.getInput();
        ds.solve();
    }

    return 0;
}
