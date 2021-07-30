#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int check(int i, int j, string &s, string &t) {
	if (s[i] == t[j])
		return 0;

	return 1;
}

int dist[5001][5001];
int solve(int i, int j, string &s, string &t) {
	//add remove or check operation based solution

	if (i == s.length() || j == t.length())
		return max(t.length() - j, s.length() - i);

	if (dist[i][j] != -1)
		return dist[i][j];
	int op1 = 1 + solve(i + 1, j, s, t);
	int op2 = 1 + solve(i, j + 1, s, t);
	int op3 = check(i, j, s, t) + solve(i + 1, j + 1, s, t);

	return dist[i][j] = min(min(op1, op2), op3);
}

int main() {
	fast;
	memset(dist, -1, sizeof dist);
	string s, t;

	cin >> s >> t;
	cout << solve(0, 0, s, t) << endl;
	return 0;
}