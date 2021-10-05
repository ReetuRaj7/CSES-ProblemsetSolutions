//Tuesday 05-October-2021 22:24:42
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int INF = 1e17;

signed main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>>edges;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back({x, y, z});
	}
	int x;
	vector<int>dist(n + 1);
	vector<int>par(n + 1, 0);
	for (int i = 0; i < n; i++) {
		x = -1;
		for (auto e : edges) {
			int u, w, v;
			tie(u, v, w) = e;
			if (dist[u] == INF)continue;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				par[v] = u;
				x = v;
			}

		}
	}
	if (x == -1)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int y = x;
		for (int i = 0; i < n; i++)
			y = par[y];
		vector<int>path;
		for (int current = y; ; current = par[current]) {
			path.push_back(current);
			if (current == y && path.size() > 1)
				break;
		}
		reverse(all(path));
		for (auto x : path)
			cout << x << " ";
	}
	return 0;
}