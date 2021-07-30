#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int cutting[505][505];
int fun(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == j) {
				cutting[i][j] = 0;
				continue;
			} else {
				cutting[i][j] = 1e9;
				for (int k = 1; k < j; k++)
					cutting[i][j] = min(cutting[i][j], cutting[i][k] + cutting[i][j - k] + 1);
				for (int k = 1; k < i; k++)
					cutting[i][j] = min(cutting[i][j], cutting[i - k][j] + cutting[k][j] + 1);
			}
		}
	}
	return cutting[n][m];
}

int main() {
	fast;
	int a, b;
	cin >> a >> b;
	memset(cutting, -1, sizeof cutting);

	cout <<  fun(a, b) << "\n";

	return 0;
}