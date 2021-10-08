//Thursday 07-October-2021 23:20:43
#include <bits/stdc++.h>
//@ReetuRaj77
#define int long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

const int INF = 1e7;
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>>adj(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
	}
	multiset<pair<int, int>>s;
	s.insert({0, 1});
	priority_queue<int>bests[n + 1];
	bests[1].push(0);
	while (!s.empty()) {
		auto v = s.begin()->second;
		auto c = s.begin()->first;
		s.erase(s.begin());
		if (c > bests[v].top()) continue;
		for (auto& i : adj[v]) {
			int tmp = c + i.second;
			if (bests[i.first].size() < k) {
				bests[i.first].push(tmp);
				s.insert({tmp, i.first});
			} else if (tmp < bests[i.first].top()) {
				bests[i.first].pop();
				bests[i.first].push(tmp);
				s.insert({tmp, i.first});
			}
		}
	}
	vector<int>answer;
	while (answer.size() < k) {
		answer.push_back(bests[n].top());
		bests[n].pop();
	}
	reverse(all(answer));

	for (auto i : answer) {
		cout << i << " ";
	}
	cout << endl;
}