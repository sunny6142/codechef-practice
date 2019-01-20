#include<iostream> 
#include<list> 
#include <map>
#include <bits/stdc++.h>
using namespace std; 
  
class Graph 
{ 
    int V;    
  
    list<int> *adj; 

	public: map<int,int> mp;  
	public: map<int,int> group; 
public: map<int,int> cg; 
	public: long long height[100000];

	public: int h = 0;

			int g = 1;
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
 
    int DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 

    for(long long i = 0; i < 100000; i++) height[i] = 0;
} 
  
void Graph::addEdge(int v, int w) 
{ 
    
    adj[v].push_back(w); 

    
    adj[w].push_back(v);

} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    h++;
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
    
    if(mp[v] == 1)
    {
    	height[v] = h;
    	group[v] = g;
    //	cout << v << " = " <<h<<"\n";
    }
    else g++;    
    h--;
} 
int Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    DFSUtil(v, visited);

    int dif = -1;
    int a = -1,b = -1;
    int flag = 0;
    for(int i = 1;i < V; i++) 
    {
    	if(height[i] > 0)
    	{
    		cout<<i<<" - "<<height[i]<<" *"<<group[i]<<"\n";

    		if(cg[group[i]] == 0){
    			cg[group[i]] = group[i];
    		}
    		else if( cg[group[i]] != group[i]){
    			cout<<0<<"\n";
    			flag = 1;
    			break;
    		}

    		if(a == -1){
    			a == height[i];
    		}


    		else if(a != height[i] && b == -1)
    		{
				b == height[i];
    		}

    		else if(b != height[i] && dif == -1)
    		{
				cout<<0<<"\n";
				flag = 1;
				break;
    		}
    	}

    	return flag;
    }
} 

int main()
{
	long long  i, itr, j, k, l, a, b,n;
	
	cin>>itr;

	while(itr--)
	{
		Graph g(100000); 

		cin>>a>>b;
		
		long long heigth[100000];
		
		for(n = 1; n < a; n++)
		{
			cin>>k>>l;

			g.mp[k]++;
			g.mp[l]++;
    		g.addEdge(k, l); 
		}

		if(g.DFS(1) == 0){

			cout<<ceil((float)b/(float)a);
		}

	}
}