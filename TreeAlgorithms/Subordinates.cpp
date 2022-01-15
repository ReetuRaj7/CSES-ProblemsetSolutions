//Saturday 15-January-2022 11:22:42
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<vector<int>>adj(200005, vector<int>());
int subor[200005];
int dfs(int src, int parent) {
	int cur = 1;
	for (auto A : adj[src]) {
		if (A != parent) {
			cur += dfs(A, src);
		}
	}
	return subor[src] = cur;
}
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	subor[1] = dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << subor[i] - 1 << " ";
	}
	return 0;
}