//Monday 16-August-2021 22:48:54
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
	lli target;
	cin >> target;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	deque<lli>dq;
	lli dq_sum = 0;
	lli ans = 0;
	for (int i = 0; i < n; i++) {
		if (dq_sum + a[i] < target) {
			dq.push_back(a[i]);
			dq_sum += a[i];
		} else if (dq_sum + a[i] == target) {
			ans++;
			dq.push_back(a[i]);
			dq_sum += a[i];
		} else {
			while (dq_sum + a[i] > target && !dq.empty()) {
				dq_sum -= dq.front(); dq.pop_front();
			}
			if (dq_sum + a[i] < target) {
				dq.push_back(a[i]);
				dq_sum += a[i];
			} else if (dq_sum + a[i] == target) {
				ans++;
				dq.push_back(a[i]);
				dq_sum += a[i];
			} P
		}
	}
	cout << ans << '\n';
	return 0;
}