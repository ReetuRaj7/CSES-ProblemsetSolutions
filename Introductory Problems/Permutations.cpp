#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main(int argc, char const *argv[])
{
	lli n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n < 4)
		cout << "NO SOLUTION\n";
	else {
		if ((n & 1) == 1) {
			for (int i = 2; i <= n; i += 2)
				cout << i << " ";
			for (int i = 1; i <= n; i += 2)
				cout << i << " ";
		} else {
			for (int i = 2; i <= n; i += 2)
				cout << i << " ";
			for (int i = 1; i < n; i += 2)
				cout << i << " ";
		}
	}
	return 0;
}