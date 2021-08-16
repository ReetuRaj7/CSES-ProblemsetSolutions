#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fastio;
	int n, target;
	cin >> n >> target;

	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back({x, i + 1});
	}
	sort(all(v));
	// for (int i = 0; i < n; i++) {
	// 	cout << v[i].first << ' ' << v[i].second << '\n';
	// }

	for (int i = 0; i < n; i++) {
		int m = target - v[i].first;
		int l = 0, r = n - 1;
		while (l != r) {
			if (l != i && r != i && v[l].first + v[r].first == m) {
				cout << v[i].second << " " << v[l].second << " " << v[r].second;
				return 0;
			} else if (v[l].first + v[r].first < m) {
				l++;
			} else {
				r--;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}