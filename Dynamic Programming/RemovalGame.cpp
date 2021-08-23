//Thursday 19-August-2021 00:22:30

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
lli scores[5010][5010];
lli maxipoint(vector<lli>&a, int n, int m) {
	if (n > m) {
		return 0;
	}
	if (scores[n][m] != -1) {
		return scores[n][m];
	}
	lli opt1 = min(maxipoint(a, n + 2, m), maxipoint(a, n + 1, m - 1)) + a[n];
	lli opt2 = min(maxipoint(a, n + 1, m - 1), maxipoint(a, n, m - 2)) + a[m];
	lli val = max(opt1, opt2);
	return scores[n][m] = val;
}

int main() {
	int n;
	cin >> n;
	vector<lli>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(scores, -1, sizeof scores);
	cout << maxipoint(a, 0, n - 1) << endl;
}