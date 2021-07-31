#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

bool sortbysec(pair<int, int>&a, pair<int, int>&b) {
	return a.second < b.second;
}
int main() {
	//Greedy scheduling technique
	int n;
	cin >> n;

	vector<pair<int, int>>events(n);

	for (int i = 0; i < n; i++) {
		cin >> events[i].first >> events[i].second;
	}
	sort(events.begin(), events.end(), sortbysec);
	int current = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (current <= events[i].first) {
			current = events[i].second;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}