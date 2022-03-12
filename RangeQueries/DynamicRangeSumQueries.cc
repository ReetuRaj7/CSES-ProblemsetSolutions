//Saturday 12-March-2022 11:21:25
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int LSbit(int n) {
	return n & (-n);
}

class FenwickTree {
private:
	vector<int>bit;
public:
	FenwickTree(int n) {
		bit.assign(n + 1, 0);
	}
	FenwickTree(vector<int> a) : FenwickTree(a.size()) {
		for (int i = 0; i < (int)a.size(); i++)
			update(i, a[i]);
	}
	int rSum(int r) {
		r++;
		int val = 0;
		while (r > 0) {
			val += bit[r];
			r -= LSbit(r);
		}
		return val;
	}
	int range(int l, int r) {
		return rSum(r) - rSum(l - 1);
	}
	void update(int idx, int delta) {
		idx++;
		while (idx < (int)bit.size()) {
			bit[idx] += delta;
			idx  += LSbit(idx);
		}
	}
};

signed main() {
	fastio;
	int n;
	cin >> n;
	int q;
	cin >> q;
	vector<int>a(n);
	for (auto&x : a)cin >> x;

	FenwickTree FT = FenwickTree(a);

	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			FT.update(y - 1, z - a[y - 1]);
			a[y - 1] = z;
		} else {
			y--, z--;
			cout << FT.range(y, z) << endl;
		}
	}
	return 0;

}