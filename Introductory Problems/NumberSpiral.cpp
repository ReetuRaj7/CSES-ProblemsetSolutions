#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

void solve() {
	lli r, c;
	cin >> r >> c;
	lli ans = 0;
	lli z = max(r, c);
	lli z2 = (z - 1) * (z - 1);
	if (z % 2 == 0) {
		if (z == c) {
			ans = z2 + r;
		}
		else
		{
			ans = z2 + 2 * z - c;
		}
	}
	else {
		if (r == z)
		{
			ans = z2 + c;
		}
		else
		{
			ans = z2 + 2 * z - r;
		}

	}
	cout << ans << "\n";
}
int main() {
	fast;
	lli te;
	cin >> te;
	while (te-- > 0) {
		solve();
	}
	return 0;
}