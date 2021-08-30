#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



vector<int> parent;
vector<int> ranks;

void make_set(int v) {
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}



struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n,cost;
vector<Edge> edges; 

void kruskalMST(){
    vector<Edge> result;
    parent.resize(edges.size());
    ranks.resize(edges.size());
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, price, nodes, ed,a,b,z,temp;
    vector<int> cat;

    cin>>cases;

    while(cases--){
        cin>>nodes>>ed;
        n = ed;
        cost = 0;

        while (nodes--)
        {
            cin>>temp;
            cat.push_back(temp);
        }
        
        while (ed--){
            cin>>a>>b>>z;
            edges.push_back({a,b,z});
        }

        kruskalMST();
        cout<<cost<<endl;

        edges.clear();
    }

    return 0;
}