#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	fast;
	int t;
	cin >> t;
	while (t-- > 0) {
		int a, b;
		cin >> a >> b;

		if (a > 2 * b || b > 2 * a )
			cout << "NO\n";
		else {
			if (a < b)
				swap(a, b);
			// cout << a << " " << b << endl;
			int diff = a - b;
			a -= 2 * diff;
			b -= diff;
			// cout << a << " " << b << endl;
			if (a == b && a % 3 == 0)
				cout << "YES\n";
			else cout << "NO\n";

		}
	}
	return 0;
}