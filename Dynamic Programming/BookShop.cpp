#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;

int maximi_pages(int *price, int *pages, int max_pages, int n) {
	int **max_pages_at = new int*[n + 1];

	for (int i = 0; i <= n; i++) {
		max_pages_at[i] = new int[max_pages + 1];
	}
	for (int i = 0; i <= max(n, max_pages); i++) {
		if (i <= n)
			max_pages_at[i][0] = 0;
		if (i <= max_pages)
			max_pages_at[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= max_pages; j++) {
			max_pages_at[i][j] = max_pages_at[i - 1][j];

			if (price[i - 1] <= j) {
				max_pages_at[i][j] = max(max_pages_at[i][j], pages[i - 1] + max_pages_at[i - 1][j - price[i - 1]]);
			}
		}
	}
	return max_pages_at[n][max_pages];
}

int main() {
	fast;
	int n, max_pages;
	cin >> n >> max_pages;

	int *price = new int[n + 1];
	int *pages = new int[n + 1];

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pages[i];
	}
	// for(int i=0;i<n;i++){
	// 	cout << pages[i];
	// }for(int i=0;i<n;i++){
	// 	cout << price[i];
	// }
	cout << maximi_pages(price, pages, max_pages, n) << "\n";
}