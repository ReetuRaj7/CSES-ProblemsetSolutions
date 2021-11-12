//Friday 12-November-2021 17:41:00
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	int n, q;
	cin >> n >> q;
	vector<lli>a(n);
	for (auto&x : a)cin >> x;
	vector<lli>prefix(n + 1);
	prefix[0] = a[0];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] + a[i];

	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x == 0)cout << prefix[y] << endl;
		else cout << prefix[y] - prefix[x-1] << endl;
	}
	return 0;
}