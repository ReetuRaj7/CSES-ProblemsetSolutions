//Monday 16-August-2021 21:38:07

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
	vector<pair<int, int>>a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first, a[i].second = i;
	stack<pair<int, int>>S;
	for (int i = 0; i < n; i++) {
		while (!S.empty() && S.top().first >= a[i].first)
			S.pop();
		if (S.empty())
			cout << 0 << ' ';
		else
			cout << S.top().second + 1 << ' ';
		S.push(a[i]);
	}
	return 0;
}