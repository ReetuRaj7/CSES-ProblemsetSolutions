//Friday 17-June-2022 00:45:50
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

int answer = 0;
bool checkQueen(int row, int col, vector<string>board) {
	if (board[row][col] == '*')return false;
	for (int i = 0; i < 8; i++) {
		if (board[i][col] == '!' || board[row][i] == '!')
			return false;
	}
	int tu = row, tv = col;
	while (tu >= 0 && tv >= 0) {
		if (board[tu][tv] == '!')
			return false;
		tu--, tv--;
	}
	tu = row, tv = col;
	while (tu >= 0 && tv < 8) {
		if (board[tu][tv] == '!')
			return false;
		tu--, tv++;
	}
	return true;
}

void queenPlacer(int queenNumber, vector<string>board) {
	if (queenNumber == 8) {
		answer ++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (checkQueen(queenNumber, i, board)) {
			board[queenNumber][i] = '!';
			queenPlacer(queenNumber + 1, board);
			board[queenNumber][i] = '.';
		}
	}
}
int main() {
	fastio;
	vector<string>board;
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	//Recursive solution

	queenPlacer(0, board);
	cout << answer << endl;
}