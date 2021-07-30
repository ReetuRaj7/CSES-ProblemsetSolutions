#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int i = 0, j = n - 1, cnt = 0;
	while (i <= j && j > 0) {
		if (a[i] + a[j] <= k)
			i++, j--, cnt++;
		else
			j--, cnt++;
	}
	cout << cnt << "\n";
}