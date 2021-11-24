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

void solve(){
	ll n,x,y; cin>>n>>x>>y;
	string s="1";
	while(n>1){
		if(n%2==0)s+="0";
		else s+="1";
		n/=2;
	}
	ll ans=x;
	ll cur=1;
	for(int i=s.size()-2;i>0;i--){
		if(s[i]=='0'){
			ans+=(min(cur*x,y));
			cur*=2;
		}else{
			ans+=(min(cur*x+x,y+x));
			cur=2*cur+1;
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

