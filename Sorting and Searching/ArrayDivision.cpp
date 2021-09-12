//Sunday 12-September-2021 01:00:23
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

bool func(lli mid, vector<lli>&a, lli k) {
	lli temp = 0;
	lli count = 0;
	for (lli i = 0; i < (lli)a.size(); i++) {
		if (a[i] > mid)return false;
		else if (a[i] + temp > mid)count++, temp = a[i];
		else temp += a[i];
	} if (temp != 0)count++;
	return count <= k;
}
int main() {
	fastio;
	lli n, k;
	cin >> n >> k;
	vector<lli>a(n);
	lli sum = 0;
	for (lli i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	lli low = *max_element(all(a)), high = sum;
	while (low < high) {
		lli mid = low + (high - low) / 2 ;
		if (func(mid, a, k))
			high = mid;
		else
			low = mid + 1;
	}
	cout << low << endl;
}