//Monday 27-September-2021 23:56:29
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
vector<int>adj[100005];
vector<bool>visited;

vector<int>topo;

void topological_order(int source) {
	visited[source] = true;
	for (auto v : adj[source]) {
		if (!visited[v])
			topological_order(v);
	}
	topo.push_back(source);
}


bool check_cycle(vector<int>&order, int source) {
	for (int x : adj[source]) {
		if (order[x] < order[source])
			return true;
	}
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	visited.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			topological_order(i);
	reverse(all(topo));
	vector<int>order(n + 1);
	int ind = 0;
	for (int i = 0; i < topo.size(); ++i) {
		order[topo[i]] = ind++;
	}
	visited.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		if (check_cycle(order, i)) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	for (auto x : topo)
		cout << x << ' ';
	cout << endl;

}