#include "bits/stdc++.h"
using namespace std;

class GraphColoring
{
	int numOfNode;
	vector<int>color;
	int s;
public:
	GraphColoring(int n){
		numOfNode = n;
		for(int i=0; i<n; i++){
			color.push_back(-1);
		}
		s = 0;
	}

	void printSolution(){
		cout<<"Solution #"<<++s<<endl;
		for(int i=0; i<color.size(); i++){
			cout<<i<<":"<<color[i]<<endl;
		}
	}

	bool isSafe(vector< vector<int> > graph, int node, int col){
		//cout<<"N"<<node<<": C"<<col<<" : ";
		for(int i=0; i<graph[node].size(); i++){
			//cout<<"E"<<graph[node][i]<<" ";
			if(color[graph[node][i]]==col)
				return false;
		}
		//cout<<endl;
		return true;
	}

	void colorGraph(vector< vector<int> > graph, int node){
		if(node>=numOfNode){
			if(!s)
				printSolution();
			return;
		}
		//cout<<node<<endl;
		for(int i=0; i<3; i++){
			if(isSafe(graph, node, i)){
				color[node] = i;
				colorGraph(graph, node + 1);
				color[node] = -1;
			}
		}
	}
	
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v, n, e;
    vector< vector<int> > graph;
    cin>>n>>e;
    graph.resize(n);
    for(int i = 0; i<e; i++){
    	cin>>u>>v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    GraphColoring gc(n);
    gc.colorGraph(graph, 0);
	return 0;
}