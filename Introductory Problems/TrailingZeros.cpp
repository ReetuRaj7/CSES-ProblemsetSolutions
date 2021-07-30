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
	lli ans = 0;
	for (int i = 5; i <= n; i *= 5)
		ans += (n / i);
	cout << ans << endl;
}