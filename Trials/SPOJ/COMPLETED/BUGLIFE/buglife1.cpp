#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std; 
  
void addEdge(vector<vector<int>> &adj, int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
bool isBipartite(vector<vector<int>> adj, int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
    //cout<<"for adj[v] = "<<v<<endl;
    for (int u : adj[v]) { 
        //cout<<"for u:"<<u<<endl;
        //cout<<"if: "<<visited[u]<<endl;
        if (visited[u] == false) { 
  
            visited[u] = true; 
  
            color[u] = !color[v]; 
            //cout<<"color: "<<!color[v]<<endl;
  
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, nodes, query,a,b,N;
    cin>>cases;

    for (int jj = 1; jj <= cases; jj++)
    {
        cout<<"Scenario #"<<jj<<":"<<endl;
        cin>>nodes>>query;

        N = nodes; 
    
        vector<vector<int>> adj(N + 1); 
    
        vector<bool> visited(N + 1); 
    
        vector<int> color(N + 1); 
        //cout<<"vector created"<<endl;
    
        while (query--)
        {
            cin>>a>>b;
            //cout<<a<<" "<<b<<endl;
            addEdge(adj, a, b); 
        }
        
        cout<<"edge added"<<endl;
        for (auto &&x : adj)
        {
            for (auto &&z : x)
            {
                cout<<z<<" ";
            }
            cout<<endl;
        }
        
    
        visited[1] = true; 
        /*cout<<"v: ";
        for (auto &&x : visited)
        {
            cout<<x<<" ";
        }
        cout<<endl;*/
    
        color[1] = 0; 
        /*cout<<"c: ";
        for (auto &&x : color)
        {
            cout<<x<<" ";
        }
        cout<<endl;*/
    
        if (isBipartite(adj, 1, visited, color)==true) { 
            cout << "No suspicious bugs found!"<<endl; 
        } 
        else { 
            cout << "Suspicious bugs found!"<<endl; 
        } 
    }
    return 0; 
} 
