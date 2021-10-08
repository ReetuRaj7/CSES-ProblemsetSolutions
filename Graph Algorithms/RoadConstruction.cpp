//Friday 08-October-2021 19:39:04
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<int>root, rak, vals;

int find_set(int v) {
	if (vals[v] < 0)
		return v;
	return vals[v] = find_set(vals[v]);
}

bool union_sets(int i, int j) {
	i = find_set(i), j = find_set(j);
	if (i == j)return 0;
	if (vals[i] > vals[j])
		swap(i, j);
	vals[i] += vals[j];
	vals[j] = i;
	return 1;
}
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vals.resize(n + 1, -1);
	int maxi = -1;
	int components = n;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (union_sets(x, y)) {
			maxi = max(maxi, -vals[find_set(x)]);
			components--;
		}
		cout << max(0, components) << " " << maxi << endl;
	}
	return 0;
}