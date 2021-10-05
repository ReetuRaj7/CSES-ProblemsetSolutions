//Tuesday 05-October-2021 00:45:47
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


struct edge {
	long long int a, b, cost;
};

vector<edge>e;

const long long int INF = 1e17;
const long long int NINF = INF * (-1);

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		struct edge et;
		cin >> et.a >> et.b >> et.cost;
		et.cost *= (-1);
		e.push_back(et);
	}

	vector<lli>dist(n + 1, INF);
	dist[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[e[j].a] < INF) {
				if (dist[e[j].b] > dist[e[j].a] + e[j].cost) {
					dist[e[j].b] =  dist[e[j].a] + e[j].cost;
				}
				dist[e[j].b] = max(NINF, dist[e[j].b]);
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[e[j].a] < INF) {
				dist[e[j].b] = max(NINF, dist[e[j].b]);
				if (dist[e[j].b] > dist[e[j].a] + e[j].cost) {
					dist[e[j].b] =  NINF;
				}
			}
		}
	}
	if (dist[n] == NINF) {
		cout << -1 << endl;
	} else {
		cout << -dist[n] << endl;
	}

}