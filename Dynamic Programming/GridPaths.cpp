#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

const int MOD = 1000000007;
using namespace std;


int main(){
	fast;
	int n;
	cin>>n;
	auto ar = new char[n+1][1005];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> ar[i][j];
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout << ar[i][j];
	// 	}
	// 	cout<<endl;
	// }
	auto prepaths = new int[n+1][1005];
	//memset(prepaths,0,sizeof(prepaths));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			prepaths[i][j] = 0;
		}
	}
	prepaths[0][0] = 1;
	if(ar[0][0] == '*'){
		cout << 0 << endl;
		exit(0);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ar[i][j] != '*'){
				if(i > 0){
					prepaths[i][j] += (prepaths[i-1][j] % MOD);
				}
				if(j > 0){
					prepaths[i][j] += (prepaths[i][j-1] % MOD);
				}
			}
		}
	}
	cout << prepaths[n-1][n-1] % MOD << "\n";
	return 0; 
}