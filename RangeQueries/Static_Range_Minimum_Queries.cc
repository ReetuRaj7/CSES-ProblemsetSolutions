//Thursday 13-January-2022 21:16:42
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()
#define MAXN 200005
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

int logs[MAXN + 5];
int st[MAXN][30];

int main() {
	fastio;
	int n, q;
	cin >> n >> q;
	logs[1] = 0;
	for (int i = 2; i <= MAXN ; i++)logs[i] = logs[i / 2] + 1;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	int K = 25;

	//sparse table calculation
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	//using sparse table to calculate the corresponding RMQs
	//the idea is to think that we can divide an interval into
	//parts of power of two..

	for (int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		int j = logs[R - L + 1]; //to calculate nearest power of two, to start

		int min_range = min(st[L - 1][j], st[R - (1 << j)][j]);
		cout << min_range << endl;
	}
}
