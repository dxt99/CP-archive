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
	ll n,k; cin>>n>>k;
	vl a(k);
	ll sum =0;
	for(ll& x:a)x=0;
	for(int i=0; i<n; i++){
		ll x; cin>>x;
		sum+=x;
		a[x%k]++;
	}
	ll wst = 0;
	if(k%2==0)a[k/2]=a[k/2]%2;
	for(int i=1; i<k ;i++){
		for(int j=k-i; j<k; j++){
			ll mini = min(a[i],a[j]);
			if(i==j)mini/=2;
			a[i]-=mini;
			a[j]-=mini;
			wst += (i+j-k)*mini;
			//cout<<i<<"-"<<j<<"-"<<wst<<endl;
		}
	}
	for(int i=1; i<k; i++){
		wst += a[i]*i;
	}
	cout<<(sum-wst)/k<<endl;
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
