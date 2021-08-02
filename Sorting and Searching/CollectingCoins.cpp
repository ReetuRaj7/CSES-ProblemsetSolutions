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
	cin >> n;
	vector<int>a(n);
	for (auto&i : a)cin >> i;
	vector<int>b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[a[i]] = i; // Saving the positions
	}
	lli ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += b[i] < b[i - 1];
	}
	cout << ++ans << '\n';
	return 0;
}