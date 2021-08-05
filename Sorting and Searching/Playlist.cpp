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
	int n;
	set<int> s;
	vector<int>a(n);
	int ans = 0;

	int r = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		while (r < n - 1 && !s.count(a[r + 1])) s.insert(a[++r]);
		//Two pointers
		ans = max(ans, r - i + 1);
		s.erase(a[i]);
	}
	cout << ans;
}