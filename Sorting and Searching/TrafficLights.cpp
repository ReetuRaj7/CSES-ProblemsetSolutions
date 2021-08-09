#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fast;
	int n, k;
	cin >> n >> k;
	set<int>s;
	multiset<int>ms;
	s.insert(0);
	s.insert(n);
	ms.insert(n);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		auto it = s.lower_bound(x);
		int el1 = *it;
		--it;
		int el2 = *it;
		ms.erase(ms.find(el1 - el2));
		ms.insert(el1 - x);
		ms.insert(x - el2);
		cout << *(--ms.end()) << ' ';
		s.insert(x);
	}
}