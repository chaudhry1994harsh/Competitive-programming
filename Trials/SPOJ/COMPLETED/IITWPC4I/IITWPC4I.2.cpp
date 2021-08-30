#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

typedef  pair<int, int> iPair; 
  

struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
  

    Graph(int V, int E) 
    { 
        this->V = V; 


        this->E = E; 
    } 
  
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
  
    int kruskalMST(); 
}; 
  

struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 

    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  

        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
  

    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 

    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  

        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  



int Graph::kruskalMST() 
{ 
    int mst_wt = 0; 
  
    sort(edges.begin(), edges.end()); 
  
    DisjointSets ds(V); 
  
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  

        if (set_u != set_v) 
        { 

            cout << u << " - " << v << endl; 

            mst_wt += it->first; 

            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, price, nodes, ed,a,b,z,temp;
    vector<int> cat;

    cin>>cases;

    while(cases--){
        unordered_map<int, int> mlk;
        cin>>nodes>>ed;

        Graph g(nodes, ed);
		int count = 0;

        for (int i = 1; i <= nodes; i++)
        {
            cin>>temp;
            mlk.insert({i,temp});
        }

        for (int i = 0; i < ed; i++)
        {
            cin>>a>>b>>z;
            g.addEdge(a,b,z);
        }
        
        g.kruskalMST();
    }

/*while (n1--) {
		unordered_map<int, int> milk;
		scanf("%i %i", &n2, &n3);
		Graph g(n2, n3);
		int count = 0;
		for (int i = 1; i <= n2; ++i) {
			scanf("%i", &n4);
			milk.insert(make_pair(i, n4));
		}

		while (n3--) {
			scanf("%i %i %ld", &a, &b, &c);

			g.addEdge(a, b, c);
		}

		g.kruskalMST(milk);

	}*/

    return 0;
}