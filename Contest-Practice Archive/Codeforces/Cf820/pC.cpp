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
	string s; cin>>s;
	ll n=s.size();
	vl arr(n);
	map<int,vl> f;
	for(int i=0; i<26; i++)f[i]={};
	for(int i=0; i<n; i++){
		arr[i]=s[i]-'a';
		f[arr[i]].pb(i+1);
	}
	ll cost = abs(arr[0]-arr[n-1]);
	ll l = arr[0];
	ll r = arr[n-1];
	vl ans = {1};
	while(l!=r){
		for(auto c:f[l]){
			if (c==1||c==n)continue;
			ans.pb(c);
		}
		if(l>r)l--;
		else l++;
	}
	for(auto c:f[r]){
			if (c==1||c==n)continue;
			ans.pb(c);
	}
	ans.pb(n);
	cout<<cost<<" "<<ans.size()<<endl;
	for(auto c: ans){
		cout<<c<<" ";
	}
	cout<<endl;

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
