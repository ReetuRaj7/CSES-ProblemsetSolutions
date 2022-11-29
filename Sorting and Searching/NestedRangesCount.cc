//Friday 14-October-2022 23:25:27
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//.*find_by_order(),.order_of_key()
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

typedef array<int, 3> Pair;
class FenwickTree {
	int sz;
public:
	vector<int>ft;

	FenwickTree(int x): sz(x) {
		ft.resize(sz+1, 0);
	}
	int query(int ind) {
		int ans = 0;
		for (; ind > 0; ind -= ind & -ind) {
			ans += ft[ind];
		}
		return ans;
	}
	void update(int ind, int val) {
		for (; ind <= this->sz; ind += ind & -ind) {
			ft[ind] += val;
		}
	}
};

int main() {
	fastio;
	int n;
	cin >> n;
	vector<Pair>A(n);
	set<int>S;
	for (int i = 0; i < n; i++) {
		cin >> A[i][0] >> A[i][1];
		A[i][2] = i;
		S.insert(A[i][1]);
	}
	sort(all(A), [&](Pair a, Pair b) {
		if (a[0] == b[0])
			return a[1] > b[1];
		return a[0] < b[0];
	});
	//a map to hold the numbers value-> there can be multiple same values;
	int cnt = 0;
	map<int, int>mp;
	for (auto X : S)mp[X] = ++cnt;
	FenwickTree F1(cnt);
	F1.update(mp[A[n - 1][1]], 1);

	vector<int>ans1(n);
	for (int i = n - 2; i >= 0; i--) {
		ans1[A[i][2]] = F1.query(mp[A[i][1]]);
		F1.update(mp[A[i][1]], 1);
	}
	vector<int>ans2(n);
	FenwickTree F2(cnt);
	// number of ranges containing the range
	// just because we're not maintaining anything to declare the start we
	// we assume every start as 1,that doesn't make any difference
	// for end we update -1,so that the values are cancelled out
	F2.update(1, 1);
	F2.update(mp[A[0][1]] + 1, -1);
	for (int i = 1; i < n; i++) {
		ans2[A[i][2]] = F2.query(mp[A[i][1]]);
		F2.update(1, 1); //start of a range
		F2.update(mp[A[i][1]] + 1, -1); //end of the range
	}

	for (auto X : ans1)
		cout << (X > 0) << ' ';
	cout << endl;
	for (auto X : ans2)
		cout << (X > 0) << ' ';
	cout << endl;
}

//a PBDS based answer also possible