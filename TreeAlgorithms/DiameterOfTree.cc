//Tuesday 11-January-2022 11:49:02
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<vector<int>>adj(200005, vector<int>());
int dfs(int ch, int par, lli& res) {
	vector<lli>ans;
	for (auto x : adj[ch]) {
		if (x != par) {
			ans.push_back(dfs(x, ch, res));
		}
	}
	if (ans.size() == 0)return 0;
	sort(all(ans), greater<lli>());
	lli t = ans.front();
	if (ans.size() >= 2)
		res = max(res, ans[1] + ans[0] + 2);
	else
		res = max(res, t + 1);
	return 1 + t;

}
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	lli res = 0;
	int t = dfs(1, 0, res);
	cout << res << endl;
}