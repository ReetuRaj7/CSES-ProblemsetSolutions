//Wednesday 29-September-2021 00:46:05
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

vector<int>adj[100005];
vector<bool>visited;
vector<int>topo;


void topological_order(int source) {
	visited[source] = true;
	for (auto x : adj[source])
		if (!visited[x])
			topological_order(x);
	topo.push_back(source);
}
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	topological_order(1);
	reverse(all(topo));
	vector<int>last(n + 1, -1), lvl(n + 1, 0);

	for (auto x : topo) {
		for (auto a : adj[x]) {
			if (lvl[a] < lvl[x] + 1) {
				last[a] = x;
				lvl[a] = lvl[x] + 1;
			}
		}
	}
	if (last[n]==-1){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	int i = n;
	vector<int>answer;
	while (i != -1) {
		answer.push_back(i);
		i = last[i];
	}
	cout<<answer.size()<<endl;
	reverse(all(answer));
	for(auto X:answer)
		cout<<X<<' ';
}