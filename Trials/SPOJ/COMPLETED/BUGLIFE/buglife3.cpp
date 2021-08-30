//works
//algo cp algo
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;



void bipart(int n, vector<vector<int>> adj){
    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    cout << (is_bipartite ? "No suspicious bugs found!" : "Suspicious bugs found!") << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz,nd,a,b;
    
    cin>>cases;

    for (int jj = 1; jj <= cases; jj++)
    {
        cout<<"Scenario #"<<jj<<":"<<endl;
        cin>>sz>>nd;
        vector<vector<int>> adj(sz +1);
        
        for (int i = 0; i < nd; i++)
        {
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        /*for (auto &&x : adj)
        {
            for (auto &&y : x)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }*/
         
        bipart(sz,adj);

    }

    return 0;
}