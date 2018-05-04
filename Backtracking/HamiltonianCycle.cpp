#include "iostream"
#include "vector"
#include "stdio.h"
using namespace std;

class HamiltonianCycle
{
	int n, e;
	vector<int>path;
	int visited[1024];
	int s;
public:
	HamiltonianCycle(int nn, int ee){
		n = nn;
		e = ee;
		s = 0;
		for(int i=0; i<=n; i++){
			path.push_back(-1);
			if(i==n)
				continue;
			visited[i] = 0;
		}
	}	

	void printCycle(){
		cout<<"Solution #"<<++s<<"\n";
		for(int i=0; i<path.size(); i++)
			cout<<path[i]<<" ";
		cout<<"\n";
	}

	int printNoSolution(){
		return s;
	}

	void findCycle(vector< vector<int> >adj, int node, int count){
		if(node==0 && count==n){
			path[count] = node;
			printCycle();
			return;
		}
		if(visited[node])
			return;
		//cout<<node<<":"<<count<<endl;
		visited[node] = 1;
		path[count] = node;
		for(int i=0; i<adj[node].size(); i++){
			findCycle(adj, adj[node][i], count + 1);
		}
		visited[node] = 0;
		path[count] = -1;
	}
};

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int n, e;
	while(scanf("%d%d", &n, &e)!=EOF){
		vector< vector<int> >adj;
		adj.resize(n);
		for(int i=0; i<e; i++){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		HamiltonianCycle hc(n, e);
		hc.findCycle(adj, 0, 0);
		if(!hc.printNoSolution())
			cout<<"No Solution\n";
		cout<<"\n";
		adj.clear();
	}
	return 0;
}