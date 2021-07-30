#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int cont[110][1000010];

int main() {
	fast;
	int n, w;
	cin >> n >> w;

	vector<int>x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];


	//vector<vector<int>> cont(n+1,vector<int>(w+1,0));

	cont[n][0] = 1; // Initialising the first state of the cont
	for (int i = 0; i <= w; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (x[j] <= i)
				cont[j][i] = (cont[j][i - x[j]] + cont[j + 1][i]) % mod;
			else
				cont[j][i] = cont[j + 1][i];
		}
	}

	cout << cont[0][w] << endl;

	return 0;

}