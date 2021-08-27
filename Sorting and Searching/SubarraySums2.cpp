//Thursday 26-August-2021 01:01:19

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	lli n, target;
	cin >> n >> target;
	vector<lli>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<lli, lli>ma;
	ma[0] = 1;
	lli ans = 0;
	lli prefix_sum = 0;
	for (auto x : a) {
		prefix_sum+=x;
		ans += ma[prefix_sum-target];
		ma[prefix_sum]++;
	}

	cout << ans << endl;
}