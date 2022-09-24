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

ll ans[31]={0,3,9,18,12,18,27,21,27,36,30,36,45,57,45,54,66,54,63,
75,63,72,84,81,81,93,90,90,102,99,99};

void solve(){
	ll n; scanf("%lld", &n);
	if(n<=21){
		printf("%lld\n", ans[n]);
		return;
	}
	ll cnt = n%3+21;
	ll sum =(n/3-7)*10;
	ll carry=0;
	for(ll i=0; i<cnt; i++){
		ll temp =(ll)3*(n-i);
		carry = carry + temp;
		sum += carry%10;
		carry = carry/10;
	}
	printf("%lld\n", sum);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	scanf("%d",&t);
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
