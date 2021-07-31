#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	fast;
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>>vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i].first;
		vals[i].second = i + 1;
	}
	sort(vals.begin(), vals.end());
	pair<int, int>ans;
	bool fl = false;
	for (int i = 0; i < n ; i++) {
		int rem = q - vals[i].first;
		if (rem == 0)continue;
		int low = i + 1;
		int high = n;
		while (low <= high) {
			int mid = (low + high) / 2;
			// cout << i + 1 << endl;
			// cout << low << " " << mid << " " << high <<endl;
			if (vals[mid].first == rem) {
				ans.first = vals[i].second;
				ans.second = vals[mid].second;
				fl = true;
				break;
			} else if (vals[mid].first < rem) {
				low = mid + 1;
			} else
				high = mid - 1;
		}
		if (fl)
			break;
	}
	if (!fl)
		cout << "IMPOSSIBLE" << '\n';
	else
		cout << ans.first << ' ' << ans.second << endl;
	return 0;

}