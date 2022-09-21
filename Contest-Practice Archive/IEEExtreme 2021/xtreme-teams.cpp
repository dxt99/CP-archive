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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll C(ll n){
	if(n<3)return 0;
	ll ret=(n)*(n-1)*(n-2);
	ret=ret/6;
	return ret;
}

void solve(){
	ll n,m; cin>>n>>m;
	ll arr[n];
	for(int i=0;i<n;i++){
		string s; cin>>s;
		ll cur=1;
		arr[i]=0;
		for(int j=m-1;j>=0;j--){
			if(s[j]=='y')arr[i]+=cur;
			cur=cur<<1;
		}
	}
	ll tar=(1<<m)-1;
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				ll ret=arr[i]|arr[j];
				ret=ret|arr[k];
				if(ret==tar)ans++;
			}
		}
	}
	cout<<ans<<endl;
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

