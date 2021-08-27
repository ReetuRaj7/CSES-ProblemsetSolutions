//Friday 27-August-2021 21:54:50

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<int> bfs(int source, int destination, vector<int>adj[]) {
	vector<int>p(destination + 10);
	p[source] = -1;
	bool vs[destination + 11];
	memset(vs, false, sizeof vs);

	vs[source] = true;
	queue<int>q;
	q.push(source);
	while (!q.empty()) {
		int v = q.front();
		for (auto x : adj[v]) {
			if (!vs[x]) {
				vs[x] = true;
				p[x] = v;
				q.push(x);
			}
		}
		q.pop();
	}
	vector<int>answer;
	if (vs[destination] == true) {
		for (int i = destination; i != -1; i = p[i]) {
			answer.push_back(i + 1);
		}
	}
	reverse(all(answer));
	return answer;
}
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> ans = bfs(0, n - 1, adj);
	if (ans.size())
		cout << ans.size() << endl;
	else
		cout << "IMPOSSIBLE" << endl;
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;
}