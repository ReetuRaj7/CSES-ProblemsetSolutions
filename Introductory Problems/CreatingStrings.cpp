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
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	set <string> ans;
	do {
		ans.insert(str);
	} while (next_permutation(str.begin(), str.end()));
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;
}