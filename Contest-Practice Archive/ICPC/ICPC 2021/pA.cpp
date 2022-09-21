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

int arr[N];
ll tot[maxN];

ll cnt(ll x){
	ll ret=0;
	ll cnt=1;
	while(x>1){
		if(x&1)ret+=(1<<cnt);
		x>>=1;
		cnt++;
	}
	return ret;
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	sort(arr,arr+m);
	ll ans=0;
	ll cur=3;
	for(int i=0;i<m;i++){
		if(arr[i]>n)break;
		while(cur<arr[i]){
			ans+=cnt(cur);
			cur++;
		}
		cur=arr[i]+1;
	}
	while(cur<=n){
		ans+=cnt(cur);
		cur++;
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);

	//for(int i=1;i<=20;i++)cout<<cnt(i)<<endl;
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

