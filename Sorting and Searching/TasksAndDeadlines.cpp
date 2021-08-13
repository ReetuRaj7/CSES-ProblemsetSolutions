#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()
#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fast;
	int n;
	cin >> n;
	vector<pair<int, int>>vpr(n);
	for (int i = 0; i < n; i++)
		cin >> vpr[i].first >> vpr[i].second;

	sort(all(vpr));
	lli maxim = vpr[0].second - vpr[0].first;
	lli time = vpr[0].first;
	for (int i = 1; i < n; i++)	
		maxim += (vpr[i].second - (vpr[i].first + time)),time+=vpr[i].first;

	cout << maxim << '\n';

	return 0;

}