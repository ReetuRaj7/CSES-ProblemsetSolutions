#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi INT_MAX
#define mini INT_MIN

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (n % 2) {
		int med = n / 2;
		lli ans = 0;
		for (int i = 0; i < n; i++) {
			ans += abs(a[med] - a[i]);
		}
		cout << ans << '\n';
	} else {
		int med1 = n / 2;
		int med2 = med1 + 1;
		lli ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++) {
			ans1 += abs(a[med1] - a[i]);
			ans2 += abs(a[med2] - a[i]);
		}
		cout << min(ans1, ans2) << '\n';
	}
	return 0;
}