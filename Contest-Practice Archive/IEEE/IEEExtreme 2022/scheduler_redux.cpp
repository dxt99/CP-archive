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

const int N = 1e6, Mod = 1e9 + 7;
const int maxN=1e3+3;

ll cnt[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

void solve(){
	ll n,m; cin>>n>>m;
	ll sum=0;
	ll maxx =0;
	for(int i=0; i<n; i++){
		ll x; cin>>x;
		maxx = max(x,maxx);
		sum += (modpow(2, x));
		sum %= Mod;
		cnt[x]++;
	}
	if(m==1){
		cout<<sum<<endl;
		return;
	}
	ll ans=sum; //ans so far
	ll sumeq=0; //sum of m cnts
	ll big=0; //biggest <m cnts
	for(int i=0; i<=N; i++){
		if(cnt[i]>m || (cnt[i]==m && cnt[i+1]<m && i!=maxx)){
			ll dif = cnt[i]-m;
			if(dif%2)dif++;
			if(dif==0)dif+=2;
			cnt[i]-=dif;
			cnt[i+1]+=(dif/2);
		}
		if(cnt[i]==m){
			sumeq += (modpow(2,i));
			sumeq %= Mod;
			ans = (sumeq + big) % Mod;
			continue;
		}else if(cnt[i]>0){
			big = modpow(2,i);
			ans = big;
		}
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
