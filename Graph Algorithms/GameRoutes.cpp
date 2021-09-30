//Thursday 30-September-2021 22:49:46
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<int>adj[100005], adj_rev[100005];
vector<int>dp;
vector<int>topo;
vector<bool>vis;
void topology(int source) {
	vis[source] = true;
	for (auto x : adj[source]) {
		if (!vis[x])
			topology(x);
	}
	topo.push_back(source);
}
int main() {
	int n, m;
	cin >> n >> m;
	dp.resize(n + 1, 0);
	vis.resize(n + 1, false);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj_rev[y].push_back(x);
	}
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i] != true)
			topology(i);
	}
	reverse(all(topo));
	for (auto k : topo) {
		for (auto x : adj_rev[k]) {
			dp[k] = (dp[k] + dp[x]) % 1000000007;
		}
	}
	cout << dp[n] << endl;
}
