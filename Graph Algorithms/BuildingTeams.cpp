//Friday 27-August-2021 22:46:53

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

void dfs(int source, bool &mark, vector<int>adj[], bool grp[], bool vs[], bool t = 0) {
	grp[source] = t;
	vs[source] = true;

	for (auto u : adj[source]) {
		if (vs[u]) {
			if (grp[u] == t)
				mark = true;
		} else {
			dfs(u, mark, adj, grp, vs, !t);
		}
	}
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool mark = false;
	bool vs[n + 1] = {false};
	bool grp[n + 1] = {false};
	for (int i = 0; !mark && i < n; i++) {
		if (vs[i] == false) {
			dfs(i, mark, adj, grp, vs);
		}
	}
	if (mark) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (int i = 0; i < n; i++)
			cout << grp[i] + 1 << " \n"[i == n - 1];
	}
	return 0;
}