#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define mod 1e9 + 7
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	fast;
	int n, w;
	cin >> n >> w;
	vector<int>a(n);
	int count[w + 10] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	count[0] = 1;
	for (int i = 1; i <= w; i++) {
		for (auto k : a) {
			if (i - k >= 0) {
				count[i] += count[i - k];
				count[i] %= (int)mod;
			}
		}
	}
	cout << count[w] << endl;
}