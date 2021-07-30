#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>vals;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vals.push_back({x, 1});
		vals.push_back({y + 1, -1});
	}
	int ans = 0;
	int sum = 0;
	sort(vals.begin(), vals.end());
	for (auto x : vals) {
		sum += x.second;
		if (sum > ans)
			ans = sum;
	}
	cout << ans << "\n";
}