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
	vl arr(s.size()+3);
	arr[0]=0;
	for(int i=0; i<s.size(); i++){
		arr[i+1]=s[i]-'0';
		arr[i+1]+=arr[i];
	}
	ll n = s.size();
	ll w; cin>>w;
	map<int, vl> f;
	for(int i=0; i<9; i++)f[i]={};
	for(int i=0; i+w<=n; i++){
		ll r = arr[i+w]-arr[i];
		r%=9;
		f[r].pb(i+1);
	}
	// for mult = 0-8, mod = 0-8
	pl ans[9][9];
	for(int k=0; k<9; k++){
		for(int m=0; m<9; m++){
			ans[k][m]=mp(-1,-1);
			for(int i=0; i+w<=n; i++){
				ll rem = arr[i+w]-arr[i];
				rem%=9;
				rem*=k;
				rem%=9;
				rem = m-rem;
				if(rem<0)rem+=9;
				ll temp = i+1;
				if(f[rem].size()>0)temp=f[rem][0];
				if(temp==i+1 && f[rem].size()>1)temp=f[rem][1];
				if(i+1!=temp){
					ans[k][m]=mp(i+1,temp);
					break;
				}
			}
		}
	}
	// queries
	ll m; cin>>m;
	while(m--){
		ll l,r,k; cin>>l>>r>>k;
		ll mul = arr[r]-arr[l-1];
		mul = mul%9;
		//cout<<"ans: ";
		cout<<ans[mul][k].fs<<" "<<ans[mul][k].sd<<endl;
	}
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
