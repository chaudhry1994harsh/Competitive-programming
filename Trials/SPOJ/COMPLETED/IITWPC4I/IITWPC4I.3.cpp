//algo from geeks4geeks: kruskals-minimum-spanning-tree-using-stl-in-c
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;


typedef pair<int, int> iPair;

struct DisjointSets {
	int *parent, *rnk;
	int n;

	DisjointSets(int n) {
		// Allocate memory
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];

		for (int i = 0; i <= n; i++) {
			rnk[i] = 0;
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	int Union(int x, int y) {
		x = find(x), y = find(y);

		if (rnk[x] > rnk[y]) {
			parent[y] = x;
			return x;
		} else {
			parent[x] = y;
			return y;
		}

		if (rnk[x] == rnk[y]) {
			rnk[y]++;
		}
	}
};

struct Graph {
	int V, E;
	vector<pair<int, iPair> > edges;

	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}

	void addEdge(int u, int v, long w) {
		edges.push_back(make_pair(w, make_pair(u, v)));
	}

	void kruskalMST(unordered_map<int, int> milk) {
		long mst_wt = 0;

		sort(edges.begin(), edges.end());

		DisjointSets ds(V);

		unordered_map<int, int> noMilk;
		vector<pair<int, iPair> >::iterator it;
		for (it = edges.begin(); it != edges.end(); it++) {
			int u = it->second.first;
			int v = it->second.second;

			int set_u = ds.find(u);
			int set_v = ds.find(v);
			//cout << "1:" << u << " " << v << endl;
			//cout << "  2:" << set_u << " " << set_v << endl;
			if (set_u != set_v) {
				if (!milk[set_u] || !milk[set_v]) {
					mst_wt += it->first;
				}
				int p = ds.Union(set_u, set_v);
				if (milk[set_u] || milk[set_v]) {
					milk[u] = 1;
					milk[v] = 1;
					milk[p] = 1;
				}

			}
		}
		bool flag = true;
		for (auto &x : milk) {
			//cout << x.first << "-"<< milk[ds.find(x.first)] << " ";
			if (!milk[ds.find(x.first)]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << mst_wt << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
};

int main() {

	int n1, n2, n3, n4, a, b;
	long c;
	scanf("%i", &n1);

	while (n1--) {
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

	}
}