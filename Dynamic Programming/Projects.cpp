//Thursday 23-June-2022 02:03:45
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fastio;
	int N;
	cin >> N;
	vector<array<int, 3>>arr;
	for (int i = 0; i < N; i++) {
		int st, en, pro; cin >> st >> en >> pro;
		arr.push_back({st, en, pro});
	}
	sort(all(arr));
	map<lli, lli>m;
	lli ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		lli en = arr[i][1];
		map<lli, lli>::iterator mit = m.upper_bound(en);
		lli cnt = 0;
		if (mit != m.end()) {
			cnt += mit->second;
		}
		cnt += arr[i][2];
		ans = max(ans, cnt);
		m[arr[i][0]] = max(m[arr[i][0]], ans);
	}
	cout << ans << endl;
	return 0;
}