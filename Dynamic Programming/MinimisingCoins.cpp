#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi 1<<32
#define mini -1<<32

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using namespace std;


int main(){
	int n,target;

	cin>>n>>target;
	vector<int> c(n);
	for(auto&x : c)cin>>x;
	vector<int> dp(target+1,1e9);
	dp[0] = 0;
	for(int i=1;i<=target;i++){
		for(int j=0;j<n;j++){
			if(i-c[j] >=0){
				dp[i] = min(dp[i],dp[i-c[j]]+1);
			}
		}
	}
	cout<<(dp[target] == 1e9?-1:dp[target])<<endl;


}