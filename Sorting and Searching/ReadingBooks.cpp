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
	vector<lli>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(all(a));
	lli sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	cout << max(2 * a[n - 1], sum) << endl;

}