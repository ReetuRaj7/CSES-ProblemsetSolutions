//Thursday 02-September-2021 23:21:57

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
vector<int>adj[200011];
vector<int>color;
vector<int>parent;
int st, en;

bool dfs(int source) {
	color[source] = 1;
	for (auto i : adj[source]) {
		if (color[i] == 1) {
			st = i;
			en = source;
			return true;
		} else if (color[i] == 0) {
			parent[i] = source;
			if (dfs(i))
				return true;
		}
	}
	color[source] = 2;
	return false;
}
void find_cycle(int n) {
	color.assign(n, 0);
	parent.assign(n, -1);
	st = -1;
	for (int i = 0; i < n; i++)
		if (color[i] == 0 && dfs(i))
			break;
	if (st == -1)
		cout << "IMPOSSIBLE" << endl;
	else {
		vector<int>cycle;
		cycle.push_back(st + 1);
		for (int i = en; i != st; i = parent[i])
			cycle.push_back(i + 1);
		cycle.push_back(st + 1);
		reverse(all(cycle));
		cout << cycle.size() << endl;
		for (size_t i = 0; i < cycle.size(); i++)
			cout << cycle[i] << " \n"[i == cycle.size() - 1];
	}
}
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
	}
	find_cycle(n);
	return 0;
}