#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	// cout << n << m << k;
	vector<int>a(n), b(m);

	for (auto&x : a)
		cin >> x;
	for (auto&y : b)
		cin >> y;

	// cout<<"hello world";
	// cout << count << endl;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int l = 0, r = 0, cnt = 0;
	while (l < m && r < n ) {
		if (abs(b[l] - a[r]) <= k)
			l++, r++, cnt++;
		else if (b[l] < a[r])
			l++;
		else if (a[r] < b[l])
			r++;
	}
	cout << cnt << endl;
}