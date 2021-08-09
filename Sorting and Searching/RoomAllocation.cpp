#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(),(x).end()

#define maxi INT_MAX
#define mini INT_MIN
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;


int main() {
	fast;
	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first.first>>v[i].first.second;;
		v[i].second = i;
	}
	sort(all(v));
	vector<int>ans(n);
	priority_queue<pair<int,int>>pq;
	int rooms=0,current=0;
	for(int i=0;i<n;i++){
		if(pq.empty()){
			current++;
			pq.push({-v[i].first.second,current}); //cleanest way to implement min heap;use negative
			ans[v[i].second] = current; 
		}else{
			pair<int,int>minima = pq.top();
			if(-minima.first < v[i].first.first){
				pq.pop();
				pq.push({-v[i].first.second,minima.second});
				ans[v[i].second] = minima.second;				
			}else{
				current++;
				pq.push({-v[i].first.second,current});
				ans[v[i].second] = current;
			}
		}
		rooms = max(rooms,(int)pq.size());
	}
	
	cout << rooms << endl;
	for (auto I : ans)cout << I << " ";
}