//Friday 20-August-2021 20:24:58
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string steps = "RLDU";
int n, m;

bool isValid(int x1, int y1, bool visited[][1011], char mat[][1011]) {
	if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && visited[x1][y1] == false && mat[x1][y1] != '#')
		return true;
	return false;
}
int prevsteps[1011][1011];

void bfs(int src1, int src2, int dest1, int dest2, bool visited[][1011], char mat[][1011]) {
	visited[src1][src2] = true;
	queue<pair<int, int>>q;
	q.push({src1, src2});
	memset(prevsteps, -1, sizeof prevsteps);
	while (q.empty() == false) {
		pair<int, int> fron = q.front();
		int x = fron.first, y = fron.second;
		for (int i = 0; i < 4; i++) {
			int xd = dx[i], yd = dy[i];
			if (isValid(x + xd, y + yd, visited, mat)) {
				q.push({x + xd, y + yd});

				visited[x + xd][y + yd] = true;
				prevsteps[x + xd][y + yd] = i;
			}
		}
		q.pop();
	}

	vector<int>st;
	string ts = "";
	if (visited[dest1][dest2] == true) {
		cout << "YES" << endl;

		pair<int, int> end = {dest1, dest2};
		pair<int, int> begin = {src1, src2};
		while (end != begin) {
			int move = prevsteps[end.first][end.second];
			end = {end.first - dx[move], end.second - dy[move]};
			st.push_back(move);
		}
		cout << st.size() << endl;
		reverse(all(st));
		for (auto c : st) {
			cout << steps[c];
		}

	} else {
		cout << "NO" << endl;
	}
}

int main() {
	fastio;
	cin >> n >> m;

	char mat[n + 10][1011];
	int si, sj, di, dj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'A')
				si = i, sj = j;
			if (mat[i][j] == 'B')
				di = i, dj = j;
		}
	}
	bool visited[n + 10][1011] = {false};

	bfs(si, sj, di, dj, visited, mat);

}