#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

bool value[110][100010];

void subsetSum(int money[], int amount, int n) {
	for (int i = 0; i < n; i++)
		value[i + 1][money[i]] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= amount; j++) {
			value[i][j] |= value[i - 1][j];
			// cout << "hello" << endl;
			if (j > money[i - 1])
				value[i][j] |= value[i - 1][j - money[i - 1]];
		}
	}

}
int main() {
	fast;
	int n;
	cin >> n;
	int money[n + 1];
	for (int i = 0; i < n; i++)
		cin >> money[i];
	int amount = accumulate(money, money + n, 0);
	memset(value, false, sizeof value);
	// cout << amount << "\n";
	subsetSum(money, amount, n);
	vector<int>ans;
	int total = 0;
	for (int i = 1; i <= amount; i++)
		if (value[n][i] == true) {
			total++;
			ans.push_back(i);
		}

	cout << total << endl;
	for (auto I : ans)
		cout << I << " ";
	return 0;
}