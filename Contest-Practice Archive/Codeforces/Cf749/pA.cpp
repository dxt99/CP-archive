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

bool prime(ll k){
	for(int i=2;i*i<=k;i++){
		if(k%i==0)return 0;
	}
	return 1;
}

void solve(){
	ll n; cin>>n;
	ll s=0; 
	ll g=0;
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		s+=x;
		if(x&1)g=(i);
	}
	if(prime(s)){
		cout<<n-1<<endl;
		for(int i=0;i<n;i++){
			if(i!=g)cout<<i+1<<" ";
		}
		cout<<endl;
	}else{
		cout<<n<<endl;
		for(int i=0;i<n;i++)cout<<i+1<<" ";
		cout<<endl;
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

