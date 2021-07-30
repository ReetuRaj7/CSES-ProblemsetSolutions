#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;
const int MOD = 1000000007;

lli powerOfTwo(lli n) {
	lli ans = 1;
	lli i = 0;
	while (i < n) {
		ans = ((ans) % MOD * 2) % MOD;
		i++;
	}
	return ans % MOD;
}

int main() {
	fast;
	lli n;
	cin >> n;
	cout << powerOfTwo(n) << endl;
}