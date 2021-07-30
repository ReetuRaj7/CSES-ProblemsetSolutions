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

	long long mod = 1e9 + 7;
	long long dp[n + 1] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6 && i - j >= 0; j++)
			(dp[i] += dp[i - j]) %= mod;
	}

	cout << dp[n] << endl;

	return EXIT_SUCCESS;
}