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
	ll a,b,c; cin>>a>>b>>c;
	ll sum=a+b*2+c*3;
	sum=sum&1;
	cout<<sum<<endl;
	/*
	ll ans=0;
	if(c&1)ans+=3;
	if(b&1)ans-=2;
	if(a&1&&ans>0)ans-=1;
	else if(a&1)ans+=1;
	cout<<abs(ans)<<endl;
	*/
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

