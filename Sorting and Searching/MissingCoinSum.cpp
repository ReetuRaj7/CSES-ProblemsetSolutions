#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define maxi INT_MAX
#define mini INT_MIN

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main(){
	fast;
	int n;
	cin>>n;
	vector<lli>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(), a.end());

	lli res = 1; // Initialise the value of the lowest possible count

	for(int i=0;i<n;i++){
		if(a[i] > res) //This means there exists a gap between the 
			break;		//result and upcoming value and that gap will
						//all the values that can't be created
		else
			res += a[i];//add the value to the result
	}

	cout << res << '\n';
	return 0;
}