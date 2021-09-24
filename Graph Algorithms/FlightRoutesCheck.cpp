//Friday 24-September-2021 23:23:46
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
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
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	component;
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
	int cnt = 0;
	while (!order.empty()) {
		int i = order.top();
		order.pop();
		if (!used[i]) {
			if (cnt < 1) {
				dfs2(i, adj_rev);
				cnt++;
			} else {
				cout << "NO" << endl;
				cout << i << " " << component.back() << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}