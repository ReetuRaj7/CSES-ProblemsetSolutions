#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

const int MOD = 1000000007;

int solve(vector<int>&input, int m, int n) {
	int ways[n + 2][m + 2];

	memset(ways, 0, sizeof ways);

	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= m; x++) {
			if (i == 1) {
				if (input[i] == 0 || input[i] == x)
					ways[i][x] = 1;
				else
					ways[i][x] = 0;
			} else {
				if (input[i] == 0 || input[i] == x) // We can check for validity on x iff it is equal to 0 or x
					ways[i][x] = ((ways[i - 1][x - 1] + ways[i - 1][x]) % MOD + ways[i - 1][x + 1]) % MOD; // Since we will be adding
				// x iff it is preceded by an x,x-1,x+1.
				else
					ways[i][x] = 0;
			}
		}
	}
	lli ans = 0;
	for (int i = 1; i <= m; i++) {
		ans = (ans + ways[n][i]) % MOD;
	}
	return ans;
}


int main() {
	fast;
	int n, m;
	cin >> n >> m;
	vector<int>input(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	cout << solve(input, m, n) << endl;

	return 0;

}