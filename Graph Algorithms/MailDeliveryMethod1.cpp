//Friday 03-September-2021 23:56:21

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;



int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<set<int>>vs(n + 1, set<int>());
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
	for (int i = 1; i <= n; i++)
		if (vs[i].size() & 1) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	stack<int>rec_stack;
	rec_stack.push(1);
	vector<int>ans;
	while (rec_stack.empty() == false) {
		int v = rec_stack.top();
		if (vs[v].empty()) {
			ans.push_back(v);
			rec_stack.pop();
		} else {
			int i = *vs[v].begin();
			vs[v].erase(i);
			vs[i].erase(v);
			rec_stack.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
		if (vs[i].size()) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	return 0;
}