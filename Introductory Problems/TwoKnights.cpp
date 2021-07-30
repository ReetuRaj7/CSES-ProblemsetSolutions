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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		lli an = i * i;
		lli as = an * (an - 1) / 2;
		if (i > 2)
			cout << as - 4 * (i - 1)*(i - 2) << endl;
		else
			cout << as << endl;
	}
	return 0;
}