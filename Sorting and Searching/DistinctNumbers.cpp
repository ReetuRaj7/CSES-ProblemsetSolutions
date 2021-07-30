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
	set<lli> set1;
	for (int i = 0; i < n; i++) {
		lli  x;
		cin >> x;
		set1.insert(x);
	}
	cout << set1.size() << endl;
}