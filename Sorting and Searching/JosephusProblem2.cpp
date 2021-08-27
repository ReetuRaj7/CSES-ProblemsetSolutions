//Thursday 26-August-2021 01:00:09

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;



int main() {
	int n, k=1;
	cin >> n;
	cin >> k; 

	oset<int> josephus;

	for (int i = 1; i <= n; i++)
		josephus.insert(i);

	int remove = k % n;

	while (josephus.size()) {
		int cur = *josephus.find_by_order(remove);
		josephus.erase(cur);
		if (josephus.size())
			remove = (remove + k) % josephus.size();
		cout << cur << " ";
	}
	return 0;
}