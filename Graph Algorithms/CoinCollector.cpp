//Saturday 25-September-2021 00:11:13
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<int>component;
vector<bool>used;
stack<int>order;

void dfs1(int source, vector<int>adj[]) {
	used[source] = true;
	for (auto v : adj[source]) {
		if (used[v] == false)
			dfs1(v, adj);
	}
	order.push(source);
}
void dfs2(int source, vector<int>adj_rev[]) {
	used[source] = true;
	component.push_back(source);
	for (auto v : adj_rev[source])
		if (!used[v])
			dfs2(v, adj_rev);
}
signed main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<int>values(n);
	for (auto&x : values)cin >> x;
	used.resize(n + 1, false);
	vector<int>adj[n + 1], adj_rev[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj_rev[y].push_back(x);
	}
	for (int i = 1; i < n + 1; i++) {
		if (used[i] == false) {
			dfs1(i, adj);
		}
	}
	used.assign(n + 1, false);
	vector<int>roots(n + 1), root_nodes;
	vector<int>sums(n + 1);
	while (!order.empty()) {
		int i = order.top();
		order.pop();
		if (!used[i]) {
			dfs2(i, adj_rev);
			int root = component.front();
			int sum = 0;
			for (auto u : component) {
				roots[u] = root;
				sum += values[u - 1];
			}
			sums[root] = sum;
			root_nodes.push_back(root);
		}
		component.clear();
	}
	//adjacency matrix of condensation graph.
	vector<int>adj_scc[n + 1];
	for (int i = 1; i < n + 1; i++) {
		for (auto x : adj[i]) {
			int root_source = roots[i];
			int root_destination = roots[x];
			if (root_destination != root_source)
				adj_scc[root_source].push_back(root_destination);
		}
	}
	reverse(all(root_nodes));
	for (auto x : root_nodes) {
		int val = sums[x];
		for (auto v : adj_scc[x]) {
			val = max(val, sums[x] + sums[v]);
		}
		sums[x] = val;
	}
	cout << *max_element(all(sums)) << endl;
	return 0;
}
