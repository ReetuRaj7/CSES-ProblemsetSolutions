//Sunday 13-March-2022 01:05:29
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int N = 2 * 1e5;
int tree[4 * N];
vector<int>a;

void build(int node, int st, int en) {
	if (st == en) {
		tree[node] = a[st];
		return;
	}
	int mid = (st + en) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);

	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r) {
	if (st > r || en < l)
		return INT64_MAX;

	if (l <= st && en <= r)
		return tree[node];


	int mid = (st + en) / 2;
	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, en, l, r);

	return min(q1, q2);
}


void update(int node, int st, int en, int idx, int val) {
	if (st == en) {
		a[st] = val;
		tree[node] = val;
		return;
	}

	int mid = (st + en) / 2;

	if (idx <=  mid)
		update(2 * node, st, mid, idx, val);
	else
		update(2 * node + 1, mid + 1, en, idx, val);

	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

signed main() {
	fastio;
	int n;
	cin >> n;
	int q;
	cin >> q;
	a.resize(n);
	for (auto&x : a)cin >> x;

	build(1, 0, n - 1);

	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
		} else {
			int idx, val;
			cin >> idx >> val;
			update(1, 0, n - 1, idx - 1, val);
		}
	}

	return 0;
}