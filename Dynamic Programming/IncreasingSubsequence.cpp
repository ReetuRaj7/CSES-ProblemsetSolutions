#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int longestIncSub(int *input, int n) {
	const int INF = 1e9;
	vector <int> sortedOnes(n + 1, INF);
	vector <int> p(n, -1);

	sortedOnes[0] = -INF;

	for (int i = 0; i < n; i++) {
		/*We need to find the first element which is greater than the given element
		and also it's previous one should be less than it so that it can occupy
		the place in the sortedOnes array. By this we build a list of element
		in the sorted order and then just is the implementation to find the position
		of the last added element*/
		int j  = upper_bound(sortedOnes.begin(), sortedOnes.end(), input[i]) - sortedOnes.begin();
		if (sortedOnes[j - 1] < input[i] && input[i] < sortedOnes[j]) {
			sortedOnes[j] = input[i];
			p[j] = i;
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (sortedOnes[i] < INF) {
			ans = i;
		}
	}
	for (int i = 1; i <= ans; i++) {
		cout << input[p[i]] << " ";
	}
	cout << endl;
	return ans;
}
int main() {
	fast;
	int n;
	cin >> n;
	int *input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int ans = longestIncSub(input, n);
	delete [] input;
	cout << ans << endl;

	return 0;
}