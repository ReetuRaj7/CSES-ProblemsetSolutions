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
	int input[n + 1];
	for (int i = 0; i < n; i++)
		cin >> input[i];
	lli ans = 0;
	for (int i = 1; i < n; i++) {
		if (input[i] < input[i - 1]) {
			ans += input[i - 1] - input[i];
			input[i] = input[i - 1];
		}
	}
	cout << ans << "\n";
}