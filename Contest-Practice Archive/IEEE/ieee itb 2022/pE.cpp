#include<bits/stdc++.h>
#define pb push_back
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

map<int, int> mp;

void solve(){
	ll n; cin>>n;
	vl arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	for(auto c: arr)mp[c]++;
	vl pre(n+1); pre[0]=0;
	for(int i=1; i<=n; i++)pre[i]=pre[i-1]+arr[i-1];
	vl suf(n+1); suf[0]=0;
	for(int i=1; i<=n; i++)suf[i]=suf[i-1]+arr[n-i];
	ll ans = n-1;
	if(mp[arr[0]]==n){
		cout<<0<<endl;
		return;
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j+i<=n; j++){
			if(i==0 || j==0 || pre[i]==suf[j]){
				//cout<<i<<" "<<j<<" "<<pre[i]<<" "<<mp[pre[i]]<<endl;
				ll cnt = i+j;
				ll num = pre[i];
				if (i==0)num=suf[j];
				if(i>0)cnt--;
				if(j>0)cnt--;
				if (mp[num]==n-i-j)ans=min(ans, cnt);
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
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
