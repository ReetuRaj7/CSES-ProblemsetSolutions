//Sunday 05-September-2021 17:43:18

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int
#define int long long int
#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
vector<int>d;
vector<int>par;


const int INF = 100000000000000;
struct node {
	int destination;
	int cost;
};
bool operator <(const node & left, const node & right) {
	if (left.cost != right.cost )return left.cost < right.cost;
	if (left.destination != right.destination)return left.destination < right.destination;
	return false;
}


signed main() {
	fastio;
	int n, m;
	cin >> n >> m;
	d.assign(n + 1, INF);
	par.assign(n + 1, -1);
	vector<vector<node>>adj(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
	}
	set<node>s;
	// for (node x : s) {
	// 	cout << x.source << " " << x.destination << " " << x.cost << endl;
	// }
	d[1] = 0;
	s.insert({1, 0});
	while (!s.empty()) {
		int f = s.begin()->destination;
		s.erase(s.begin());
		for (node i : adj[f]) {
			int to = i.destination;
			int cost = i.cost;
			// cout << to << " " << cost << endl;
			if (d[f] + cost < d[to]) {
				s.erase({to, d[to]});
				d[to] = cost + d[f];
				par[to] = f;
				s.insert({to, d[to]});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}

	cout << endl;
}