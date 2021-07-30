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
	string s;
	cin >> s;
	int len = 1;
	int maxilen = -1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1])
			len++;
		else {
			maxilen = max(maxilen, len);
			len = 1;
		}

	}
	maxilen = max(len, maxilen);
	cout << maxilen << endl;
}