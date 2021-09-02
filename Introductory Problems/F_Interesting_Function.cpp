/*~~~~~~~~ ReetuRajDubey ~~~~~~~~:-)
    @ReetuRaj77
    Thursday,02 September 2021
    19:40:12
*/
  
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
//using namespace __gnu_pbds;
using namespace chrono;
  
#define endl "\n"
#define space " "
#define pb push_back
#define t_case  lli test; cin >> test;while (test--)
  
#define mod 1000000007
#define ff first
#define ss second
#define INF 2000000000
#define MINF -2000000000
  
#define fl(a, b, r) for (lli a = b; a < r; a++)
#define fr(a, b) for (lli a = b; a >= 0; a--)
#define rfor(it,x) for(auto& it: x)
ostream_iterator<long long int> out(cout," ");
#define print(x) copy(all(x),out);
#define itover(it,x) for(auto (it)=(x).begin();(it)!=(x).end();(it)++)
  
#define fastio ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
  
#define vec vector
#define yes cout << "YES\n"
#define no cout << "NO\n"
//#define ordered_set tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//.*find_by_order(),.order_of_key()
typedef long int li;
typedef long double ld;
typedef long long int lli;
typedef unsigned long long int ulli;


/*~~~~END Of TEMPLATE~~~~*/


void solve(){
    lli a,b;
    cin>>a>>b;
    lli ans = b - a;
    /*Number of times we have transition from 9 to 10 or 
    alikes*/
    lli i = 10;
    while(i<(lli)1e10){
        ans += b / i - a / i;
        i *= 10;
    }
    cout<<ans<<endl;

}
  
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    fastio;
    t_case
        solve();
}