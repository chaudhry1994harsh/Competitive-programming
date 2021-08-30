//algo-code from cp-algorithms: topological sort
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 

  

int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    //reverse(ans.begin(), ans.end());

    for(int i = 1; i <= n ; i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,a,b;

    cin>>n>>cases;
    adj.resize(n+1);
    visited.reserve(n+1);
    ans.resize(n+1);

    while (cases--)
    {
        cin>>a>>b;
        adj[b].push_back(a);
    }
    topological_sort();

    
    return 0; 

}