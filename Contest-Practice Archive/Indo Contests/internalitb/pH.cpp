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
	ll n = s.size();
	ll cnt=0;
	for(int i=0; i<n; i++)if(s[i]=='x')cnt++;
	if(cnt<2){
		cout<<0<<endl;
		return;
	}
	ll mid = (cnt+1)/2;
	ll cur = 0;
	for(int i=0; i<n; i++){
		if(s[i]=='x')cur++;
		if(mid==cur){
			cur = i;
			break;
		}
	}
	ll start = cur - mid + 1;
	//cout<<start<<endl;
	vl arr;
	ll ans = 0;
	for(int i=0; i<n; i++)if(s[i]=='x')arr.pb(i);
	for(auto c:arr){
		ans += abs(c-start);
		start++;
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
