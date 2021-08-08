//Find minumum number of increasing sequences
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main(int argc, char const *argv[])
{
	fast;
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int>towers;

	for (int i = 0; i < n; i++) {
		auto it = upper_bound(all(towers), a[i]);
		if (it == towers.end())towers.push_back(a[i]);
		else {
			auto ik = it - towers.begin();
			towers[ik] = a[i];
		}
	}

	cout << towers.size() << endl;

	return 0;
}