/*
	Basically we can do this using top down approach
	we can say in
	d(n,0) -> ways to build tower of size n using n-1 when we have both
	the previous ones linked

	d(n,1) -> ways to build tower of size n-1 when we have both the towers of
	previous ones unlinked

	for unlinked(d(i,0)) -> dont extend any of the ith towers:d(i+1,0)+d(i+1,1)
						-> gets to extend any of the tower
				-> extend both of the ith towers: d(i+1,0)
						-> gets to extend both
				-> extend one of the ith towers:2*d(i+1,0)
						-> gets to extend one of the towers(symmetric are considered different)

	for linked(d(i,1)) -> dont extend any: gets to extend any or none
					-> extend both: gets to extend both or leave both
*/

#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

const int mod = (int)1e9 + 7;

int main() {
	int t;
	cin >> t;

	while (t-- > 0) {
		int n;
		cin >> n;

		lli building[n + 10][2];
		building[n + 1][0] = building[n + 1][1] = 1;
		for (int i = n; i >= 2; i--) {
			building[i][0] = (building[i + 1][1] + 4 * building[i + 1][0]) % mod;
			building[i][1] = (2 * building[i + 1][1] + building[i + 1][0]) % mod ;
		}
		cout << (building[2][0] + building[2][1]) % mod << "\n";
	}
	return 0;
}