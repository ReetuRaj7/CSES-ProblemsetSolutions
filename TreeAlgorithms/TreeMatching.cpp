//Friday 17-December-2021 23:38:07
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
vector<vector<int>>adj(200005, vector<int>());
int ans = 0;
bool marked[200005] = {false};

void parenting_dfs(int source, int parent) {
	for (int i = 0; i < adj[source].size(); i++) {
		if (adj[source][i] != parent) {
			parenting_dfs(adj[source][i], source);
		}
	}
	if (!marked[source] && !marked[parent] && parent != 0) {
		ans ++;
		marked[source] = marked[parent] = true;
	}
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

	parenting_dfs(1, 0);
	cout << ans << endl;
}