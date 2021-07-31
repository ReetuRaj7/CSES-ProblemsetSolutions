#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1000000088

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	lli n;
	cin >> n;
	vector<lli>a(n);
	lli min = mini;
	for (auto&x : a) {
		cin >> x;
		if (x > min)
			min = x;
	}
	lli max_so_far = a[0];
	lli max_here = a[0];

	for (int i = 1; i < n; i++) {
		max_here = max(a[i], max_here + a[i]);
		max_so_far = max(max_here, max_so_far);
	}
	cout << max_so_far << endl;
	return 0;

}