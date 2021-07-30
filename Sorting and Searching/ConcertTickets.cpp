#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	multiset<int>a;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		a.insert(h);
	}
	// sort(a.begin(), a.end());
	vector<int>ans;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		auto it = a.upper_bound(x);
		if (it == a.begin())
			cout << -1 << endl;
		else {
			cout << *(--it) << endl;
			a.erase(it);
		}
	}
}