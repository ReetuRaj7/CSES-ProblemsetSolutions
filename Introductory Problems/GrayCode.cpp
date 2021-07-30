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
	for (int i = 0; i < (1 << n); i++) {
		int val = i ^ (i >> 1);
		bitset<16> r(val);
		string s = r.to_string();
		cout << s.substr(16 - n) << "\n";
	}
	return 0;
}