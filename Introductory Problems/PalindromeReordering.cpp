#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main() {
	fast;
	string s;
	cin >> s;
	int ar[27] = {0};

	for (int i = 0; i < s.size(); i++) {
		ar[s[i] - 'A']++;
	}
	int odd = 0, eve = 0;
	for (int i = 0; i < 26; i++) {
		if (ar[i] % 2 == 1)
			odd++;
		else if (ar[i] > 0 && ar[i] % 2 == 0)
			eve++;
	}
	if (odd > 1) {
		cout << "NO SOLUTION \n";
	} else {
		string fin = "";
		for (int i = 0; i < 26; i++) {
			if (ar[i] > 0 && ar[i] % 2 == 0) {
				//ar[i] /= 2;
				int k = ar[i] / 2;
				while (k > 0) {
					char c = 'A' + i;
					fin += c;
					k--;
				}
			}
		}
		string fin2 = fin;
		reverse(fin2.begin(), fin2.end());
		int j;
		for (j = 0; j < 26; j++) {
			if (ar[j] % 2 == 1)
				break;
		}
		while (ar[j] > 0) {
			char c = j + 'A';
			fin += c;
			ar[j]--;
		}
		fin += fin2;
		cout << fin << endl;
	}
}