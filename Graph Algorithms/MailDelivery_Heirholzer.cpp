//Sunday 05-September-2021 00:15:43

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
vector<set<int>>vs(100010, set<int>());
vector<bool>used;
vector<int>ans;



void dfs(int source) {
	used[source] = true;
	for (int i : vs[source]) {
		if (!used[i])
			dfs(i);
	}
}
bool hasEuler(int n) {
	for (int i = 1; i <= n; i++) {
		if (vs[i].size() & 1) {
			return false;
		}
	}
	used.assign(n + 1, false);
	dfs(1);

	for (int i = 1; i <= n; i++)
		if (used[i] == false && vs[i].size())
			return false;
	return true;
}
void make_path(int source) {
	while (vs[source].size()) {
		int i = *vs[source].begin();
		vs[i].erase(source);
		vs[source].erase(i);
		make_path(i);
	}
	ans.push_back(source);
}
int main() {
	fastio;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vs[x].insert(y);
		vs[y].insert(x);
	}
	// for(int i=0;i<n;i++){
	// 	for(auto x: vs[i+1])
	// 		cout<<x<<" ";
	// 	cout<<endl;
	// }

	if (!hasEuler(n)) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	make_path(1);

	for (int i : ans)
		cout << i << " ";
	cout << endl;

}