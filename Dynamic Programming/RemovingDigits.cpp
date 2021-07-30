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
	vector<int> minnum(n + 1, 1e9);
	minnum[0] = 0;
	for (int i = 0; i <= n; i++) {
		for (char x : to_string(i)) {
			minnum[i] = min(minnum[i], minnum[i - (x - '0')] + 1);
		}
	}
	cout << minnum[n] << endl;
}