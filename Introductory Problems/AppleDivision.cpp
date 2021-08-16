#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fastio;
	int n;
	cin >> n;
	lli ar[n + 1];
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	lli ans = (lli)1e18;
	for (int mask = 0; mask < (1 << n); mask++) {
		lli s1 = 0, s2 = 0;
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) { //if the j-th bit is toggled
				s1 += ar[j];
			}
			else {
				s2 += ar[j];
			}
		}
		ans = min(ans, abs(s1 - s2));
	}
	cout << ans << '\n';
	return 0;
}