#include<bits/stdc++.h>
#define pb push_back
#define mprr make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll n,k;
set<string> s;
map<string,int> mp;
vl arr;

void fs(ll cur,string t){
	if(cur>=n)return;
	fs(cur+1,t);
	t+=to_string(arr[cur]);
	s.insert(t);
	fs(cur+k+1,t);
}

void solve(){
	s.clear();
	mp.clear();
	arr.clear();
	cin>>n>>k;
	ll idx=1;
	for(int i=0;i<n;i++){
		string s; cin>>s;
		if(mp[s]==0)mp[s]=idx++;
		arr.pb(mp[s]);
	}
	fs(0,"");
	cout<<s.size()<<endl;
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

