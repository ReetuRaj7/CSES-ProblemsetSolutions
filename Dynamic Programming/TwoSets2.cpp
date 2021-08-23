//Thursday 19-August-2021 11:50:58

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int mod = 1000000007;
int CountSums(vector<int>&a, int need) {
	int n = (int)a.size();
	lli counter[n + 10][need + 10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= need; j++) {
			if (j == 0) {
				counter[i][j] = 1;
			} else if (i == 0 && j != 0) {
				counter[i][j] = 0;
			} else {
				counter[i][j] = counter[i - 1][j];
				if (i <= j) {
					counter[i][j] = ((counter[i - 1][j]) % mod + (counter[i - 1][j - i]) % mod) % mod;
				}
			}
		}
	}
	return counter[n-1][need];

}


int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	iota(all(a), 1);
	lli sum = (lli)(n) * (n + 1) / 2;
	if (sum % 2 != 0) {
		cout << 0 << '\n';
	} else {
		cout << CountSums(a, sum / 2) << endl;
	}
	return 0;
}