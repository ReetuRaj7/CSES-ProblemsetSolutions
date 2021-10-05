//Tuesday 05-October-2021 23:15:23
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int INF = 1e17;

signed main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>>adj(n + 1, vector<pair<int, int>>());
	vector<vector<pair<int, int>>>adj_rev(n + 1, vector<pair<int, int>>());

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
		adj_rev[y].push_back({x, z});
	}
	vector<int>dist1(n + 1, INF), dist2(n + 1, INF);
	dist1[1] = 0;
	set<pair<int, int>>s;
	s.insert({0, 1});
	while (!s.empty()) {
		int q = s.begin()->second;
		s.erase(s.begin());
		for (auto e : adj[q]) {
			int to = e.first;
			int len = e.second;

			if (dist1[q] + len < dist1[to]) {
				s.erase({dist1[to], to});
				dist1[to] = dist1[q] + len;
				s.insert({dist1[to], to});
			}
		}
	}
	dist2[n] = 0;
	set<pair<int, int>>r;
	r.insert({0, n});
	while (!r.empty()) {
		int q = r.begin()->second;
		r.erase(r.begin());
		for (auto e : adj_rev[q]) {
			int to = e.first;
			int len = e.second;

			if (dist2[q] + len < dist2[to]) {
				r.erase({dist2[to], to});
				dist2[to] = dist2[q] + len;
				r.insert({dist2[to], to});
			}
		}
	}
	int ans = INF;
	for (int i = 1; i < n + 1; i++) {
		for (auto v : adj[i]) {
			ans = min(ans, dist1[i] + dist2[v.first] + v.second / 2);
		}
	}

	cout << ans << endl;
}