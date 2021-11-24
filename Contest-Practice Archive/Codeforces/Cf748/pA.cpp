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

ll f(ll a,ll sum){
	if(a>=sum)return 0;
	else return sum-a+1;
}

void solve(){
	ll a,b,c; cin>>a>>b>>c;
	ll sum=max(a,max(b,c));
	if(a==b||b==c||a==c){
		sum++;
	}
	cout<<f(a,sum)<<" "<<f(b,sum)<<" "<<f(c,sum)<<endl;
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

