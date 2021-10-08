//Friday 08-October-2021 17:46:32
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int INF = 1e11;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>>adj(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	vector<bool>vis(n + 1, false);
	vector<int>chosen(n + 1, INF);
	set<pair<int, int>>mst;
	mst.insert({0, 1}); //weight , to;
	int total = 0;
	for (int i = 1; i < n + 1; i++) {
		if (mst.empty()) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		int weight = mst.begin()->first;
		int from = mst.begin()->second;
		vis[from] = true;
		total += weight;
		mst.erase(mst.begin());
		for (auto a : adj[from]) {
			if (!vis[a.first] && a.second < chosen[a.first]) {
				mst.erase({chosen[a.first], a.first});
				chosen[a.first] = a.second;
				mst.insert({a.second, a.first});
			}
		}
	}
	cout << total << endl;
}