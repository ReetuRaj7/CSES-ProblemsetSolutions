//Thursday 17-March-2022 16:53:56
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<lli>tree;

lli func(int node, int node_left, int node_right, int left, int right, int val) {
	if (left <= node_left && node_right <= right) {
		if (val != -1) {
			tree[node] += val;
		}
		return tree[node];
	}

	if (left > node_right || right < node_left)
		return 0;


	int mid = (node_left + node_right) / 2;
	lli sum = func(2 * node, node_left, mid, left, right, val)
	          + func(2 * node + 1, mid + 1, node_right, left, right, val);

	return sum + tree[node];
}

int main() {
	fastio;
	int n, q;
	cin >> n >> q;
	vector<lli>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];


	while (__builtin_popcount(n) != 1)n++;
	tree.resize(2 * n);

	for (int i = 0; i < (int)a.size(); i++)tree[n + i] = a[i];

	while (q--) {
		int type;
		cin >> type;

		if (type == 1) {
			int low, high, upd;
			cin >> low >> high >> upd;
			low--, high--;
			func(1, 0, n - 1, low, high, upd);
		} else {
			int idx; cin >> idx;
			idx--;
			cout << func(1, 0, n - 1, idx, idx, -1) << endl;
		}
	}
}