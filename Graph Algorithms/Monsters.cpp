//Wednesday 08-September-2021 11:29:11

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

int dist[1001][1001];
int d[1001][1001];
int n, m;
bool isInValid(int x, int y, int st, vector<string>&mat) {
	if (x < 0 || y < 0 || x > n - 1 || y > m - 1 || d[x][y] != -1 || (dist[x][y] >= 0 && dist[x][y] <= st) || mat[x][y] == '#')
		return true;
	return false;
}
vector<int>dx = {1, -1, 0, 0};
vector<int>dy = {0, 0, 1, -1};
int main() {
	fastio;
	memset(dist, -1, sizeof dist);
	memset(d, -1, sizeof d);
	cin >> n >> m;
	vector<string>mat(n);
	for (auto&i : mat)cin >> i;
	queue<vector<int>>q;
	int x1, y1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'M')
				q.push({i, j, 0});
			if (mat[i][j] == 'A')
				x1 = i, y1 = j;
		}
	}
	while (!q.empty()) {
		auto f  = q.front();
		q.pop();
		int x = f[0], y = f[1], steps = f[2];

		if (x < 0 || x > n - 1 || y < 0 || y > m - 1  || mat[x][y] == '#' || dist[x][y] != -1)
			continue;
		dist[x][y] = steps;
		for (int i = 0; i < 4; i++){
			int cx = x + dx[i],cy = dy[i] + y;
			q.push({cx,cy, steps + 1});
		}
	}
	int ans = 0;
	
	queue<vector<int>>empty;
	swap(q, empty);
	q.push({x1, y1, 0, 0});
	int par[n + 1][m + 1];
	string fin = "";
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		int x = f[0], y = f[1], steps = f[2], dir = f[3];
		if (isInValid(x, y, steps, mat))
			continue;
		if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
			par[x][y] = dir;
			while (x != x1 || y != y1) {
				ans++;
				if (par[x][y] == 0) fin += "D", x--;
				else if (par[x][y] == 1)fin += "U", x++;
				else if (par[x][y] == 2)fin += "R", y--;
				else if (par[x][y] == 3)fin += "L", y++;
			}
			reverse(all(fin));
			cout << "YES" << endl;
			cout << ans << endl;
			cout << fin << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			q.push({x + dx[i], y + dy[i], steps + 1, i});
		}
		par[x][y] = dir;
		d[x][y] = steps;
	}
	cout<<"NO"<<endl;
	return 0;
}