//Monday 20-June-2022 22:30:16
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

int main() {
	fastio;
	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		lli k; cin >> k;
		if (k <= 9) {
			cout << k << endl;
			continue;
		}
		ulli cnt = 0;
		ulli j = 1;
		while (cnt + j * 9 * (ulli)pow(10ULL, j - 1) < k) {
			cnt += 9 * j * (ulli)pow(10ULL, j - 1);
			j++;
		}
		k -= cnt;
		lli number = pow(10, j - 1);
		lli dig = floor(log10(number)) + 1;
		number += (k / dig);
		ulli rem = k % dig;
		if(rem == 0)number--;
		string ans = to_string(number);
		if (rem == 0)cout << ans.back() << endl;
		else cout << ans[rem - 1] << endl;

	}
}