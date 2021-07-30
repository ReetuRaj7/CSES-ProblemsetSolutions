#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	fast;
	lli n;
	cin >> n;
	cout << n << " ";
	while (n != 1) {
		if (n % 2 == 1) {
			cout << 3 * n + 1 << " ";
			n = 3 * n + 1;
		} else {
			cout << n / 2 << " ";
			n /= 2;
		}
	}
	//cout << 1 << "\n";
	return 0;
}