#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fast;
	int n, m;
	cin >> n;
	cin >> m;
	vector<int>a(n + 10);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>b(n + 10);
	for (int i = 1; i <= n; i++) {
		b[a[i]] = i;
	}
	lli ans = 1;
	for (int i = 2; i <= n; i++) {
		ans += (b[i] < b[i - 1]);
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		int f = a[x];
		int s = a[y];
		if (x == y) {
			cout << ans << '\n';
			continue;
		}
		//if (x > y)swap(x, y);
		if (b[f - 1] > b[f] && f > 1)
			ans--;
		if (b[f + 1] < b[f] && f < n)
			ans--;
		if (b[s - 1] > b[s] && s > 1 && s - 1 != f)
			ans--;
		if (b[s + 1] < b[s] && s < n && s + 1 != f)
			ans--;
		
		swap(a[x], a[y]);
		b[f] = y;
		b[s] = x;
		f = a[y];
		s = a[x];

		if (b[f - 1] > b[f] && f > 1)
			ans++;
		if (b[f + 1] < b[f] && f < n)
			ans++;
		if (b[s - 1] > b[s] && s > 1 && s - 1 != f)
			ans++;
		if (b[s + 1] < b[s] && s < n && s + 1 != f)
			ans++;
		cout << ans << '\n';
	}
	return 0;
}