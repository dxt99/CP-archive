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
	ll n; scanf("%lld", &n);
	if (n==2)cout<<2<<endl;
	else{
		ll k = n-1;
		k = k*k + 1;
		k = k%Mod;
		printf("%lld\n",k);
	}
}
 
int main(){
	
	ll t=1;
	scanf("%lld", &t);
 	for(int i=0;i<t;i++){
		solve();
		//cout<<"Case #"<<i+1<<": ";
	}
}
