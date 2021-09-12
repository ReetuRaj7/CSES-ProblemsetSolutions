//Sunday 12-September-2021 11:19:54
#include <bits/stdc++.h>
//@ReetuRaj77
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ordered_set tree < lli ,  null_type ,  less_equal<lli> ,  rb_tree_tag ,  tree_order_statistics_node_update >

using namespace std;
using namespace __gnu_pbds;


//Policy based data structures used//
int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	vector<lli>a(n);
	for (auto&x : a)cin >> x;
	ordered_set s;
	vector<lli>answer;
	lli med = k / 2;
	if (k % 2 == 0)med--;
	int i;
	for (i = 0; i < k; i++)
		s.insert(a[i]);
	answer.push_back(*s.find_by_order(med));
	for (; i < n; i++) {
		int ind = (int)answer.size() - 1;
		auto it = s.find_by_order(s.order_of_key(a[ind]));
		s.erase(it);
		s.insert(a[i]);
		answer.push_back(*s.find_by_order(med));
	}
	for (auto x : answer)
		cout << x << endl;

}