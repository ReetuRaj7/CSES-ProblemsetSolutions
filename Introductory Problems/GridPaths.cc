//Wednesday 22-June-2022 01:12:07
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

//rercursion with optimization and pruning.

//declarations
int dx[] = { -1, 1, 0, 0};
int dy[] = { 0, 0, 1, -1};
bool used[9][9];
string s; int p[49];


int genPaths(int pathIdx, int row, int col) {
	//check if hitting a wall
	if ((used[row][col - 1] && used[row][col + 1] && !used[row - 1][col] && !used[row + 1][col])
	        || (used[row + 1][col] && used[row - 1][col] && !used[row][col + 1] && !used[row][col - 1])) {
		return 0;
	}
	if (row == 7 && col == 1) {
		if (pathIdx == 48)return 1;
		return 0;
	}
	if (pathIdx == 48)return 0;

	used[row][col] = true;
	int ans = 0;
	if (p[pathIdx] < 4) { //already determined path
		int nxr = dx[p[pathIdx]] + row;
		int nxc = dy[p[pathIdx]] + col;

		if (!used[nxr][nxc])ans += genPaths(pathIdx + 1, nxr, nxc);
	} else {
		for (int i = 0; i < 4; i++) {
			int nxr = dx[i] + row;
			int nxc = dy[i] + col;

			if (!used[nxr][nxc])
				ans += genPaths(pathIdx + 1, nxr, nxc);
		}
	}
	used[row][col] = false;
	return ans;

}
int main() {
	fastio;
	cin >> s;
	//convert path to ints
	for (int i = 0; i < 48; i++) {
		if (s[i] == 'U')p[i] = 0;
		else if (s[i] == 'D')p[i] = 1;
		else if (s[i] == 'R')p[i] = 2;
		else if (s[i] == 'L')p[i] = 3;
		else p[i] = 4;
	}
	memset(used, false, sizeof used);
	//set the borders of the grid
	for (int i = 0; i < 9; i++) {
		used[i][0] = true;
		used[0][i] = true;
		used[8][i] = true;
		used[i][8] = true;
	}
	int pathIdx = 0;
	int nums = genPaths(pathIdx, 1, 1);
	cout << nums << endl;
}