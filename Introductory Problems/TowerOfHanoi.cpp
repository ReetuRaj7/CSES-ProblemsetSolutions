#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

void tower(int n, int from, int to, int aux, int&moves, vector<pair<int, int>>&ans) {
	if (n == 1) {
		moves++;
		ans.push_back({from, to});
		return;
	}
	tower(n - 1, from, aux, to, moves, ans);
	moves++;
	ans.push_back({from, to});
	tower(n - 1, aux, to, from, moves, ans);
}

int main() {
	vector<pair<int, int>> ans;
	fast;
	int moves = 0;
	int n;
	cin >> n;
	tower(n, 1, 3, 2, moves, ans);
	cout << moves << endl;

	for (int i = 0; i < moves; i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

}