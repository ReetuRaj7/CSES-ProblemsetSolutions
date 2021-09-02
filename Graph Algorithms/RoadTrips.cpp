//Thursday 02-September-2021 20:59:50

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


vector<int>parent;
vector<int>adj[200011];
vector<bool>visited;
int start, ending;

bool dfs(int u, int par) {
	visited[u] = true;
	for (auto i : adj[u]) {
		if (par == i)continue;
		if (visited[i] == true) {
			start = i;
			ending = u;
			return true;
		}
		parent[i] = u;
		if (dfs(i, parent[i]))
			return true;
	}
	return false;
}
void find_cycle(int n) {
	parent.assign(n, -1);
	visited.assign(n, false);
	start = -1;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false && dfs(i, parent[i]))
			break;
	}

	if (start == -1) {
		cout << "IMPOSSIBLE\n";
	} else {
		vector<int>cycle;
		cycle.push_back(start);
		for (int i = ending; i != start; i = parent[i])
			cycle.push_back(i);
		cycle.push_back(start);

		reverse(all(cycle));
		cout << cycle.size() << endl;
		for (int i = 0; i < cycle.size(); i++) {
			cout << cycle[i] + 1 << " \n"[i == cycle.size() - 1];
		}
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
		adj[y].push_back(x);
	}
	find_cycle(n);
	return 0;
}