
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()
#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

bool vis[1010][1010];
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, -1, 1};
int n, m;
char ar[1010][1010];

bool isvalid(int i, int j) {
	if (i >= 0 && j >= 0 && i < n && j < m && vis[i][j] == false && ar[i][j] != '#')
		return true;
	return false;
}
void dfs(int i, int j) {
	vis[i][j] = true;

	for (int moves = 0; moves < 4; moves++) {
		int dx = i + x[moves];
		int dy = j + y[moves];

		if (isvalid(dx, dy))
			dfs(dx, dy);
	}

}
//For lower values of n even n^2 is accepted.
int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];
	}
	memset(vis, false, sizeof vis);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && ar[i][j] != '#') {
				dfs(i, j);
				ans++;
			}

		}
	cout << ans << '\n';

}
