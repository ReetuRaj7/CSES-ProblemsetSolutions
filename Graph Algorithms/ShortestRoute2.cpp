//Thursday 09-September-2021 11:40:02

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const lli inf = 100000000000000;

//flloyd warshall algorithm


int main() {
	fastio;
	lli n, m, q;
	cin >> n >> m >> q;
	vector<vector<lli>>dist(n + 10, vector<lli>(n + 10, inf));
	for (int i = 0; i < m; i++) {
		lli x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		dist[x][x] = dist[y][y] = 0;
		dist[x][y] = min(dist[x][y], z);
		dist[y][x] = min(dist[y][x], z);
	}
	for (int k = 0; k < n; k++) //intermediate vertex
		for (int i = 0; i < n; i++) //source vertex
			for (int j = 0; j < n; j++) { //destination vertex
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
	//queries
	for (int i = 0; i < q; i++) {
		lli x, y;
		cin >> x >> y;
		x--, y--;
		if (dist[x][y] == inf)
			cout << -1 << endl;
		else
			cout << dist[x][y] << endl;
	}
	return 0;
}