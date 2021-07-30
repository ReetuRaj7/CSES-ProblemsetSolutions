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
	if (n % 4 == 0 || n % 4 == 3) {
		cout << "YES\n";
		lli sum = n * (n + 1) / 2;
		lli needto = sum / 2;
		vector<lli>ans, ans2;
		for (int i = n; i >= 1; i--) {
			if (i <= needto) {
				ans.push_back(i);
				needto -= i;
			} else {
				ans2.push_back(i);
			}
		}
		cout << ans.size() << endl;
		for (auto i : ans)
			cout << i << " ";

		cout << endl;
		cout << ans2.size() << endl;
		for (auto i : ans2)
			cout << i << " ";

		cout << endl;

	} else {
		cout << "NO" << endl;
	}
}