#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	ll n; cin>>n;
	map<string,ll> mm;
	for(int i=0; i<n; i++){
		string a; cin>>a;
		int m; cin>>m;
		for(int j=0; j<m; j++){
			string b; cin>>b;
			mm[a]++;
			mm[b]--;
		}
	}
	ll tot = 0;
	ll num = 0;
	for(auto c: mm){
		if(c.sd<=0)continue;
		num = max(num, c.sd);
		tot+=c.sd;
	}
	cout<<tot<<" "<<num<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
