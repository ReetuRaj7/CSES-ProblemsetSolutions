#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int main() {
	lli n;
	cin >> n;
	lli sum = 0;
	lli maxisum = n * (n + 1) / 2;

	for (int i = 0; i < n - 1; i++) {
		lli x;
		cin >> x;
		sum += x;
	}
	cout << maxisum - sum << endl;
}