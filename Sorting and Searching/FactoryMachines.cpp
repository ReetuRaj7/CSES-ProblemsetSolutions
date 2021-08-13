#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()
#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

bool check(lli mid, lli checker, vector<lli>&k, lli n) {
	lli sum = 0;
	for (int i = 0; i < n; i++) {
		sum += mid / k[i];
		if (sum >= checker)
			return true;
	}
	return false;
}


int main() {
	fast;

	lli n, t;
	cin >> n >> t;
	lli low = 0, high = 1e20, ans = 0;
	vector<lli>k(n);
	for (int i = 0; i < n; i++)
		cin >> k[i];

	while (low <= high) {
		lli mid = (low + high) / 2;

		if (check(mid, t, k, n))
			high = mid - 1, ans = mid;
		else
			low = mid + 1;
	}
	cout << ans << '\n';
}