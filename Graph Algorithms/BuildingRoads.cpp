//Friday 27-August-2021 19:42:18

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


struct UnionFind {
	vector<int>par;
	int n;
	UnionFind(int n) {
		this->n = n;
		par.assign(n, 0);
		iota(par.begin(), par.end(), 0);
	}
	int get(int a) {
		if (a == par[a])
			return a;
		return par[a] = get(par[a]);
	}
	void combine(int a, int b) {
		a = get(a);
		b = get(b);

		if (a == b)
			return;
		par[b] = a;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	UnionFind uf1 = UnionFind(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		uf1.combine(x, y);
	}
	set<int>s;
	for (int i = 0; i < n; i++)
		s.insert(uf1.get(i));
	vector<int>v(all(s));
	cout << s.size() - 1 << endl;
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] + 1 << " " << v[i + 1] + 1 << endl;
	}
}