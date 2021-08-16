//Monday 16-August-2021 12:55:59
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
using namespace chrono;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int main() {
	fastio;
	int n;
	int target;
	cin >> n;
	cin >> target;
	vector<int>ar(n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	unordered_map<int, pair<int, int>,custom_hash>mp;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			int idx = target - ar[i] - ar[j];
			if (mp.find(idx) != mp.end()) {
				cout << i + 1 << ' ' << j + 1 << ' ' << mp[idx].first+1 << ' ' << mp[idx].second+1;
				return 0;
			}
		}
		for (int j = i + 1; j < n; j++)mp[ar[i] + ar[j]] = {i, j};
	}
	cout << "IMPOSSIBLE";
	return 0;

}